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
    char board[BOARD_SIZE][BOARD_SIZE];
    char PLAYER_X = "X";
    char PLAYER_O = "O";
    char CURRENT_PLAYER;
};

void print_display(){}
void put_judge(){}
void put_piece(){}
void win_judge(){}


int main{
    Game game;


}