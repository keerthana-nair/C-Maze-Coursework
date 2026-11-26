#include "maze.h"
#include "graphics.h"
#include"robot.h"
#include <stdlib.h>
#include <time.h>


//Using the Right Hand on wall rule to solve the maze: https://en.wikipedia.org/wiki/Maze-solving_algorithm
void rightHandOnWall(Robot *robot){
    right(robot);
    for (int turn= 0; turn < 4; turn++){
        if (canMoveForward(robot)){
            forward(robot);
            return;
        }
        left(robot);
    }
}

int main(){
    int squareSize= 500/WIDTH;
    setWindowSize(WIDTH*squareSize, HEIGHT*squareSize);
    background();

    //https://stackoverflow.com/questions/14849866/c-rand-is-not-really-random
    //The random maze generation kept generating the same maze 
    //due to the fact that rand() is not completely random
    srand(time(NULL)); 

    generateMaze();
    drawMaze(squareSize);
    foreground();
    int row=0, col=0;
    findStartCoordinate(&row, &col);
    Robot robot= createRobot(col, row, EAST);
    drawRobot(&robot, squareSize);
    while (!atMarker(&robot))
    {
        clear();
        drawRobot(&robot, squareSize);
        sleep(200);
        rightHandOnWall(&robot);
    }
    clear();
    drawRobot(&robot, squareSize);
    return 0;
}