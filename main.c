#include "stdio.h"
#include "time.h"

/*
+-+-
|x|
+-+
*/

void printMap_old(char *map_ptr, const int lenght, const int height) {
    char (*map)[lenght] = map_ptr;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < lenght; j++) {
            printf("+-\e[2D\e[B|%c\e[A", map[i][j]);
        }
        printf("+\e[D\e[B|\n");
    }        
    for (int j = 0; j < lenght; j++)
            printf("+-");
    printf("+\n\n");
}

void printGame(char *map_ptr, const int lenght, const int height) {
    char (*map)[lenght] = map_ptr;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < lenght; j++) {
            printf("\e[%i;%iH+-\e[2D\e[B|%c\e[A", i*2+1, j*2+1, map[i][j]);
        }
    } 
    for (int i = 0; i < height; i++)
        printf("\e[%i;%iH+\e[D\e[B|", i*2+1, lenght*2+1);
    for (int i = 0; i < height; i++)
        printf("\e[%i;%iH+-", height*2+1, i*2+1);
    printf("\e[%i;%iH+", height*2+1, lenght*2+1);

    printf("\n\n\n");
}
 
float millis() {
    return (float)clock() / CLOCKS_PER_SEC;
}

int main(int argc, const char *argv[])
{
    //map defenition 
    int lenght = 3;
    int height = 3;
    char map[height][lenght];

    //user input
    float lastPrint = 0.;
    float lastInput = 0.;
    int cursor [2] = {height/2, height/2};

    for (int i = 0; i < height; i++)
        for (int j = 0; j < lenght; j++)
            map[i][j] = ' ';    

    printGame(map, lenght, height);

    //infinite game loop
    while (1)
    {
        if (millis() > lastPrint+1000./60.) //60 fps
            printGame(map, lenght, height);
        
    }
    

}
