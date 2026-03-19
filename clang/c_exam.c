#include <stdio.h>

#define BOARD_SIZE 8

typedef enum {
    GAME_PLAYING,
    GAME_WIN,
    GAME_DRAW
} State;

typedef enum {
    BLACK,
    WHITE,
    NONE
} Color;

typedef struct
{
    State game_State;
    char board[BOARD_SIZE][BOARD_SIZE];
    Color currentPlayer;
    int cursX;
    int cursY;
} Game;


void initBoard(Game* game){
    for (int x = 0; x < BOARD_SIZE; x++){
        for(int y = 0; y < BOARD_SIZE; y++){
            game->board[y][x] = NONE;
        }
    }
    return;
}

//初期配置
void putFirst(Game* game){
    game->board[3][3] = WHITE;
    game->board[4][4] = WHITE;
    game->board[3][4] = BLACK;
    game->board[4][3] = BLACK;
    return;
}

//表示
void printBoard(int nowX, int nowY, Game* game){
    for(int y = 0; y < BOARD_SIZE; y++){
        for(int x = 0; x < BOARD_SIZE; x++){
            if (x == nowX && y == nowY)
                printf(" + ");
            else if (game->board[y][x] == NONE)
                printf("・ ");
            else if (game->board[y][x] == BLACK)
                printf(" ● ");
            else if (game->board[y][x] == WHITE)
                printf(" ○ ");
        }
        printf("\n");
    }
    
}

//カーソル移動
void moveCursor(char Usel, Game* game){
if (Usel == 'w'){        //上
            if (game->cursY > 0){
                --game->cursY;
            }
            else{
                printf("そこには移動できません1\n");
            }
        }
        else if (Usel == 's'){   //下
            if (game->cursY < 7){
                ++game->cursY;
            }
            else{
                printf("そこには移動できません2\n");
            }
        }
        else if (Usel == 'a'){   //左
            if (game->cursX > 0){
                --game->cursX;
            }
            else{
                printf("そこには移動できません3\n");
            }
        }
        else if (Usel == 'd'){
            if (game->cursX < 7){
                ++game->cursX;
            }
            else{
                printf("そこには移動できません4\n");
            }
        }        

         printf("\n");
}


int main(void){
    Game game;
    game.cursX = 0;
    game.cursY = 0;
    char Uselect = ' ';

    initBoard(&game);
    putFirst(&game);


    while(1){
        printBoard(game.cursX, game.cursY, &game);

        scanf("%c",&Uselect);
        while (getchar() != '\n');

        moveCursor(Uselect, &game);

        
    }


    return 0;
}