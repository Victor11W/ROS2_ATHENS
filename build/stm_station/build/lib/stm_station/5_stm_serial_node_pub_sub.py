# Objective:
# The goal is to create a ROS 2 node that reads data from a serial device and publishes it using standard messages like Float32MultiArray.
# Additionally, the node subscribes to Float32MultiArray messages to receive control commands and sends these commands to the serial device.
# The serial reading part is provided.

# 1. Import necessary libraries
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
import serial

# 2. Define the SerialPubSubNode class
class SerialPubSubNode(Node):
    def __init__(self):
        """
        Initialize the SerialPubSubNode with publishers, subscribers, and serial interface.
        """
        super().__init__('stm_serial_node')

        # 3. TODO: Get Serial Configuration Values 
        self.port = '/dev/ttyACM0'  # Serial port name
        self.baudrate = 115200      # Baud rate for serial communication
        self.loop_frequency = 1000  # Frequency to read data from the serial port

        # 4. Set up the serial port for communication
        self.serial_port = serial.Serial(self.port, self.baudrate, timeout=0.01)
        self.get_logger().info(f'Node initialized with serial port {self.port} at {self.baudrate} baud.')

        # 5. TODO: Create a publisher to publish the received data from the serial port
        # using Float32MultiArray messages from the std_msgs package in the topic '/stm_state'
        self.stm_state_topic = '/stm_state'
        self.stm_state_publisher = '/stm_state/publisher2'

        # 6. Create a timer to read data periodically and publish it
        self.timer = self.create_timer(1 / self.loop_frequency, self.timer_read_pub_callback)

        # 7. TODO: Create a subscriber to receive control commands as Float32MultiArray messages
        # on the topic '/stm_control' with a queue size of 10 and a callback function 'stm_control_callback'
        self.stm_control_topic = '/stm_control'
        self.stm_control_subscriber = '/stm_control/publisher'


        self.subscription = self.create_subscription(
            Float32MultiArray,             # Message type used by the publisher
            self.stm_control_topic,  # <-- Replace 'NICKNAME' with the specific topic name for your group
            self.stm_control_callback,  
            10)  # Queue size for incoming messages
        self.subscription  # Prevent unused variable warning



    # 7. Define the callback function for the timer
    def timer_read_pub_callback(self):
        """
        Periodically reads data from the serial port and publishes it as a Float32MultiArray.
        """
        # Check if data is available to read (in_waiting is the number of bytes in the input buffer)
        if self.serial_port.in_waiting > 0:
            try:
                # Read the data from the serial port 
                serial_data_raw = self.serial_port.readline()

                # Decode the data
                serial_data_decoded = serial_data_raw.decode('utf-8')

                # Remove leading and trailing whitespace
                serial_data = serial_data_decoded.strip()

                # Check if data is properly formatted with braces
                # Spected format: 
                # {motor_position, motor_velocity, imu_acceleration_x, imu_acceleration_y, imu_acceleration_z, imu_gyro_x, imu_gyro_y, imu_gyro_z}
                if serial_data.startswith('{') and serial_data.endswith('}'):
                    serial_data = serial_data[1:-1]  # Remove the braces
                else:
                    self.get_logger().warn('Data does not start and end with braces')
                    return
                
                # Split the data by commas
                float_values = serial_data.split(',')
                
                if len(float_values) == 8:
                    # Ensure the correct number of data parts is present (expected 8 fields)
                    # 1. motor_position
                    # 2. motor_velocity
                    # 3. imu_acceleration_x
                    # 4. imu_acceleration_y
                    # 5. imu_acceleration_z
                    # 6. imu_gyro_x
                    # 7. imu_gyro_y
                    # 8. imu_gyro_z

                    # Create a Float32MultiArray message
                    # TODO: Create and populate the Float32MultiArray message
                    float32_multi_array_msg = Float32MultiArray()
                    float32_multi_array_msg.data = [float(i) for i in float_values]

                    # Publish the message
                    # TODO: Publish the float32_multi_array_msg
                    self.publisher_=self.create_publisher(Float32MultiArray,self.stm_state_topic,10)
                    self.publisher_.publish(float32_multi_array_msg) #rajout
                    

                self.get_logger().info(f'Published data: {float_values}')
            except ValueError as e:
                self.get_logger().warn(f'Error parsing serial data: {e}')


    # 8. Define the callback function for the timer
    def stm_control_callback(self, msg):
        """
        Callback function for control commands.
        Sends the control data to the serial device.
        """
        try:
            # TODO: Format the control data as a comma-separated string and send it to the serial device
            # format: {control_type, goal_position, Kp, PWM}
            # control_type: 0 = Stop, 1 = Position Control (Close Loop), 2 = PWM Control (Open Loop)
            control_data = f"{{{msg.data[0]}, {msg.data[1]}, {msg.data[2]}, {msg.data[3]}}}"

            # TODO: Encode the control data as UTF-8 and write it to the serial port 
            self.serial_port.write((control_data+'\n').encode('utf-8'))
            self.get_logger().info(f'Sent control command: {control_data}')
            
        except Exception as e:
            self.get_logger().error(f'Error sending control command: {e}')

    # 9. Define the destroy_node method
    def destroy_node(self):
        """
        Clean up the node by closing the serial port.
        """
        self.serial_port.close()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    
    node = SerialPubSubNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()