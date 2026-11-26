#ifndef ROBOT_H
#define ROBOT_H

typedef enum {
    NORTH, 
    EAST, 
    SOUTH,
    WEST
} Direction;

typedef struct{
    int xCoord, yCoord;
    Direction direction;
} Robot;

void forward(Robot *robot);
void left(Robot *robot);
void right(Robot *robot);
int canMoveForward(Robot *robot);
int atMarker(Robot *robot);

Robot createRobot(int col, int row, Direction direction);
void drawRobot(Robot *robot, int squareSize);
#endif