#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "life.h"


//この人生に選ばれたプレイヤーが何人目か
int PlayerIndex = -1;


//各ターンにおける定数の設定
//ターンごとに別々の変数を用い，各ターンの関数で用いる
char turn1_word[6][100]={};
char turn3_word_event[6][100]={};
int turn7_times = -1;
int turn3_exp[6] = {10,20,30,40,50,60};
char turn14_word_name[6][100]={};
char turn14_word_thing[6][100]={};
char turn15_word_event[100]={};
int turn15_exp_event = -1;
char turn16_word_event[100]={};
int turn16_exp_event=-1;


int life1_1(int dice);
int life1_2(int dice);
int life1_3(int dice);
int life1_4(int dice);
int life1_5(int dice);
int life1_6(int dice);
int life1_7(int dice);
int life1_8(int dice);
int life1_9(int dice);
int life1_10(int dice);
int life1_11(int dice);
int life1_12(int dice);
int life1_13(int dice);
int life1_14(int dice);
int life1_15(int dice);
int life1_16(int dice);
int life1_17(int dice);
int life1_18(int dice);
int life1_19(int dice);
int life1_20(int dice);



void InputLife1(void){
    //まず1年目の人生を設計する
    printf("ターン1の設定.\n");
    //ある程度のフォーマットは用意しておく. 各自，自分の作った人生のフォーマットに合わせればよい.
    printf("1ターン目で喋る言葉を書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn1_word[dice-1]);//%sは，&がいらない
    }

    //2年目の人生を設計する
    printf("ターン2の設定.\n");
    printf("2年目は何も起こらないので設定不要.\n");


    //3年目の人生を設計する
    printf("ターン3の設定.\n");
    printf("3年目で起こる出来事を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn3_word_event[dice-1]);
    }


    //4~6年目の人生を設計する
    printf("ターン4~6の設定.\n");
    printf("4~6年目は何も起こらないので設定不要.\n");
    //これってただの3回休みじゃね...


    //7年目の人生を設計する
    printf("ターン7の設定.\n");
    printf("7年目に起こる個人ミニゲームで得られる点数の倍率を, 1~10の範囲で設定してください.\n");
    while(turn7_times < 0 || 10 < turn7_times){
        printf("1~10の範囲で設定してください.\n");
        scanf("%d", &turn7_times);
    }

    //8年目の人生を設計する
    printf("ターン8の設定.\n");
    printf("ターン8はプレイヤー横断イベントなので入力はいりません.\n");

    //9年目の人生を設計する
    printf("ターン9~13の設定.\n");
    printf("9~13年目は何も起こらないので設定不要.\n");

    //14年目の人生を設計する
    printf("ターン14の設定.\n");
    printf("14年目で物をもらいます. もらう人物と, そのものを，サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        printf("もらう人物：");
        scanf("%s", turn14_word_name[dice-1]);
        printf("もらう物: ");
        scanf("%s", turn14_word_thing[dice-1]);
    }

    //15年目の人生を設計する
    printf("ターン15の設定.\n");
    printf("15年目で起こる出来事を書いてください.\n");
    scanf("%s", turn15_word_event);
    printf("また，このターンで起こる設定を, 数字で選択してください.\n");
    printf("1: 経験値が増える, 2: じゃんけんイベントを発生させる, 3: Battleイベントを発生させる");
    while(turn15_exp_event < 1 || 3 < turn15_exp_event){
        printf("1~3の範囲で入力してください.\n");
        scanf("%d", &turn15_exp_event);
    }

    //16年目の人生を設計する
    printf("ターン16の設定.\n");
    printf("16年目で起こる出来事を書いてください.\n");
    scanf("%s", turn16_word_event);
    printf("また，このターンで起こる設定を, 数字で選択してください.\n");
    printf("1: 経験値が増える, 2: じゃんけんイベントを発生させる, 3: Battleイベントを発生させる");
    while(turn16_exp_event < 1 || 3 < turn16_exp_event){
        printf("1~3の範囲で入力してください.\n");
        scanf("%d", &turn16_exp_event);
    }
}



int life1(int i, int dice, int turn) {
    PlayerIndex = i;
    switch (turn) {
        case 1:
            life1_1(dice);
            break;
        case 2:
            life1_2(dice);
            break;
        case 3:
            life1_3(dice);
            break;
        case 4:
            life1_4(dice);
            break;
        case 5:
            life1_5(dice);
            break;
        case 6:
            life1_6(dice);
            break;
        case 7:
            life1_7(dice);
            break;
        case 8:
            life1_8(dice);
            break;
        case 9:
            life1_9(dice);
            break;
        case 10:
            life1_10(dice);
            break;
        case 11:
            life1_11(dice);
            break;
        case 12:
            life1_12(dice);
            break;
        case 13:
            life1_13(dice);
            break;
        case 14:
            life1_14(dice);
            break;
        case 15:
            life1_15(dice);
            break;
        case 16:
            life1_16(dice);
            break;
        case 17:
            life1_17(dice);
            break;
        case 18:
            life1_18(dice);
            break;
        case 19:
            life1_19(dice);
            break;
        case 20:
            life1_20(dice);
            break;
        default:
            break;
    }

    return 0;
}

// life 関数の定義
int life1_1(int dice) {//1年目の人生
    printf("初めて喋った！！\n");
    getchar();
    printf("「");
    printf("%s", turn1_word[dice-1]);//いつものようにswitch文で書いても良い.
    printf("」!!!\n");
    printf("%s, 早くも芸人としての才能の片鱗が見える…！\n", player[PlayerIndex]);
    getchar();
    printf("新しい言葉を覚えたので経験値%dアップ!\n", 10);
    expv[PlayerIndex] += 10;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
}

