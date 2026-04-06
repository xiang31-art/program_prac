#include <stdio.h>

typedef struct{
    char name[20];  //キャラ名
    int hp;         //体力
    int max_hp;     //最大HP(回復上限判定用)
    int attack;     //攻撃力
    int defense;    //防御力
} Character;

void create_character(Character *chara);
void show_character();
void show_all();
void battle();
void heal();

int main(void){
    Character characters[5];
    int Unum;   //Usernumber

    printf("--- RPG キャラクター管理 ---\n");

    while(1){
        printf("1.キャラ登録\n");
        printf("2.一覧表示\n");
        printf("3.バトル\n");
        printf("4.回復\n");
        printf("5.終了\n");
        printf("選択 >");
        scanf("%d",&Unum);
        while(getchar() != '\n');

        //バリデーションチェック
        if (Unum < 1 || Unum > 5){
            printf("予期しない値が入力されました\n");
            continue;
        }

        switch(Unum){
            case 1:
                create_character(&characters);
                break;
            case 2:
                printf("2\n\n");
                break;
            case 3:
                printf("3\n\n");
                break;
            case 4:
                printf("4\n\n");
                break;
            case 5:
                printf("5\n\n");
                return 0;
            default:
                printf("どうやってここにたどり着いたの?\n\n");
        }

    }
}

void create_character(Character *chara){
    //キャラ数判定
    int count = 0;
    

    printf("-- キャラ登録 --\n");
    printf("キャラ名:");
    scanf("%s",*chara[].name[])
}

void show_character();

void show_all();

void battle();

void heal();