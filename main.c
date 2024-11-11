#include "stdio.h"
#include "time.h"
#include "stdlib.h"

struct Game
{
    int lenght;
    int height;
    int cursor[2];
    char* map;
}; // TODO dynamic size

void printGame(const struct Game* game) {
    char (*map)[game->lenght] = game->map;

    //printf("\e[2J");
    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->lenght; j++) {
            if ((i == game->cursor[0]) && (j == game->cursor[1]))
                printf("\e[%i;%iH+-\e[2D\e[B|\e[30;47m%c\e[0m\e[A", i*2+1, j*2+1, map[i][j]);
            else
                printf("\e[%i;%iH+-\e[2D\e[B|%c\e[A", i*2+1, j*2+1, map[i][j]);
        }
    } 
    for (int i = 0; i < game->height; i++)
        printf("\e[%i;%iH+\e[D\e[B|", i*2+1, game->lenght*2+1);
    for (int i = 0; i < game->height; i++)
        printf("\e[%i;%iH+-", game->height*2+1, i*2+1);
    printf("\e[%i;%iH+", game->height*2+1, game->lenght*2+1);

    printf("\n\n\n");
}
 
float millis() {
    return (float)clock() / CLOCKS_PER_SEC;
}


int main(int argc, const char *argv[])
{
    int lenght_i = 3;
    int height_i = 3;

    struct Game game = {
        .lenght = lenght_i,
        .height = height_i,
        .cursor = {height_i/2, lenght_i/2},
        .map = (char*)calloc(height_i*lenght_i, sizeof(char))
        //.map = calloc(height_i, sizeof(char*))
    };

    //user input
    float lastPrint = 0.;
    float lastInput = 0.;
    int cursor [2] = {game.lenght/2, game.height/2};

    for (char* ptr = game.map; ptr < (char*)(game.map + height_i*lenght_i); ptr++)
        *ptr = ' ';
    

    //infinite game loop
    while (1)
    {
        //60 fps
        if (millis() > lastPrint+1./60.) {
            printGame(&game);
            lastPrint = millis();
        }
    }
}
