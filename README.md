# GPS_Tracking_System
The GPS Distance Tracking System is an embedded system developed using the TM4C123G LaunchPad. It allows users to track the distance they travel between two points using GPS coordinates. The system provides visual feedback to the user through built-in LEDs, indicating when they are close to their destination or have reached it.

# Description
The GPS Distance Tracking System is a project developed as part of the CSE 211 course at the Computer and Systems Engineering Department, Faculty of Engineering, during the Fall 2023 semester. The main objective of the project is to create an embedded system that accurately tracks the distance a user travels between two points using GPS coordinates. The system is implemented on the TM4C123G LaunchPad and provides real-time visual feedback to the user through LEDs.

#Features
The GPS subsystem performs the following tasks:

1-Stores the coordinates of the starting point.
2-Green LED turns on when the total distance is greater than 100 meter.

The trajectory of the distance traveled satisfies the following criteria:

1-The total distance between the start and end points should be greater than 100 meters.
2-The path from the start point to the end point should form a non-straight line similar to the provided baseline path.

# Installation
To use the GPS Distance Tracking System, follow these steps:

Clone the repository to your local machine:

https://github.com/Mahmoud-Abdelraouf/GPS-Tracking-System.git
Connect the TM4C123G LaunchPad to a GPS module and configure it to receive GPS coordinates.

Open the project in Code Composer Studio (CMake is also required for building).
