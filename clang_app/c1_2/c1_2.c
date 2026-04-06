#include <stdio.h>
#include <stdbool.h>

//偶数のみ変更可能
#define BOARD_SIZE 8
#define FLIP_MAX (BOARD_SIZE - 2)

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
void initBoard(Game *game);
void printBoard(Game *game);
void showCurrentPlayer(Game *game);
bool checkBoard(Game *game);
void moveCursor(char Usel, Game *game);
bool judgeBoard(Game *game, int x, int y);
bool putStone(Game *game);
void flipStone(Game *game);
void cheatFlipAll(Game *game);
void changePlayer(Game *game);
void judgeWin(Game *game);
//自作関数群end



//main関数

int main(void){
    Game gameMain;
    gameMain.cursX = 0;
    gameMain.cursY = 0;
    char Uselect = ' ';
    int flag = 0;

    printf("------------------ CLIオセロ -------------------\n");
    printf("| 操作方法                                     |\n");
    printf("|1.w,a,s,dのキーで移動します。                 |\n");
    printf("|2.スペースキーを押して石を配置。              |\n");
    printf("|   大文字入力すると、端まで移動できます       |\n");
    printf("|注:すべての操作の後にEnterキーを押してください|\n");
    printf("------------------------------------------------\n");

    initBoard(&gameMain);

    //メインループ
    while(1){
        showCurrentPlayer(&gameMain);
        printBoard(&gameMain);

        if (flag == 2){
            judgeWin(&gameMain);
            return 0;
        }

        if (checkBoard(&gameMain) == false){
            flag++;
            changePlayer(&gameMain);
            printf("pass\n");
            continue;
        }

        scanf("%c",&Uselect);
        while (getchar() != '\n');
        printf("\n\n\n\n");

        //配置のコマンドか判定
        if (Uselect != ' '){
            moveCursor(Uselect, &gameMain);
        }

        

        else if (Uselect == ' '){
            if (judgeBoard(&gameMain, gameMain.cursX, gameMain.cursY) == true){
                if (putStone(&gameMain) == true){
                    flag = 0;
                    flipStone(&gameMain);
                    changePlayer(&gameMain);
                }
            }
            else{
                printf("そこには置けません\n");
            }

            
        }
    }
    //メインループ終了

    return 0;
}

//main関数end


//自作関数群

//盤面初期化関数
void initBoard(Game *game){
    for (int x = 0; x < BOARD_SIZE; x++){
        for(int y = 0; y < BOARD_SIZE; y++){
            game->board[y][x] = NONE;
        }
    }

    //初期配置
    game->board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 - 1] = WHITE;
    game->board[BOARD_SIZE / 2][BOARD_SIZE / 2] = WHITE;
    game->board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2] = BLACK;
    game->board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1] = BLACK;

    game->currentPlayer = BLACK;

    return;
}


