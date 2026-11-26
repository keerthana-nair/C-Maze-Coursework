#ifndef MAZE_H
#define MAZE_H

#ifndef WIDTH
#define WIDTH 25
#endif

#ifndef HEIGHT
#define HEIGHT 25
#endif

#if (WIDTH%2==0) || (HEIGHT%2==0)
#error "WIDTH and HEIGHT must both be odd"
#endif

#if  (WIDTH != HEIGHT)
#error "WIDTH and HEIGHT must be equal"
#endif

typedef enum{
    EMPTY,
    WALL,
    EXIT,
    START
} Square;

void createFreeSpace(int x, int y);
void generateMaze();
void drawMaze(int squareSize);
void findStartCoordinate(int *row, int *col);

extern Square maze[HEIGHT][WIDTH]; //https://www.geeksforgeeks.org/c/understanding-extern-keyword-in-c/

#endif