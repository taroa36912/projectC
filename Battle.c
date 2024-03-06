#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "life.h"

int Battle(){
    printf("ルール説明を行います\n");
    getchar();
    printf("貴方と敵はそれぞれ、攻撃、ガードブレイク、ガードのうち一つを選びます\n");
    getchar();
    printf("攻撃はガードブレイクに強く、ガードブレイクはガードに強く、ガードは攻撃に強いです\n");
    getchar();
    printf("以上の相性を元に勝敗が決定します\n");
    getchar();
    printf("先に三勝した方が勝利です！それでは頑張って！\n");
    int human_win_number = 0;
    int com_win_number = 0;
    for(;;){
        Battle_result();
        if(human_win_number == 3||com_win_number == 3){
            printf("戦闘終了！\n");
            break;
        }
        else{
            printf("戦闘続行\n");
        }
    }
    if (human_win_number > 3){
        printf("貴方の勝利です！\n");
        return 2;
    }
    else{
        printf("貴方は敗北した...\n")
        return 0;
    }
}

int Battle_result()
{
    printf("両者が態勢を構えた\n");
    int num = judge();
    switch (num)
    {
    case 0:
        printf("貴方にダメージ！\n");
        com_win_number += 1;
        return 0;
    case 1:
        printf("敵に有効打！\n");
        human_win_number += 1;
        return 1;
    case 2:
        printf("相殺！\n");
        return 2;
    default:
        return -1;
    }
}

int human_play(){
    int num;
    do
    {
        printf("攻撃:0 ガードブレイク:1 ガード:2 を入力してください: ");
        scanf("%d", &num);
        if (num < 0 || num > 2)
        {
            printf("正しい値を入力してください\n");
        }
    } while (num <0 || num >2);
    return num;
}

int computer_play()
{
    srand(time(NULL));
    return rand() % 3;
}
int judge(){
    int humP = human_play();
    int comP = computer_play();

    print_hand(comP);

    switch (comP - humP)
    {
    case 1:
    case -2:
        return 0;
    case -1:
    case 2:
        return 1;
    case 0:
        return 2;
    default:
        break;
    }
    return 3;
}