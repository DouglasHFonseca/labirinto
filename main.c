#include <stdio.h>
#include "mouseStack.h"
#include "mouseMovement.h"
#include "userStack.h"
int main() {

    TUserStack userStack;
    FPVazia2(&userStack);

    TMazeStack  mazeStack;
    FPVazia(&mazeStack);

    TMazeCell currentCell, exitCell;



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

    leLinhas(&userStack, maze, rows, &currentCell, &exitCell) ;


    TCoordenadas limitCoord;

    limitCoord.y = rows+3;
    limitCoord.x = columns+3;

//    maze[0][0] = '1'; maze[0][1] = '1'; maze[0][2] = '1'; maze[0][3] = '1'; maze[0][4] = '1'; maze[0][5] = '1';
//    maze[1][0] = '1'; maze[1][1] = '1'; maze[1][2] = '1'; maze[1][3] = '1'; maze[1][4] = '1'; maze[1][5] = '1';
//    maze[2][0] = '1'; maze[2][1] = '1'; maze[2][2] = '1'; maze[2][3] = '0'; maze[2][4] = '0'; maze[2][5] = '1';
//    maze[3][0] = '1'; maze[3][1] = '0'; maze[3][2] = '0'; maze[3][3] = '0'; maze[3][4] = 'e'; maze[3][5] = '1';
//    maze[4][0] = '1'; maze[4][1] = '0'; maze[4][2] = '0'; maze[4][3] = 'm'; maze[4][4] = '1'; maze[4][5] = '1';
//    maze[5][0] = '1'; maze[5][1] = '1'; maze[5][2] = '1'; maze[5][3] = '1'; maze[5][4] = '1'; maze[5][5] = '1';
//

    int isTherePath;
    do{
        isTherePath = moveMouse(maze, &currentCell, exitCell, &mazeStack, limitCoord);
    } while (isTherePath == 0);



    printf("\n");

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
