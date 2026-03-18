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
    int cursX;
    int cursY;
} Game;


//自作関数群(プロトタイプ宣言)
void initBoard(Game* game);
void printBoard(int nowX, int nowY, Game* game);
void moveCursor(char Usel, Game* game);
bool judgeBoard();
void putStone();
void flipStone();
int judgeWin();
//自作関数群end



//main関数

int main(void){
    Game gameMain;
    gameMain.cursX = 0;
    gameMain.cursY = 0;
    char Uselect = ' ';
    bool test;

    initBoard(&gameMain);

    //メインループ
    while(1){
        printBoard(gameMain.cursX, gameMain.cursY, &gameMain);

        scanf("%c",&Uselect);
        while (getchar() != '\n');

        moveCursor(Uselect, &gameMain);

        
    }
    test = judgeBoard(4, 4, &gameMain); 
    if (test == true){
        printf("true\n");
    }
    else if (test == false){
        printf("false\n");
    }


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
    return;
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


//配置可能判定
bool judgeBoard(int nowX, int nowY, Game* game){
    int x = nowX;
    int y = nowY;
    int flag = 0;
    int stopFlag = 0;   //味方の石を発見したら止めるため
    int countStone = 0;

    //すでに置かれていないか
    if (game->board[y][x] != NONE){
        printf("1\n");  //
        return false;
    }
    else{
        //上
        stopFlag = flag;    //判定停止用
        printf("2\n");      //
        for (y = nowY; y >= 0; y--){
            printf("3\n");  //
            printf("x=%d y =%d\n",x,y);
            if (game->board[y][x] != game->currentPlayer){
                countStone++;   //相手の色の個数カウント
                printf("4\n");  //
            }
            else if(game->board[y][x] != game->currentPlayer){
                flag++;       //同じ色の石があることを認識
                printf("5\n");  //
            }

            //同じ色の石があったら判定を停止
            if (flag != stopFlag){
                break;
            }
        }
        printf("6\n");  //
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