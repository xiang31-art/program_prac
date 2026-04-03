#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
    int gameboard[4][4];
    int score;
    char Userect;
}Game;

void initBoard(Game *game);
void printBoard(Game *game);
void scratchBoard(Game *game);


int main(void){
    Game gameMain;

    initBoard(&gameMain);

    printf("--- CLI2048 ---\n");
    while(1){
        //debug
        gameMain.gameboard[2][3] = 23;
        gameMain.gameboard[0][2] = 2;

        printBoard(&gameMain);
        
        printf("input: ");
        scanf("%c",&gameMain.Userect);
        while(getchar() != '\n');

        scratchBoard(&gameMain);

    }
    

}


//盤面初期化
void initBoard(Game *game){
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            game->gameboard[y][x] = 0;
        }
    }
    return;
}


//盤面表示
void printBoard(int *gameboard[][]){
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            printf("%4d | ",game->gameboard[y][x]);
        }
        printf("\n---------------------------\n");
    }
}

//コマの移動
void scratchBoard(Game *game){
    int board[4][4];

    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            board[y][x] = game->gameboard[y][x];
        }
    }

    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            printf("%4d | ",game->gameboard[y][x]);
        }
        printf("\n");
    }
}