#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 4    //盤面サイズ
#define NONE 0          //何もないマス

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];  //盤面
    int score;                          //スコア
} Game;


void init_board(Game* game);
bool can_play(Game* game);
void show_result(Game* game);
void print_board(Game* game);
void generate_number(Game* game);
void judge_transferring(Game* game);
void transfer_board(Game* game);
void synthesis_number(Game* game);
void count_score(Game* game);


int main(void){
    Game gameMain;
    char Uselect = " ";

    initBoard(&gameMain);

    printf("--- CLI2048 ---\n");
    while(1){
        //debug
        gameMain.board[2][3] = 23;
        gameMain.board[0][2] = 2;

        printBoard(&gameMain);
        
        printf("input: ");
        scanf("%c",&Uselect);
        while(getchar() != '\n');

        scratchBoard(&gameMain);

    }
}

//初期化
void init_board(Game* game){
    for (int y = 0; y < BOARD_SIZE; y++){
        for (int x = 0; x < BOARD_SIZE; x++){
            game->board[y][x] = NONE;
        }
    }
    game->score = 0;
    return;
}

//盤面チェック(プレイできるか)
bool can_play(Game* game){
    int countEmpty = 0;
    for (int y = 0; y < BOARD_SIZE; y++){
        for (int x = 0; x < BOARD_SIZE; x++){
            if (game->board[y][x] == NONE){
                countEmpty++;
            }       
        }
    }

    if (countEmpty == 0){
        return true;
    }
}

//結果表示
void show_result(Game* game){

}

//盤面表示
void print_board(Game* game){

}

//数生成
void generate_number(Game* game){

}

//移動可能判定
void judge_transferring(Game* game){

}

//移動
void transfer_board(Game* game){

}

//数合成
void synthesis_number(Game* game){

}

//スコア計算
void count_score(Game* game){

}