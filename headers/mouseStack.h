#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
// Creating a stack
#include <stdlib.h>
#include <stdio.h>
typedef struct coord{
  
  int x;
  int y;

} TCoordenadas;

typedef struct maze
{

  TCoordenadas coordenadas;
  struct maze* prox;

} TMazeCell;

typedef struct mazestack{
  TMazeCell* topo;
  TMazeCell* fundo;
  int profundidade;

} TMazeStack;



//==================================Basico======================================

void FPVazia(TMazeStack *pilha);

void Empilha(TCoordenadas coordenadas, TMazeStack *pilha);

void Desempilha(TCoordenadas *coordenadas, TMazeStack *pilha);

int isPilhaVazia(TMazeStack pilha);

#endif // MAZE_H_INCLUDED