//盤面表示
void printBoard(Game *game){
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


//現在プレイヤー表示
void showCurrentPlayer(Game *game){
    if (game->currentPlayer == WHITE){
        printf("Turn : ○○○○\n");
    }
    else if (game->currentPlayer == BLACK){
        printf("Turn : ●●●●\n");
    }
}


//盤面チェック
bool checkBoard(Game *game){
    for (int y = 0; y < BOARD_SIZE; y++){
        for (int x = 0; x < BOARD_SIZE; x++){
            //埋まりマスを除く
            if (game->board[y][x] != NONE){
                continue;
            }

            //空きマスが配置可能か判定
            if (judgeBoard(game, x, y) == true){
                return true;
            }
        }
    }
    return false;
}


//カーソル移動
void moveCursor(char Usel, Game *game){
    if (Usel == 'w'){        //上
        if (game->cursY > 0){
            --game->cursY;
        }
        else{
            printf("そこには移動できません\n");
        }
    }
    else if (Usel == 's'){   //下
        if (game->cursY < BOARD_SIZE -1){
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
        if (game->cursX < BOARD_SIZE - 1){
            ++game->cursX;
        }
        else{
            printf("そこには移動できません\n");
        }
    }

    else if (Usel == 'W'){
        game->cursY = 0;
    }
    else if (Usel == 'A'){
        game->cursX = 0;
    }
    else if (Usel == 'S'){
        game->cursY = BOARD_SIZE - 1;
    }
    else if (Usel == 'D'){
        game->cursX = BOARD_SIZE - 1;
    }
    else if (Usel == '+'){
        cheatFlipAll(game);
    }
     return;
}


//配置可能判定
bool judgeBoard(Game *game, int x, int y){
    int countStone = 0;
    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    
    for (int dir = 0; dir < 8; dir++){
        int nx = x;     //探索用変数
        int ny = y;     //n -> next
        countStone = 0;


        for (;;){
            //判定する方向へ1マス移動
            nx += dx[dir];
            ny += dy[dir];
            
            //範囲チェック
            if (nx < 0 || nx >= BOARD_SIZE || ny < 0 || ny >= BOARD_SIZE){
                break;
            }
        
            //判定
            if (game->board[ny][nx] == NONE){
                break;
            }
            else if (game->board[ny][nx] != game->currentPlayer){
                countStone++;   //相手の色の個数カウント
            }
            else if(game->board[ny][nx] == game->currentPlayer && countStone > 0){
                return true;
            }
        }
    }
    return false;
}


//配置
bool putStone(Game *game){
    //省略用
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


//ひっくり返す(ほぼjudgeBoardと同じ)
void flipStone(Game *game){
    //省略用
    int x = 0;
    int y = 0;

    //方向転換用
    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    //ひっくり返す座標記録用
    int countX[FLIP_MAX];
    int countY[FLIP_MAX];
    int index = 0;  //座標記録配列の要素指定用


    for (int dir = 0; dir < 8; dir++){  //8方向の切り替え
        x = game->cursX;
        y = game->cursY;
        index = 0;
        int countStone = 0;
        int flag = 0;

        //座標記録初期化
        //0ではないことで、ひっくり返すときに終わりを判定する
        for (int i = 0; i < FLIP_MAX; i++){
            countX[i] = BOARD_SIZE;
            countY[i] = BOARD_SIZE;
        }

        //座標記録処理
        for (;;){
            //判定する方向へ1マス移動
            x += dx[dir];
            y += dy[dir];
            
            //範囲チェック
            if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE){
                break;
            }
        
            //判定
            if (game->board[y][x] == NONE){
                break;
            }
            else if (game->board[y][x] != game->currentPlayer){
                //座標を記録
                countX[index] = x;
                countY[index] = y;
                index++;
                countStone++;
            }
            else if (game->board[y][x] == game->currentPlayer && countStone > 0){
                flag = 1;
                break;
            }
        }

        //自分の石でbreakしたか判定
        if (flag == 0){
            continue;
        }

        //ひっくり返す処理
        for (int i = 0; i < FLIP_MAX; i++){
            //終了か判定
            if (countX[i] == BOARD_SIZE){
                break;
            }

            //省略用
            int XX = countX[i];
            int YY = countY[i];
            
            if (game->board[YY][XX] == BLACK){
                game->board[YY][XX] = WHITE;
            }
            else if (game->board[YY][XX] == WHITE){
                game->board[YY][XX] = BLACK;
            }
        }
    }
    return;
}


//チート
void cheatFlipAll(Game *game){
    for (int y = 0; y < BOARD_SIZE; y++){
        for (int x = 0; x < BOARD_SIZE; x++){
            game->board[y][x] = game->currentPlayer;
        }
    }
    return;
}


//プレイヤー交代
void changePlayer(Game *game){
      if (game->currentPlayer == BLACK){
           game->currentPlayer = WHITE;
       }
       else if (game->currentPlayer == WHITE){
           game->currentPlayer = BLACK;
       }
       return;
}
 


//勝利判定
void judgeWin(Game *game){
    int countWhite = 0;
    int countBlack = 0;

    for (int y = 0; y < BOARD_SIZE; y++){
        for (int x = 0; x < BOARD_SIZE; x++){
            if (game->board[y][x] == BLACK){
                countBlack++;
            }
            else if (game->board[y][x] == WHITE){
                countWhite++;
            }
        }
    }
    printf("●●●●: %d\n",countBlack);
    printf("○○○○: %d\n",countWhite);

    if (countBlack < countWhite){
        game->game_State = GAME_PLAYER_WHITE_WIN;
        printf("Player:○○○○の勝ち\n");
    }
    else if (countBlack > countWhite){
        game->game_State = GAME_PLAYER_BLACK_WIN;
        printf("Player:●●●●の勝ち\n");
    }
    else if (countBlack == countWhite){
        game->game_State = GAME_DRAW;
        printf("引き分け...\n");
    }

    return;
}

//自作関数群end