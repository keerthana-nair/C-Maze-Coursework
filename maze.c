#include "graphics.h"
#include "maze.h"
#include <stdio.h>
#include <stdlib.h>

Square maze[HEIGHT][WIDTH];

//Randomised Depth First Search is used to generate the maze
//References: https://en.wikipedia.org/wiki/Maze_generation_algorithm
//https://rosettacode.org/wiki/Maze_generation#C 

void createFreeSpace(int x, int y){
    int xDirections[4]= {0,2,0,-2};
    int yDirections[4]= {-2,0,2,0};
    int order[4]= {0,1,2,3};

    for (int i =3; i>0; i--){
        int j= rand() % (i+1);
        int temp= order[i];
        order[i]= order[j];
        order[j]= temp;
    }

    maze[y][x] = EMPTY;
    for(int i=0; i<4; i++){
        int newX= x+ xDirections[order[i]];
        int newY= y+ yDirections[order[i]];
        if (newX >0 && newX < WIDTH-1 && newY >0 && newY < HEIGHT-1 && maze[newY][newX]== WALL){
            maze[y+ yDirections[order[i]]/2][x+ xDirections[order[i]]/2]= EMPTY;
            createFreeSpace(newX, newY);
        }
    }
}

void generateMaze(){
    for (int y=0; y< HEIGHT; y++){
        for(int x= 0; x< WIDTH; x++){
            maze[y][x]= WALL;
        }
    }
    createFreeSpace(1,1);
    maze[1][0]= START;
    maze[HEIGHT-2][WIDTH-1]= EXIT;
}

void drawMaze(int squareSize){
    setColour(gray);
    for (int i=0; i<= WIDTH; i++){
        drawLine(i*squareSize, 0, i*squareSize, HEIGHT*squareSize);
    } 
    for (int i=0; i<= HEIGHT; i++){
        drawLine(0, i*squareSize, WIDTH*squareSize, i*squareSize);
    }  
    for (int row= 0; row < WIDTH; row++){
        for(int col= 0; col < HEIGHT; col++){
            switch (maze[row][col])
            {
                case WALL:
                    setColour(black);
                    fillRect(col*squareSize, row*squareSize, squareSize, squareSize);
                    break;
                case EXIT:
                    setColour(gray);
                    fillRect(col*squareSize, row*squareSize, squareSize, squareSize);
                    break;
                default:
                    break;
            }
        }
    }
    
}

void findStartCoordinate(int *row, int *col){
    for (int x=0; x< WIDTH; x++){
        for (int y=0; y< HEIGHT; y++){
                if (maze[x][y]== START){
                    *row= x;
                    *col= y;
                    return;
                }
        }
    }
    printf("Start coordinates not found");
    *row= -1;
    *col= -1;
}
