#include <stdio.h>

int main(void){
    char a = ' ';

    while(1){
        printf("input: ");
        scanf("%c",&a);

        if(getchar()){
            printf("!\a\n");
        }
    }
    return 0;
}