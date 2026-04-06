#include <stdio.h>
#include <stdlib.h> // malloc, free 用

// 定数定義
#define BOARD_SIZE 8
#define EMPTY 0
#define BLACK 1
#define WHITE 2

// 盤面の表現
int board[BOARD_SIZE][BOARD_SIZE];

// 盤面を初期化する
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

// 盤面を表示する
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf(" . ");
            } else if (board[i][j] == BLACK) {
                printf(" X ");
            } else {
                printf(" O ");
            }
        }
        printf("\n");
    }
}

// 石を置く（無効な場合は何もしない）
void place_stone(int row, int col) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == EMPTY) {
        board[row][col] = BLACK; // 黒石を置く（ここでは黒石のみ）
    }
}

// 石を反転させる（周囲の石をチェックして、同じ色の石を反転）
void flip_stones(int row, int col) {
    // TODO: 石を反転させるロジックの実装 (周囲の石を探索し、同じ色の石を反転させる)
}

// 勝利判定（TODO: 勝利条件を満たしているか判定する）
int check_win() {
  // TODO: 勝利条件を満たしているか判定する
  return 0; // 仮の勝利判定
}

int main() {
    initialize_board();

    // ゲームループ
    while (1) {
        print_board();

        // ユーザー入力（例：行、列）
        int row, col;
        printf("石を置く場所（行 列）：");
        scanf("%d %d", &row, &col);

        place_stone(row, col);

        // TODO: 勝利判定を行う
        if (check_win() == 1) {
            printf("黒が勝ち！\n");
            break;
        }
    }

    return 0;
}
