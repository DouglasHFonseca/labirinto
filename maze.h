#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
// Creating a stack
#define MAX 10

typedef struct stack
{
  int items[MAX];
  int top;
} st;

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