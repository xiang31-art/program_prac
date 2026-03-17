#include <stdio.h>

#define BOARD_SIZE 3

int main(void){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            printf("あ");
        }
        printf("\n");
    }

    return 0;
}