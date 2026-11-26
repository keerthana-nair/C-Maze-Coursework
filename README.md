# C-Maze-Coursework
C coursework project I built to practise C. It generates random mazes using a recursive backtracker and solves them with a robot that follows the right-hand wall.

This program generates a square maze of different sizes using a Randomised Depth First Search (recursive backtracker) algorithm created in the maze.c file. 
In the maze, the black squares represent the walls of the maze and the grey square represents the exit. The entrance is at (0,1) on the outer wall and the exit is at the bottom right on the outer wall. Each run generates a random, different maze.

The maze macros WIDTH and HEIGHT defined in the maze.h file can hold any odd integer value. Both WIDTH and HEIGHT must hold the same value.
The best range of the WIDTH and HEIGHT are between 5 and 55, as (5 squares x 5 squares) is the smallest proper maze that the algorithm generates and when the size of the maze> (55 squares x 55 squares), both the robot and the individual squares of the maze get too small to be seen clearly.
Currently they are set to 25, so the maze is 25x25 squares.

The program also contains a software robot, represented by a blue triangle which initially faces east. The robot uses the right-hand-on-wall rule to solve the maze. 
Essentially this means that the robot will:
1. Turn right and move forward if the square on the right is free
2. Otherwise go straight ahead if the square is free
3. Otherwise turn left and move forward if the square is free
4. Otherwise, if it is a dead end, turn around and go back the way it came

As both the entrance and exit are gaps in the outer wall, the wall to the right of the robot that it follows goes along the entire boundary of the maze and therefore always reaches the exit.
The maze is solved once the robot has reached the exit.

The commands used to compile this code are as follows:
gcc -Wall -Wextra -o main main.c maze.c graphics.c robot.c

If you wanted to change the size of the maze drawn then use the following compile command:
gcc -Wall -Wextra -DWIDTH=35 -DHEIGHT=35 -o main main.c maze.c graphics.c robot.c

This changes the size of the maze to a 35x35 square grid. You may change the numbers following -DWIDTH= and -DHEIGHT= to change the size of the maze. There should be no spaces between -DHEIGHT/-DWIDTH= and the number chosen e.g. -DWIDTH=25 is correct, but -DWIDTH= 25 is incorrect.

To run the code on Windows, the command is as follows:
.\main | java -jar drawapp-5.0.jar

On Mac/Linux:
./main | java -jar drawapp-5.0.jar
