#include "userStack.h"

void FPVazia2(TUserStack *pilha) {

    pilha->topo = (TUserCell *) malloc(sizeof (TUserCell ));
    pilha->fundo =  pilha->topo;
    pilha->topo->prox = NULL;
    pilha->profundidade = 0 ;

}

void Empilha2(TSymbol symbol, TUserStack *pilha) {
    TUserCell *aux;
    aux = (TUserCell *) malloc(sizeof (TUserCell ));
    pilha->topo->symbol = symbol;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->profundidade++;
}

void Desempilha2( TSymbol *symbol, TUserStack *pilha) {
    TUserCell* q;
    if(isPilhaVazia2(*pilha)){
        printf("Erro: Lista Vazia!\n");
        return;
    }
    q = pilha->topo;
    pilha->topo = q->prox;
    *symbol = q->prox->symbol;
    free(q);
    pilha->profundidade--;
}

int isPilhaVazia2(TUserStack pilha) {
    return (pilha.topo == pilha.fundo);
}

void TransferePPRange2(TUserStack *pilha1, TUserStack *pilha2, int n) {
    TSymbol aux;
    for(int i = 0; i < n; i++){
        Desempilha2(&aux, pilha1);
        Empilha2(aux, pilha2);
    }
}

void InvertePilha3(TUserStack *pilha) {

    if(isPilhaVazia2(*pilha)){
        printf("Pilha Vazia");
    }

    TUserStack pilha2;
    FPVazia2(&pilha2);
    TSymbol aux;
    int tamanho = pilha->profundidade;
    for(int i = 1; i <= tamanho; i++) {
        Desempilha2(&aux, pilha);
        TransferePPRange2(pilha, &pilha2, tamanho-i);
        Empilha2(aux, pilha);
        TransferePPRange2(&pilha2, pilha, tamanho-i);
    }
}

int leLinha(TUserStack *stack) { //Le uma linha individualmente, e adiciona cada char em uma pilha.
    int input;
    TSymbol simbolo;
    while(1) {
        input = getc(stdin);
        if(input == EOF || input == '\n' || input == ' '){
            break;
        }
        if(input == 'p'){
            return 1;
        }
        simbolo.c = (char) input;
        Empilha2(simbolo, stack);
    }
    InvertePilha3(stack);
    return 0;
}

//Faz o push e pop dos characteres das linhas lidas e coloca na posicao [i][j], faz isso ate acabar o espaco.
void leLinhas(TUserStack *userStack, char** maze, int rows, TMazeCell *currentCell, TMazeCell *exitCell) {
    int j, isSaida = 0, isMouse = 0;
    TSymbol  symbol;

    for(int i = 1; i <= rows; i++){

        j = 1;
        if(isPilhaVazia2(*userStack)){
            for(int j = 1; j <= rows; j++){
                maze[i][j] = '0';
            }
        }

        while (!isPilhaVazia2(*userStack)) {
            Desempilha2(&symbol, userStack);
            if (symbol.c == '0' || symbol.c == '1') {
                maze[i][j] = symbol.c;
            }
            else if(symbol.c == 'e'){
                if(isSaida == 0){
                    maze[i][j] = symbol.c;
                    exitCell->coordenadas.x = i;
                    exitCell->coordenadas.y = j;
                    isSaida = 1;
                }else{
                    maze[i][j] = '0';
                }
            }
            else if(symbol.c == 'm'){
                if(isMouse == 0){
                    maze[i][j] = symbol.c;
                    currentCell->coordenadas.x = i;
                    currentCell->coordenadas.y = j;
                    isMouse = 1;
                }else{
                    maze[i][j] = '0';
                }
            }
            else{
                maze[i][j] = '0';
            }

            j++;
        }
        if(i < rows) {
            printf("Digite a %d linha: ", i + 1);
            leLinha(userStack);
        }

    }
}