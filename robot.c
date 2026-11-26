#include "graphics.h"
#include "robot.h"
#include "maze.h"

void peekSquareAhead(Robot *robot, int *x, int *y ){
    *x= robot -> xCoord;
    *y = robot->yCoord;
    switch (robot-> direction)
    {
    case NORTH:
        (*y)--;
        break;
    case EAST:
        (*x)++;
        break;
    case SOUTH:
        (*y)++;
        break;
    case WEST:
        (*x)--;
        break;
    }
}

void forward(Robot *robot){
    if (canMoveForward(robot)){
        int newX =0, newY=0;
        peekSquareAhead(robot, &newX, &newY);
        robot->xCoord= newX;
        robot->yCoord= newY;
    }
}

void left(Robot *robot){
    robot-> direction = (robot-> direction +3)%4;
}

void right(Robot *robot){
    robot-> direction = (robot-> direction +1)%4;
}

int atMarker(Robot *robot){
    if (maze[robot->yCoord][robot->xCoord]==EXIT){
        return 1;
    }
    return 0;
}
int canMoveForward(Robot *robot){
    int newXCoord= 0, newYCoord= 0;
    peekSquareAhead(robot, &newXCoord, &newYCoord);
    if (newXCoord < 0 || newXCoord >= WIDTH || newYCoord<0 || newYCoord>= HEIGHT || maze[newYCoord][newXCoord]==WALL){
        return 0;
    }
    return 1;
}

Robot createRobot(int col, int row, Direction direction){
    Robot robot= {col, row, direction};
    return robot;
}

void drawRobot(Robot *robot, int squareSize){
    int centreX= robot->xCoord*squareSize +squareSize/2;
    int centreY= robot->yCoord*squareSize +squareSize/2;
    int triangleSize= squareSize/2;

    int directionX=0, directionY=0;
    switch (robot->direction)
    {
    case NORTH:
        directionX= 0;
        directionY= -1;
        break;
    case EAST:
        directionX= 1;
        directionY= 0;
        break;
    case SOUTH:
        directionX= 0;
        directionY= 1;
        break;
    case WEST:
        directionX= -1;
        directionY= 0;
        break;
    }

    int triangleTipX= centreX+ triangleSize*directionX;
    int triangleTipY= centreY+ triangleSize*directionY;

    int triangleCornerAX= centreX - triangleSize*directionX+ triangleSize*directionY;
    int triangleCornerAY= centreY - triangleSize*directionY+ triangleSize*directionX;

    int triangleCornerBX= centreX - triangleSize*directionX- triangleSize*directionY;
    int triangleCornerBY= centreY - triangleSize*directionY- triangleSize*directionX;

    int triangleXCoords[3]= {triangleTipX, triangleCornerAX, triangleCornerBX};
    int triangleYCoords[3]= {triangleTipY, triangleCornerAY, triangleCornerBY};

    setColour(blue);
    fillPolygon(3, triangleXCoords, triangleYCoords);
}

