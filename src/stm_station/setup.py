import os
from glob import glob
from setuptools import setup

package_name = 'stm_station'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'),
        glob('launch/*.py'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='athens',
    maintainer_email='athens@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            '4_stm_serial_node_pub = stm_station.4_stm_serial_node_pub:main',
            'stm_serial_node_pub_sub = stm_station.stm_serial_node_pub_sub:main',
            'stm_serial_node_master_slave = stm_station.stm_serial_node_master_slave:main'
        ],
    },
)
