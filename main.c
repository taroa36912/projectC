#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "life.h"

char player[6][100];//プレイヤー名
int expv[6]={0};//みんなの経験値, エラーが起こるので変数名をexpvに変更
int life[6] = {-1, -1, -1, -1, -1, -1}; //プレイヤー0~5に人生番号を割り振る
char abstract[6][256];//割り振られたときの人生の説明

int play_life(int i, int life, int dice, int turn);
void select_life(void);

int main()
{
    int dice;
    printf("半生ゲーム！\n");
    getchar();
    //プレイヤー名を決める
    for (int i = 0; i < 6; i++)
    {
        printf("player%d:名前(英数半角)を入力してください>>", i);
        scanf("%99s", player[i]);
        printf("やあ、%s。これから冒険に出かけよう ! \n", player[i]);
    }
    getchar();
    //人生を決める(手入力)
    printf("今からそれぞれの人生を設計してもらいます. \n他の人の入力は見ないようにしましょう.\n入力に要する時間は, 一人5分程度です.\n");

    for(int i = 0; i < 6; i++)
    {
        printf("%sさん,自分が作成する人生を一言で入力してください. (○○な人生): \n", player[i]);
        scanf("%s", abstract[i]);

        switch (i)
        {
        case 0:
            InputLife1();
            break;    
        case 1:
            InputLife2();
            break;
        case 2:
            InputLife3();
            break;
        case 3:
            InputLife4();
            break;
        case 4:
            InputLife5();
            break;
        case 5:
            InputLife6();
            break;
        default:
            break;
        }
        printf("次の方です.\n");
        getchar();
    }
//全員の人生を一度に決める(6人分全ての人生を使うため,重複を許さない)
    printf("それでは、進む人生を決めましょう！\n");
    printf("%sさん、Enterキーを押してください. \n", player[0]);//プレイヤー0が代表して抽選
    getchar();
    select_life();
//人生の発表
    for (int i = 0; i < 6; i++)
    {
        printf("%sさん, あなたは%sを歩みます. \n\n", player[i],abstract[life[i]-1]);
    }
//実際にプレイ
    for (int turn = 1; turn <= 20; turn++)
    {
        for (int i = 0; i < 6; i++)
        {
            printf("\n%sさん、%d歳です!Enterを押してサイコロを振ってください\n", player[i],turn);
            getchar();
            srand(time(NULL));
            dice = rand() % 6 + 1;
            printf("サイコロの目：%d\n", dice);
            select_life(i, life[i], dice, turn);//iはプレイヤーの順番番号(0~5)
        }
    }
}
//header fileから呼び出す部分
int play_life(int i, int life, int dice, int turn)//iはプレイヤーID,diceはサイコロの目、turnは年齢
{
    switch (life)
    {
    case 1:
        life1(i, dice, turn);
        break;
    case 2:
        life2(i, dice, turn);
        break;
    case 3:
        life3(i, dice, turn);
        break;
    case 4:
        life4(i, dice, turn);
        break;
    case 5:
        life5(i, dice, turn);
        break;
    case 6:
        life6(i, dice, turn);
        break;
    }
    return 0;
}
//人生をランダムで決める
//配列life[]に, 1~6が並び替えで入る
void select_life(void){
    // 配列に0から5までの数字を重複なくランダムに格納
    for (int i = 0; i < 6; i++) {
        int num;
        do {
            srand(time(NULL)); // 乱数生成器の初期化
            num = rand() % 6 + 1; // 0から5までの乱数生成
        } while (life[num] != -1 || num == i); // 既に使われた数字か自分の書いた人生なら再抽選

        life[num] = i; // 数字を配列に格納
    }
}
