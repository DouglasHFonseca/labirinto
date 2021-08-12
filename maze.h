#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
// Creating a stack

typedef struct maze
{
  int x;
  int y;
} mazeCell;

typedef struct maze
{
  mazeCell *a;
  int top;
} mazeStSack;

#endif // MAZE_H_INCLUDED