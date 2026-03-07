#include <stdio.h>

#define BOARD_SIZE 3

typedef enum
{
    Game_Praying;
    Game_X_Win;
    Game_O_Win;
    Game_Draw;
}Gamestate;

struct Game
{
    char board[][]
};



int main