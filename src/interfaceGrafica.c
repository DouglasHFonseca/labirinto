#include "interfaceGrafica.h"

void showDisplay(int height, int length, char **maze) {
    int x,y;

    for(x = 0; x < height; x++){
        mgotoxy(0,x);
        printf("%c", 219);
    }
    for(x = 0; x < length; x++){
        mgotoxy(x,0);
        printf("%c", 219);
    }
    for(x = 0; x < height; x++){
        mgotoxy(length,x);
        printf("%c", 219);
    }
    for(x = 0; x < length+1; x++){
        mgotoxy(x,height);
        printf("%c", 219);
    }
    for(x = 0; x < height; x++){
        for(y = 0; y < length+1; y++){
            if(maze[x][y] == '1'){
                mgotoxy(y,x);
                printf("%c", 219);
            }
            if(maze[x][y] == 'e'){
                mgotoxy(y,x);
                printf("%c", 3);
            }
            if(maze[x][y] == 'm'){
                mgotoxy(y,x);
                printf("%c", 30);
            }
            if(maze[x][y] == '.'){
                mgotoxy(y,x);
                printf("%c", 43);
            }
        }
    }
}

void mgotoxy(int x, int y) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x, y});
}