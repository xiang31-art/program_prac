#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef enum {
    GAME_PLAYING,
    GAME_PLAYER_BLACK_WIN,
    GAME_PLAYER_WHITE_WIN,
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


//自作関数群(プロトタイプ宣言)
void initBoard(Game* game);
void printBoard(Game* game);
void checkBoard(Game* game);
void moveCursor(char Usel, Game* game);
bool judgeBoard(Game* game);
bool putStone(Game* game);
void flipStone();
void judgeWin(Game* game);
//自作関数群end



//main関数

int main(void){
    Game gameMain;
    gameMain.cursX = 0;
    gameMain.cursY = 0;
    char Uselect = ' ';
    bool test;

    initBoard(&gameMain);
    printBoard(&gameMain);

    //メインループ
    while(1){

        scanf("%c",&Uselect);
        while (getchar() != '\n');
        printf("\n\n\n\n");

        //配置のコマンドか判定
        if (Uselect != ' '){
            moveCursor(Uselect, &gameMain);
        }
        else if (Uselect == ' '){
            if (judgeBoard(&gameMain) == true){
                if (putStone(&gameMain) == true){
                    //プレイヤー交代
                    if (gameMain.currentPlayer == BLACK){
                        gameMain.currentPlayer = WHITE;
                    }
                    else if (gameMain.currentPlayer == WHITE){
                        gameMain.currentPlayer = BLACK;
                    }
                }
            }

            
        }
        printBoard(&gameMain);

    }
    //メインループ終了

    return 0;
}




//自作関数群

//盤面初期化関数
void initBoard(Game* game){
    for (int x = 0; x < BOARD_SIZE; x++){
        for(int y = 0; y < BOARD_SIZE; y++){
            game->board[y][x] = NONE;
        }
    }

    game->board[3][3] = WHITE;
    game->board[4][4] = WHITE;
    game->board[3][4] = BLACK;
    game->board[4][3] = BLACK;

    return;
}


//盤面表示
void printBoard(Game* game){
     for(int y = 0; y < BOARD_SIZE; y++){
        for(int x = 0; x < BOARD_SIZE; x++){
            if (x == game->cursX && y == game->cursY)
                printf("+  ");
            else if (game->board[y][x] == NONE)
                printf("・ ");
            else if (game->board[y][x] == BLACK)
                printf("●  ");
            else if (game->board[y][x] == WHITE)
                printf("○  ");
        }
        printf("\n");
    }
    return;
}


//盤面チェック
void checkBoard(Game* game){

}


//カーソル移動
void moveCursor(char Usel, Game* game){
    if (Usel == 'w'){        //上
        if (game->cursY > 0){
            --game->cursY;
        }
        else{
            printf("そこには移動できません\n");
        }
    }
    else if (Usel == 's'){   //下
        if (game->cursY < 7){
            ++game->cursY;
        }
        else{
            printf("そこには移動できません\n");
        }
    }
    else if (Usel == 'a'){   //左
        if (game->cursX > 0){
            --game->cursX;
        }
        else{
            printf("そこには移動できません\n");
        }
    }
    else if (Usel == 'd'){
        if (game->cursX < 7){
            ++game->cursX;
        }
        else{
            printf("そこには移動できません\n");
        }
    }

     printf("\n");
     return;
}


//配置可能判定
bool judgeBoard(Game* game){
    int x = game->cursX;
    int y = game->cursY;
    int flag = 0;
    int countStone = 0;

    //すでに置かれていないか
    if (game->board[y][x] != NONE){
        printf("1\n");  //debug
        return false;
    }
    else{
        //上
        
        printf("2\n");      //debug
        for (y = game->cursY - 1; y >= 0; y--){
            printf("3\n");  //debug
            printf("x=%d y =%d\n",x,y);
            if (game->board[y][x] == NONE){
                break;
            }
            else if (game->board[y][x] != game->currentPlayer){
                countStone++;   //相手の色の個数カウント
                printf("4\n");  //debug
            }
            else if(game->board[y][x] == game->currentPlayer && countStone != 0){
                flag++;       //同じ色の石があることを認識
                printf("5\n");  //debug
            }

            
        }
        printf("6\n");  //debug
        if (flag != 0){
        printf("countStone = %d\n",countStone);
        printf("flag = %d\n",flag);
            return true;
        }
    }

    return false;    //debug
}


//配置
bool putStone(Game* game){
    int x = game->cursX;
    int y = game->cursY;

    if (game->board[y][x] != NONE){
        printf("そこには置けません\n");
        return false;
    }
    else {
        if (game->currentPlayer == BLACK){
            game->board[y][x] = BLACK;
       }
        else if (game->currentPlayer == WHITE){
            game->board[y][x] =WHITE;
        }
    }

    return true;
}


//ひっくり返す
void flipStone(){

}


//勝利判定
void judgeWin(Game* game){
    int countWhite = 0;
    int countBlack = 0;

    for (int y = 0; y < BOARD_SIZE; y++){
        for (int x = 0; x < BOARD_SIZE; x++){
            if (game->board[y][x] == BLACK){
                countBlack++;
            }
            else if (game->board[y][x]){
                countWhite++;
            }
        }
    }
    printf("Black: %d\n",countBlack);
    printf("White: %d\n",countWhite);

    if (countBlack < countWhite){
        game->game_State = GAME_PLAYER_WHITE_WIN;
    }
    else if (countBlack > countWhite){
        game->game_State = GAME_PLAYER_BLACK_WIN;
    }
    else if (countBlack == countWhite){
        game->game_State = GAME_DRAW;
    }

    return;
}

//自作関数群end


//余計に作ってしまったもの(盤面表示)
/*
    for (int x = 0; x < BOARD_SIZE; x++){
        for (int y = 0; y < BOARD_SIZE; y++){
            if (gameMain.board[y][x] == NONE)
                printf(" NONE ");
            if (gameMain.board[y][x] == BLACK)
                printf("BLACK ");
            if (gameMain.board[y][x] == WHITE)
                printf("WHITE ");
        }
        printf("\n");
    }
*/