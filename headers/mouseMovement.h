#ifndef PROVA2_MOUSEMOVEMENT_H
#define PROVA2_MOUSEMOVEMENT_H
#include "mouseStack.h"

int isCellWalkable(char cell);

int isEqual(TMazeCell cell1, TMazeCell cell2);

int addPath(char** maze, TMazeCell *currentCell, TMazeStack *mazeStack, TCoordenadas limitCoord);

int moveMouse(char** maze, TMazeCell *currentCell, TMazeCell exitCell, TMazeStack *mazeStack, TCoordenadas limitCoord);


#endif //PROVA2_MOUSEMOVEMENT_H
