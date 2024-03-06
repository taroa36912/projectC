#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "life.h"

int PlayerIndex = -1;

int manzai_life_1(int dice);
int manzai_life_2(int dice);
int manzai_life_3(int dice);
int manzai_life_4(int dice);
int manzai_life_5(int dice);
int manzai_life_6(int dice);
int manzai_life_7(int dice);
int manzai_life_8(int dice);
int manzai_life_9(int dice);
int manzai_life_10(int dice);
int manzai_life_11(int dice);
int manzai_life_12(int dice);
int manzai_life_13(int dice);
int manzai_life_14(int dice);
int manzai_life_15(int dice);
int manzai_life_16(int dice);
int manzai_life_17(int dice);
int manzai_life_18(int dice);
int manzai_life_19(int dice);
int manzai_life_20(int dice);

int manzai_life(int i, int dice, int turn){
    PlayerIndex = i;
    switch (turn)
    {
    case 1:
        manzai_life_1(dice);
        break;
    case 2:
        manzai_life_2(dice);
        break;
    case 3:
        manzai_life_3(dice);
        break;
    case 4:
        manzai_life_4(dice);
        break;
    case 5:
        manzai_life_5(dice);
        break;
    case 6:
        manzai_life_6(dice);
        break;
    case 7:
        manzai_life_7(dice);
        break;
    case 8:
        manzai_life_8(dice);
        break;
    case 9:
        manzai_life_9(dice);
        break;
    case 10:
        manzai_life_10(dice);
        break;
    case 11:
        manzai_life_11(dice);
        break;
    case 12:
        manzai_life_12(dice);
        break;
    case 13:
        manzai_life_13(dice);
        break;
    case 14:
        manzai_life_14(dice);
        break;
    case 15:
        manzai_life_15(dice);
        break;
    case 16:
        manzai_life_16(dice);
        break;
    case 17:
        manzai_life_17(dice);
        break;
    case 18:
        manzai_life_18(dice);
        break;
    case 19:
        manzai_life_19(dice);
        break;
    case 20:
        manzai_life_20(dice);
        break;
    default:
        break;
    }

    return 0;
}

// manzai_life 関数の定義
int manzai_life_1(int dice) {
    printf("初めて突っ込まれた！！\n");
    getchar();
    printf("「");
    switch (dice)
    {
    case 1:
        printf("なんでやねん");
        break;
    case 2:
        printf("どないしましょか");
        break;
    case 3:
        printf("さんのみや");
        break;
    case 4:
        printf("ほな行きましょか");
        break;
    case 5:
        printf("うせやろ");
        break;
    case 6:
        printf("信じられへん");
        break;
    default:
        break;
    }
    printf("」!!!\n");
    printf("%s, 早くも芸人としての才能の片鱗が見える…！\n", player[i]);
    getchar();
    printf("新しい言葉を覚えたので経験値10アップ!\n");
    expv[i] += 10;
    printf("経験値：%d", expv[i]);
    getchar();
    return 0;
}

int manzai_life_2(int dice) {
    printf("何も起こらなかった！\n");
    getchar();
    return 0;
}

int manzai_life_3(int dice) {
    printf("イベント発生！！\n");
    getchar();
    switch (dice)
    {
    case 1:
        printf("親がいじられる！経験値-10\n");
        expv[i] -= 10;
        break;
    case 2:
        printf("親がいじる！経験値+10\n");
        expv[i] += 10;
        break;
    case 3:
        printf("近所でいじられる！経験値-20\n");
        expv[i] -= 20;
        break;
    case 4:
        printf("近所の中学生をいじった！経験値+20\n");
        expv[i] += 20;
        break;
    case 5:
        printf("親の物まねをした。経験値+30\n");
        expv[i] += 30;
        break;
    case 6:
        printf("まだ何もできなかった。経験値+0\n");
        break;
    }
    getchar();
    return 0;
}

int manzai_life_4(int dice) {
    printf("第一成長期 ! ! 3年進む ! \n");
    getchar();
    return 0;
}

int manzai_life_5(int dice) {
    printf("成長中!\n");
    getchar();
    return 0;
}

int manzai_life_6(int dice) {
    printf("成長中!\n");
    getchar();
    return 0;
}

int manzai_life_7(int dice) {
    printf("じゃんけんイベント発生！！\n");
    getchar();
    expv[i] += Jyanken() * 100;
    getchar();
    return 0;
}

int manzai_life_8(int dice) {
    printf("ミニゲーム発生！！\n");
    getchar();
    expv[i] += minigame() * 200;
    getchar();
    return 0;
}

int manzai_life_9(int dice) {
    printf("第2成長期 ! 5年進む ! ! \n");
    getchar();
    return 0;
}

int manzai_life_10(int dice) {
    printf("成長中!\n");
    getchar();
    return 0;
}

int manzai_life_11(int dice) {
    printf("成長中!\n");
    getchar();
    return 0;
}

int manzai_life_12(int dice) {
    printf("成長中!\n");
    getchar();
    return 0;
}

int manzai_life_13(int dice) {
    printf("成長中!\n");
    getchar();
    return 0;
}

int manzai_life_14(int dice) {
    printf("イベント発生！\n");
    getchar();
    switch (dice)
    {
    case 1:
        printf("学校で漫才を披露したが、滑った！経験値+100\n");
        expv[i] += 100;
        break;
    case 2:
        printf("学校でコントを披露したが、滑った！経験値+100\n");
        expv[i] += 100;
        break;
    case 3:
        printf("学校で披露した漫才が大ウケ！経験値+1000\n");
        expv[i] += 1000;
        break;
    case 4:
        printf("学校で披露したコントが大ウケ！経験値+1000\n");
        expv[i] += 1000;
        break;
    case 5:
        printf("なんと、若くしてM1グランプリ優勝！！経験値+1億");
        expv[i] += 100000000;
        break;
    case 6:
        printf("まだ何もできなかった。経験値+0\n");
        break;
    }
    getchar();
    return 0;
}

int manzai_life_15(int dice) {
    printf("中学校を卒業した！");
    expv[i] += 100;
    getchar();
    return 0;
}

int manzai_life_16(int dice) {
    printf("イベント発生！！");
    getchar();
    switch (dice)
    {
    case 1:
        expv[i] += Jyanken() * 100;
        break;
    case 2:
        expv[i] += Jyanken() * 200;
        break;
    case 3:
        expv[i] += Jyanken() * 300;
        break;
    case 4:
        expv[i] += minigame() * 400;
        break;
    case 5:
        expv[i] += minigame() * 500;
        break;
    case 6:
        expv[i] += minigame() * 600;
    }
    getchar();
    return 0;
}

int manzai_life_17(int dice) {
    printf("サイコロの目：%d\n", dice);
    printf("飛び級した！！\n");
    getchar();
    return 0;
}

int manzai_life_18(int dice) {
    printf("飛び級申請中…\n");
    getchar();
    return 0;
}

int manzai_life_19(int dice) {
    printf("飛び級申請中…\n");
    getchar();
    return 0;
}

int manzai_life_20(int dice) {
    printf("入学！！\n");
    getchar();
    return 0;
}