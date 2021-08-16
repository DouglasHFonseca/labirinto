#ifndef PROVA2_USERSTACK_H
#define PROVA2_USERSTACK_H
#include "stdlib.h"
#include "stdio.h"
#include "mouseStack.h"
typedef struct symbol{

    char c;

} TSymbol;

typedef struct usercell
{

    TSymbol symbol;
    struct usercell* prox;

} TUserCell;

typedef struct userStack{
    TUserCell * topo;
    TUserCell * fundo;
    int profundidade;

} TUserStack;

typedef struct stackstack{

    TUserStack * topo;
    TUserStack * fundo;
    int profundidade;

}TStackStack;

void FPVazia2(TUserStack *pilha);

void Empilha2(TSymbol symbol, TUserStack *pilha);

void Desempilha2( TSymbol *symbol, TUserStack *pilha);

int isPilhaVazia2(TUserStack pilha);

void TransferePPRange2(TUserStack *pilha1, TUserStack *pilha2, int n);

int leLinha(TUserStack *stack);

void InvertePilha3(TUserStack *pilha);

void leLinhas(TUserStack *userStack, char** maze, int rows, TMazeCell *currentCell, TMazeCell *exitCell);

#endif //PROVA2_USERSTACK_H
