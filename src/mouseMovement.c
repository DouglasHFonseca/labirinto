#include "mouseMovement.h"

int isCellWalkable(char cell) {
    return(!(cell == '1' || cell == '.' || cell == 'm'));
}

int isEqual(TMazeCell cell1, TMazeCell cell2) {
    if(cell1.coordenadas.x == cell2.coordenadas.x){
        return(cell1.coordenadas.y == cell2.coordenadas.y);
    }
    return 0;
}

int addPath(char** maze, TMazeCell *currentCell, TMazeStack *mazeStack, TCoordenadas limitCoord) {

    //A ordem de insercao eh invertida da ordem de prioridade do rato, pois o padrao eh LIFO

    int x = currentCell->coordenadas.x;
    int y = currentCell->coordenadas.y;
    TCoordenadas aux;

    int size = mazeStack->profundidade;

    //Verifica se esta disponival e adiciona o caminho abaixo
    if(x+1 < limitCoord.x && isCellWalkable(maze[x+1][y])){

        aux.y = currentCell->coordenadas.y;
        aux.x = currentCell->coordenadas.x+1;

        Empilha(aux, mazeStack);
    }

    //Verifica se esta disponival e adiciona o caminho acima
    if(x-1 >= 0 && isCellWalkable(maze[x-1][y])){

        aux.y = currentCell->coordenadas.y;
        aux.x = currentCell->coordenadas.x-1;

        Empilha(aux, mazeStack);
    }

    //Verifica se esta disponival e adiciona o caminho à esquerda
    if(y >= 0 && isCellWalkable(maze[x][y-1])){

        aux.y = currentCell->coordenadas.y-1;
        aux.x = currentCell->coordenadas.x;

        Empilha(aux, mazeStack);
    }

    //Verifica se esta disponival e adiciona o caminho à direita
    if(y+1 < limitCoord.y && isCellWalkable(maze[x][y+1])){

        aux.y = currentCell->coordenadas.y+1;
        aux.x = currentCell->coordenadas.x;

        Empilha(aux, mazeStack);
    }

    //Verifica se nao ha mais caminhos, pois a pilha esta vazia
    if(isPilhaVazia(*mazeStack)){
        printf("\n\nThere is no path... Beyond the scope of light, beneath the reach of dark."
               "\nWhat could possibly await us, yet we seek it, insatiably... For that's our curse.\n\n");
        return -1;
    }

    //Verifica se nenhum caminho esta disponivel, imprime que esta fazendo o backtracking.
    //O backtracking simplesmente joga o rato para a posição de uma prioridade abaixo na ultima tomada de decisção.
    //EX se ele foi para a direita, volte e eh jogado direto para a esqurda, etc...
    //Pode ser deletado, pois nao faz nada exceto imprimir a msg.
    if(size == mazeStack->profundidade){
        printf("Backtracking...\n");
    }

    return 1;
}

int moveMouse(char** maze, TMazeCell *currentCell, TMazeCell exitCell, TMazeStack *mazeStack, TCoordenadas limitCoord) {


    int isPathAvailable;
    TCoordenadas aux;

    //Verifica se existe algum caminho disponivel,
    isPathAvailable = addPath(maze, currentCell, mazeStack, limitCoord);

    //Move o rato para a proxima celula disponivel.
    if(isPathAvailable == 1){
        Desempilha(&aux, mazeStack);
        currentCell->coordenadas = aux;

        if(isEqual(*currentCell, exitCell)){    //Verifica se eh a saida.
            printf("\nPath found!! The mouse has escaped!!\n");
            return 1;
        }

        int x = currentCell->coordenadas.x;
        int y = currentCell->coordenadas.y;
        maze[x][y] = '.';   //Marca o caminho que o mouse ja passou.
        return 0;
    }

    else{   //Se nao existir nenhum caminho retorna -1
        return -1 ;
    }

}