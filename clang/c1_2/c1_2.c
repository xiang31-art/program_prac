#include <stdio.h>
#include <stdbool.h>

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
} Game;


//自作関数群(プロトタイプ宣言)
void initBoard(Game* game);
void putFirst(Game* game);
void printBoard(Game* game);
bool judgeBoard();
void putStone();
void flipStone();
int judgeWin();
//自作関数群end



//main関数

int main(void){
    Game gameMain;
    bool test;

    initBoard(&gameMain);
    putFirst(&gameMain);
    printBoard(&gameMain);

    gameMain.currentPlayer = WHITE;
    gameMain.board[4][2] = BLACK;
    gameMain.board[4][1] = BLACK;

    test = judgeBoard(4, 0, &gameMain); 
    if (test == true){
        printf("true\n");
    }
    else if (test == false){
        printf("false\n");
    }



    printBoard(&gameMain);

    return 0;
}




//自作関数群

//盤面初期化関数
void initBoard(Game* game){
    for (int x = 0; x < BOARD_SIZE; x++){
        for(int y = 0; y < BOARD_SIZE; y++){
            game->board[x][y] = NONE;
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

//盤面表示
void printBoard(Game* game){
    for(int x = 0; x < BOARD_SIZE; x++){
        for(int y = 0; y < BOARD_SIZE; y++){
            if (game->board[x][y] == NONE)
                printf("・ ");
            if (game->board[x][y] == BLACK)
                printf("●  ");
            if (game->board[x][y] == WHITE)
                printf("○  ");
        }
        printf("\n");
    }
    return;
}

//配置可能判定
bool judgeBoard(int nowX, int nowY, Game* game){
    int x = nowX;
    int y = nowY;
    int flag = 0;
    int countStone = 0;

    //すでに置かれていないか
    if (game->board[x][y] != NONE){
        return false;
    }
    else{
        //上
        for (int i = y; y != 0; y--){
            if (game->board[x][y] != game->currentPlayer){
                countStone++;   //相手の色の個数カウント
                printf("1\n");
            }
            else if(game->board[x][y] != game->currentPlayer){
                flag++;       //同じ色の石があることを測定
                printf("2\n");
            }
        }

        if (flag != 0){
        printf("countStone = %d\n",countStone);
        printf("flag = %d\n",flag);
            return true;
        }
    }
}

//配置
void putStone(){

}

//ひっくり返す
void flipStone(){

}

//勝利判定
int judgeWin(){

}

//自作関数群end


//余計に作ってしまったもの(盤面表示)
/*
    for (int x = 0; x < BOARD_SIZE; x++){
        for (int y = 0; y < BOARD_SIZE; y++){
            if (gameMain.board[x][y] == NONE)
                printf(" NONE ");
            if (gameMain.board[x][y] == BLACK)
                printf("BLACK ");
            if (gameMain.board[x][y] == WHITE)
                printf("WHITE ");
        }
        printf("\n");
    }
*/