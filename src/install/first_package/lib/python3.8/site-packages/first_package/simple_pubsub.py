import rclpy
from rclpy.node import Node
from std_msgs.msg import String 
from sensor_msgs.msg import FluidPressure

#we try to create a mix of pub and sub

class MinimalPubSub(Node):
    def listener_callback(self, msg):
        # Log the received message to the console
        self.get_logger().info(f'Received: "{msg}"')
    def __init__(self):
        # Initialize the node with the custom name 'node_NICKNAME'
        super().__init__('node_GOAT')  # <-- Replace 'NICKNAME' with your actual group number
        

        # Step 2: Create a publisher for your topic
        # Replace 'topic_ID' with a unique topic name (e.g., 'topic_É' for Group 1)
        self.publisher_ = self.create_publisher(FluidPressure, 'topic_3', 10)  # <-- Replace 'NICKNAME'
        
        # Step 3: Set a timer to publish messages at a chosen frequency
        # Modify 'timer_period' to control how often messages are published (e.g., 2.0 for every 2 seconds)
        timer_period = 2  # <-- You can change this to another value like 1.5 or 3.0
        self.timer = self.create_timer(timer_period, self.timer_callback)
        
        # Step 4: Initialize a counter to keep track of message numbers
        self.i = 0  # Starts counting from 0

        self.subscription = self.create_subscription(
            FluidPressure,             # Message type used by the publisher
            'topic_2',  # <-- Replace 'NICKNAME' with the specific topic name for your group&
            self.listener_callback,  
            10)  # Queue size for incoming messages
        self.subscription  # Prevent unused variable warning

    # Step 5: Define the callback function that will be called by the timer
    def timer_callback(self):
        # Create a new String message
        msg = FluidPressure()
        
        # Customize the message data with a unique message
        # Modify the message content to include your group number and a custom message
        msg.variance = 9.0 
        msg.fluid_pressure = 2.1
        
        # Publish the message
        self.publisher_.publish(msg)
        
        # Log the published message to the console
        self.get_logger().info(f'Publishing: "{msg}"')
        
        # Increment the message counter
        self.i += 1
# Step 6: Define the main function to run the node
def main(args=None):
    # Initialize the ROS2 Python client library
    rclpy.init(args=args)
    
    # Create an instance of the MinimalPubSub node
    minimal_pubsub = MinimalPubSub()

    try:
        # Run the node until interrupted
        rclpy.spin(minimal_pubsub)
    except KeyboardInterrupt:
        # Gracefully handle shutdown when Ctrl+C is pressed
        pass
    finally:
        # Destroy the node and shutdown the ROS2 Python client library
        minimal_pubsub.destroy_node()
        rclpy.shutdown()

# Entry point of the script
if __name__ == '__main__':
    main()