int life1_2(int dice) {
    printf("何も起こらなかった！\n");
    printf("%d", dice);
    getchar();
    return 0;
}

int life1_3(int dice) {
    printf("イベント発生！！\n");
    getchar();
    printf("%s\n", turn3_word_event[dice-1]);
    getchar();
    printf("新しい言葉を覚えたので経験値%dアップ!\n", turn3_exp[dice-1]);
    expv[PlayerIndex] += turn3_exp[dice-1];
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
}

int life1_4(int dice) {
    printf("%d", dice);
    printf("第一成長期!! 3年進む ! \n");
    printf("経験値20アップ!!\n");
    expv[PlayerIndex] += 20;
    getchar();
    return 0;
}

int life1_5(int dice) {
    printf("%d", dice);
    printf("成長中!\n");
    printf("経験値20アップ!!\n");
    expv[PlayerIndex] += 20;
    getchar();
    return 0;
}

int life1_6(int dice) {
    printf("%d", dice);
    printf("成長中!\n");
    printf("経験値20アップ!!\n");
    expv[PlayerIndex] += 20;
    getchar();
    return 0;
}

int life1_7(int dice) {
    
    switch (dice)
    {
    case 1:
        printf("じゃんけんイベント発生！！\n");
        getchar();
        expv[PlayerIndex] += Jyanken() * turn7_times;
        break;
    
    case 2:
        printf("じゃんけんイベント発生！！\n");
        getchar();
        expv[PlayerIndex] += Jyanken() * turn7_times;
        break;

    case 3:
        printf("じゃんけんイベント発生！！\n");
        getchar();
        expv[PlayerIndex] += Jyanken() * turn7_times;
        break;

    case 4:
        printf("ミニゲーム発生！！\n");
        getchar();
        expv[PlayerIndex] += Battle() * turn7_times;
        break;

    case 5:
        printf("ミニゲーム発生！！\n");
        getchar();
        expv[PlayerIndex] += Battle() * turn7_times;
        break;

    case 6:
        printf("ミニゲーム発生！！\n");
        getchar();
        expv[PlayerIndex] += Battle() * turn7_times;
        break;
    
    default:
        break;
    }
    getchar();
    return 0;
}

int life1_8(int dice) {
    printf("%d", dice);
    printf("イベント発生!!\n");
    getchar();
    All_minigame();
    getchar();
    return 0;
}

int life1_9(int dice) {
    printf("%d", dice);
    printf("第2次成長期! 5年進む!!\n");
    printf("経験値20アップ!!\n");
    expv[PlayerIndex] += 20;
    return 0;
}

int life1_10(int dice) {
    printf("%d", dice);
    printf("成長中...\n");
    printf("経験値20アップ!!\n");
    expv[PlayerIndex] += 20;
    return 0;
}

int life1_11(int dice) {
    printf("%d", dice);
    printf("成長中...\n");
    printf("経験値20アップ!!\n");
    expv[PlayerIndex] += 20;
    return 0;
}

int life1_12(int dice) {
    printf("%d", dice);
    printf("成長中...\n");
    printf("経験値20アップ!!\n");
    expv[PlayerIndex] += 20;
    return 0;
}

int life1_13(int dice) {
    printf("%d", dice);
    printf("成長中...\n");
    printf("経験値20アップ!!\n");
    expv[PlayerIndex] += 20;
    return 0;
}

int life1_14(int dice) {
    printf("%sから%sをもらった!!\n", turn14_word_name[dice-1], turn14_word_thing[dice-1]);
    getchar();
    printf("経験値%dアップ!!\n", 50);
    expv[PlayerIndex] += 50;
    printf("%sの経験値: %d", player[PlayerIndex], expv[PlayerIndex]);
    getchar();
    return 0;
}

int life1_15(int dice) {
    printf("%d", dice);
    switch (turn15_exp_event)
    {
    case 1:
        printf("経験値%dアップ!!\n", 50);
        expv[PlayerIndex] += 50;
        break;
    case 2:
        printf("じゃんけんイベント発生!!\n");
        Jyanken();
        break;
    case 3:
        printf("Battleイベント発生!!\n");
        break;
    
    default:
        printf("error.\n");
        break;
    }
    getchar();
    printf("%sの経験値: %d", player[PlayerIndex], expv[PlayerIndex]);
    getchar();
    return 0;
}

int life1_16(int dice) {
    printf("%d", dice);
    switch (turn16_exp_event)
    {
    case 1:
        printf("経験値%dアップ!!\n", 50);
        expv[PlayerIndex] += 50;
        break;
    case 2:
        printf("じゃんけんイベント発生!!\n");
        Jyanken();
        break;
    case 3:
        printf("Battleイベント発生!!\n");
        break;
    
    default:
        printf("error.\n");
        break;
    }
    getchar();
    printf("%sの経験値: %d", player[PlayerIndex], expv[PlayerIndex]);
    getchar();
    return 0;
}

int life1_17(int dice) {
    printf("%d", dice);
    printf("飛び級した!!3年進む!!\n");
    getchar();
    return 0;
}

int life1_18(int dice) {
    printf("%d", dice);
    printf("飛び級申請中...\n");
    printf("経験値20アップ!!\n");
    expv[PlayerIndex] += 20;
    return 0;
}

int life1_19(int dice) {
    printf("%d", dice);
    printf("飛び級申請中...\n");
    printf("経験値20アップ!!\n");
    expv[PlayerIndex] += 20;
    return 0;
}

int life1_20(int dice) {
    printf("%d", dice);
    printf("飛び級申請中...\n");
    printf("経験値20アップ!!\n");
    expv[PlayerIndex] += 20;

    return 0;
}
