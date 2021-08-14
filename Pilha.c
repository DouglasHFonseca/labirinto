#include "mazeStack.h"

//==================================Basico======================================

//Aqui jazem as funções básicas PFVazia, pop, push, isVazia.
//E uma de transferencia de n termos.

void FPVazia(TMazeStack *pilha) {

    pilha->topo = (TMazeCell*) malloc(sizeof (TMazeCell));
    pilha->fundo =  pilha->topo;
    pilha->topo->prox = NULL;
    pilha->profundidade = 0 ;

}

void Empilha(TCoordenadas coordenadas, TMazeStack *pilha) {
    TMazeCell *aux;
    aux = (TMazeCell*) malloc(sizeof (TMazeCell));
    pilha->topo->coordenadas = coordenadas;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->profundidade++;
}

void Desempilha(TCoordenadas *coordenadas, TMazeStack *pilha) {
    TMazeCell* q;
    if(isPilhaVazia(*pilha)){
        printf("Erro: Lista Vazia!\n");
        return;
    }
    q = pilha->topo;
    pilha->topo = q->prox;
    *coordenadas = q->prox->coordenadas;
    free(q);
    pilha->profundidade--;
}

int isPilhaVazia(TMazeStack pilha) {
    return (pilha.topo == pilha.fundo);
}

void TransferePPRange(TMazeStack *pilha1, TMazeStack *pilha2, int n) {
    if(isPilhaVazia(*pilha1)){
        printf("Pilha Origem Vazia");
    }
    if(n > pilha1->profundidade || n <= 0){
        printf("Alcance Invalido!");
    }
    TCoordenadas aux;
    for(int i = 0; i < n; i++){
        Desempilha(&aux, pilha1);
        Empilha(aux, pilha2);
    }
}
