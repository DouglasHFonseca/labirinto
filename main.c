#include <stdio.h>
#include "mouseStack.h"
#include "mouseMovement.h"
#include "userStack.h"
#include "interfaceGrafica.h"
int main() {



    TUserStack userStack;
    FPVazia2(&userStack);

    TMazeStack  mazeStack;
    FPVazia(&mazeStack);

    TMazeCell currentCell, exitCell;

    printf("\t#####Bem vindo ao Labirinto!#####\n");
    printf("Ao digitar a primeira linha, o numero de caracteres, sera o numero de colunas\n");
    printf("Exemplo, 0000 tera 4 colunas.\n");
    printf("Recomenda-se rodar no terminal.\n\n");

    do{
        printf("\nDigite a 1 linha: ");
        leLinha(&userStack);
        if(!(isPilhaVazia2(userStack))){
            break;
        }
    } while (1);

    int rows, columns;
    columns = userStack.profundidade;
    rows = columns;
    char** maze = malloc((sizeof (char*)) * (rows+2));


    for (int i=0; i<rows+2; i++)
        maze[i] = (char *)malloc((columns+2) * sizeof(char));

    for(int i = 0; i < rows+2; i++){
        for(int j = 0; j < columns+2; j++){
            maze[i][j] = '1';
        }
    }

    int m = leLinhas(&userStack, maze, rows, &currentCell, &exitCell) ;
    if(m == -1){
        printf("\nProgram will terminate.");
        printf("\nPress enter to continue...");
        for (int i = 0; i <  rows; i++)
            free(maze[i]);

        free(maze);
        getchar();
        return 0;
    }
    int height = rows+1;
    int lenght = columns+1;

    TCoordenadas limitCoord;

    limitCoord.y = rows+3;
    limitCoord.x = columns+3;


    int isTherePath;
    do{
        isTherePath = moveMouse(maze, &currentCell, exitCell, &mazeStack, limitCoord);
        printf("\n");
        system("cls");
        showDisplay(height,lenght, maze);
        sleep(1);
    } while (isTherePath == 0);


    if(isTherePath == 1){
        mgotoxy(0, height+2);
        printf("\nPath found!! The mouse has escaped!!\n");
        printf("Press enter to continue");
        getchar();
    }
    if(isTherePath == -1){
        mgotoxy(0, height+2);
        printf("\n\nThere is no path... Beyond the scope of light, beneath the reach of dark."
               "\nWhat could possibly await us, yet we seek it, insatiably... For that's our curse.\n\n");
        printf("Press enter to continue");
        getchar();
    }


    for (int i = 0; i < columns+2; i++) {
        for(int j = 0; j < rows+2; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }



    for (int i = 0; i <  rows; i++)
        free(maze[i]);

    free(maze);

    return 0;
}
