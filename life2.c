#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "life.h"


//この人生に選ばれたプレイヤーが何人目か
int PlayerIndex = -1;

char lod1_name[];
char lod2_name[];
char friend1_name[];
char friend2_name[];

//7年目のじゃんけんゲームで用いる関数、変数の宣言
int generateComputerChoice();
void determineWinner(int playerChoice, int computerChoice);
int playerChoice, computerChoice;

// 5年目の魚釣りバトルでプレイヤーと友達が釣った魚の数をランダムに決定する
srand(time(NULL));
int playerCatch1;
playerCatch1 = rand() % 10;
srand(time(NULL));
int friendCatch1;
friendCatch1 = rand() % 10;

//13年目(select12 == 2)の魚釣りバトルでプレイヤーと友達が釣った魚の数をランダムに決定する
srand(time(NULL));
int playerCatch2;
playerCatch2 = rand() % 10;
srand(time(NULL));
int friendCatch2;
friendCatch2 = rand() % 10;

//17年目(select12 == 1 || select16 == 1)での魚釣りバトルでライバルが釣った魚の数をランダムに決定する
srand(time(NULL));
int playerCatch3;
playerCatch3 = rand() % 30;
srand(time(NULL));
int friendCatch3;
friendCatch3 = rand() % 30;

//19年目で釣った魚の数
srand(time(NULL));
int playerCatch4;
playerCatch4 = rand() % 50;

//20年目で釣る魚の数
srand(time(NULL));
int playerCatch5;
playerCatch5 = rand() % 50;
srand(time(NULL));
int friendCatch5;
friendCatch5 = rand() % 25;

//17年目におけるテストの点数
srand(time(NULL));
int score;
score = rand() % 101;

//各ターンにおける定数の設定
//ターンごとに別々の変数を用い，各ターンの関数で用いる
char turn1_word[6][100]={};
int turn1_exp = 0;
int turn2_exp = 5;
char turn3_word[6][100]={};
int turn3_exp[6] = {0};
int turn7_times = 0;
int turn8_times;
char turn9_word[6][100]={};
int turn9_exp[6] = {0};
int turn10_exp[6] = {0};
char turn11_word[6][100] = {};
int turn11_exp[6] = {0};
char turn13_word[6][100]={};
int turn13_exp[6] = {0};
char turn16_word[6][100] = {};
char turn18_word[6][100] = {};

//12年目における進路選択
int select12;

//15年目における選択
int select15;

//17年目における選択
int select17;

int life2_1(int dice);
int life2_2(int dice);
int life2_3(int dice);
int life2_4(int dice);
int life2_5(int dice);
int life2_6(int dice);
int life2_7(int dice);
int life2_8(int dice);
int life2_9(int dice);
int life2_10(int dice);
int life2_11(int dice);
int life2_12(int dice);
int life2_13(int dice);
int life2_14(int dice);
int life2_15(int dice);
int life2_16(int dice);
int life2_17(int dice);
int life2_18(int dice);
int life2_19(int dice);
int life2_20(int dice);



void InputLife1(void){
    //1年目
    printf("ターン1の設定.\n");
    printf("1ターン目で喋る言葉を書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn1_word[dice-1]);
    }
    printf("1ターン目で増える経験値を, -10~10の範囲で設定してください. : ");
    scanf("%d",&turn1_exp);

    //2年目
    printf("ターン2の設定.\n");
    printf("2年目は何も起こらないので設定不要.\n");

    //3年目
    printf("ターン3の設定.\n");
    printf("3年目で釣る魚を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn3_word[dice-1]);
    }
    printf("3年目で増える経験値を, -10~10の範囲で, サイコロの目ごとに決めてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%d", &turn3_exp[dice-1]);
    }


    //4~6年目の人生を設計する

    //4年目
    printf("4年目の設定.\n");
    printf("愛用する釣竿の名前を入力してください.\n");
    scanf("%d", &lod1_name);

    //5年目
    printf("5年目の設定.\n");
    printf("5年目で出会う友達の名前を入力してください.\n");
    scanf("%s", friend1_name);

    //6年目
    printf("6年目の設定.\n");
    printf("6年目の設定は不要.\n");

    //7年目
    printf("ターン7の設定.\n");
    printf("7年目の設定は不要.\n");
    
    //8年目
    printf("ターン8の設定.\n");
    printf("8年目に起こる全体ミニゲームで得られる点数の倍率を, -10~10の範囲で設定してください.\n");
    scanf("%d", &turn8_times);

    //9年目
    printf("ターン9の設定.\n");
    printf("9年目で釣る魚を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn9_word[dice-1]);
    }
    printf("9年目で増える経験値を, -10~10の範囲で, サイコロの目ごとに決めてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%d", &turn9_exp[dice-1]);
    }

    //10年目
    printf("10年目の設定.\n");
    printf("10年目で増える経験値を, -10~10の範囲で, サイコロの目ごとに決めてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%d", &turn10_exp[dice-1]);
    }

    //11年目
    printf("11年目の設定.\n");
    printf("11年目で旅行に行く場所を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn3_word[dice-1]);
    }
    printf("11年目で増える経験値を, -10~10の範囲で, サイコロの目ごとに決めてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%d", &turn11_exp[dice-1]);
    }


    //12年目
    printf("12年目の設定.\n");
    printf("12年目での進路選択\n");
    printf("1:漁師の見習いとして働く\n 2:中学校に進学\n");
    scanf("%d", &select12);

    //13年目
    printf("13年目の設定.\n");
        printf("13年目で釣る魚を, サイコロの目ごとに書いてください.\n");
        for(int dice = 1; dice <= 6; dice++){
            printf("サイコロの目が%dの時: ", dice);
            scanf("%s", turn13_word[dice-1]);
        }
        printf("13年目で増える経験値を, -10~10の範囲で, サイコロの目ごとに決めてください.\n");
        for(int dice = 1; dice <= 6; dice++){
            printf("サイコロの目が%dの時: ", dice);
            scanf("%d", &turn13_exp[dice-1]);
        };


    //14年目
    printf("14年目の設定.\n");
    printf("14年目の設定は不要.\n");    

    //15年目
    printf("15年目の設定.\n");
    printf("15年目で新しく手に入れる釣竿の名前を決めてください:");
    scanf("%s", lod2_name);
       
    //16年目
    printf("16年目の設定.\n");
    printf("16年目で新たに出会う友達の名前を決めてください.\n");
    scanf("%s", friend2_name);
        
    printf("16年目で入部する部活を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn16_word[dice-1]);
    }

    //17年目
    printf("17年目の設定.\n");
    printf("17年目の設定は不要.\n");

    //18年目
    printf("18年目の設定.\n");
        printf("18年目で行く海外の国名を サイコロの目ごとに書いてください.\n");
        for(int dice = 1; dice <= 6; dice++){
            printf("サイコロの目が%dの時: ", dice);
            scanf("%s", turn18_word[dice-1]);
        }
        
    //19年目
    printf("19年目の設定.\n");
    printf("19年目の設定は不要.\n");

    //20年目
    printf("20年目の設定.\n");
    printf("20年目の設定は不要.\n");



int life2(int i, int dice, int turn) {
    PlayerIndex = i;
    switch (turn) {
        case 1:
            life2_1(dice);
            break;
        case 2:
            life2_2(dice);
            break;
        case 3:
            life2_3(dice);
            break;
        case 4:
            life2_4(dice);
            break;
        case 5:
            life2_5(dice);
            break;
        case 6:
            life2_6(dice);
            break;
        case 7:
            life2_7(dice);
            break;
        case 8:
            life2_8(dice);
            break;
        case 9:
            life2_9(dice);
            break;
        case 10:
            life2_10(dice);
            break;
        case 11:
            life2_11(dice);
            break;
        case 12:
            life2_12(dice);
            break;
        case 13:
            life2_13(dice);
            break;
        case 14:
            life2_14(dice);
            break;
        case 15:
            life2_15(dice);
            break;
        case 16:
            life2_16(dice);
            break;
        case 17:
            life2_17(dice);
            break;
        case 18:
            life2_18(dice);
            break;
        case 19:
            life2_19(dice);
            break;
        case 20:
            life2_20(dice);
            break;
        default:
            break;
    
    }
    return 0;
}

// life 関数の定義
int life2_1(int dice) {//1年目の人生
    printf("初めて喋った！！\n");
    getchar();
    printf("「");
    printf("%s", turn1_word[dice-1]);
    printf("」!!!\n");
    printf("%s, 流石は漁師の息子\n", player[i]);
    getchar();
    printf("新しい言葉を覚えたので経験値%dアップ!\n", turn1_exp);
    expv[i] += turn1_exp;
    printf("経験値：%d", expv[i]);
    getchar();
    return 0;
}

int life2_2(int dice) {
    printf("近所では、期待の星!\n");
    getchar();
    printf("経験値%dアップ!\n", turn2_exp);
    expv[PlayerIndex] += turn2_exp;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
}

int lif2_3(int dice) {
    printf("イベント発生！！\n");
    getchar();
    printf("初めて魚釣りに挑戦！釣った魚は...");
    printf("%s\n", turn3_word[dice-1]);
    getchar();
    printf("初めて魚を釣ったので、経験値%dアップ!\n", turn3_exp[dice-1]);
    expv[i] += turn3_exp[i];
    printf("経験値：%d", expv[i]);
    getchar();
    return 0;
}

int life2_4(int dice) {
    printf("初めて釣竿を買ってもらった\n");
    printf("釣竿に名前を付けた!その名前は?\n");
    getchar();
    printf("%s\n", lod1_name);
    getchar();
    return 0;
}

int life2_5(int dice) {
    srand(time(NULL));
    int playerCatch1 = rand() % 10;
    int friendCatch1 = rand() % 10;
    printf("友達と釣りバトル!\n");
    getchar();
    printf("%d : 「どっちが多くの魚を釣れるか勝負だ!」\n", friend1_name);
    getchar();
    printf("~集中する2人~\n");
    printf("結果は?!");
    printf("プレイヤーが釣った魚の数: %d\n", playerCatch1);
    printf("友達が釣った魚の数: %d\n", friendCatch1);

    if (playerCatch1 > friendCatch1) {
        printf("プレイヤーの勝利！\n");
        printf("やったー!\n");
        printf("経験値20アップ.\n");
        expv[i] += 20;
        printf("経験値：%d", expv[i]);

    } else if (playerCatch1 < friendCatch1) {
        printf("友達の勝利！\n");
        printf("悔しい\n");
        printf("経験値10アップ.\n");
        expv[i] += 10;
        printf("経験値：%d", expv[i]);

    } else {
        printf("引き分け！\n");
        printf("両者の実力は互角.\n");
         printf("経験値15アップ.\n");
        expv[i] += 15;
        printf("経験値：%d", expv[i]);

    }

    return 0;
}

int life2_6(int dice) {
    printf("成長中!\n");
    getchar();
    return 0;
}

int life2_7(int dice) {
    srand(time(NULL));
    printf("小学校に入学!\n");
    printf("友達とじゃんけん.\n");
    printf("じゃんけんゲームを始めます！\n");
    printf("1: グー\n");
    printf("2: チョキ\n");
    printf("3: パー\n");
    printf("選択してください（1-3）: ");
    scanf("%d", &playerChoice);

    // プレイヤーの選択を表示
    switch (playerChoice) {
        case 1:
            printf("あなたの選択: グー\n");
            break;
        case 2:
            printf("あなたの選択: チョキ\n");
            break;
        case 3:
            printf("あなたの選択: パー\n");
            break;
        default:
            printf("無効な選択です。\n");
            return 1;
    }

    // コンピュータの選択を生成
    computerChoice = generateComputerChoice();

    // コンピュータの選択を表示
    switch (computerChoice) {
        case 1:
            printf("コンピュータの選択: グー\n");
            break;
        case 2:
            printf("コンピュータの選択: チョキ\n");
            break;
        case 3:
            printf("コンピュータの選択: パー\n");
            break;
    }

    // 勝者を判定
    determineWinner(playerChoice, computerChoice);

    return 0;
}

int life2_8(int dice) {
    printf("プレイヤー横断イベント発生!!\n");
    getchar();
    All_minigame();
    getchar();
    return 0;
}

int life2_9(int dice) {
    printf("父の漁船に初めて乗った！ そこで釣れた魚は？\n");
    getchar();
    printf("%c\n",turn9_word);
    getchar();
    printf("経験値%dアップ!\n", turn9_exp[dice-1]);
    expv[i] += turn9_exp[i];
    printf("経験値：%d", expv[i]);
    getchar();
    printf("初めて魚を釣ったので、経験値%dアップ!\n", turn9_exp[dice-1]);
    expv[i] += turn9_exp[i];
    printf("経験値：%d", expv[i]);
    getchar();
    return 0;
}

int life2_10(int dice) {
    printf("実家の魚屋のお手伝いをした!n");
    getchar();
    printf("経験値%dアップ!\n, turn10_exp[dice-1]");
    expv[i] += turn10_exp[i];
    printf("経験値：%d", expv[i]);
    getchar();
    return 0;
}

int life2_11(int dice) {
    printf("家族で旅行に出かけることに! 旅行の行先は?!\n");
    getchar();
    printf("%s\n", turn11_word[dice-1]);
    getchar();
    printf("旅行を楽しんだ!経験値%dアップ!", turn11_exp[dice-1]);
    expv[i] += turn11_exp[i];
    printf("経験値：%d", expv[i]);
    getchar();
    return 0;
}

int life2_12(int dice) {
    printf("進路選択を迫られた!");
    if(select12 == 1){
        printf("あなたは漁師の見習いとして働くことになった!\n");
    }else if(select12 == 2){
        printf("あなたは中学校に進学することになった!\n");
    }
    return 0;
}

int life2_13(int dice) {
    if(select12 ==1){
        printf("漁船に帯同した\n");
        printf("そこで得た魚は?!\n");
        getchar();
        printf("%d!", turn13_word[dice-1]);
        getchar();
    }else if(select12 == 2){
        srand(time(NULL));
        int playerCatch2 = rand() % 10;
        int friendCatch2 = rand() % 10;
        printf("中学校に入学した!");
        getchar();
        printf("再び%sとの釣り勝負!\n", friend1_name);
        printf("~集中する2人~\n");
        printf("結果は?!");

        printf("プレイヤーが釣った魚の数: %d\n", playerCatch2);
        printf("友達が釣った魚の数: %d\n", friendCatch2);

        if (playerCatch2 > friendCatch2) {
        printf("プレイヤーの勝利！\n");
        printf("やったー!\n");
        printf("経験値20アップ.\n");
        expv[i] += 20;
        printf("経験値：%d", expv[i]);

    } else if (playerCatch2 < friendCatch2) {
        printf("友達の勝利！\n");
        printf("悔しい\n");
        printf("経験値10アップ.\n");
        expv[i] += 10;
        printf("経験値：%d", expv[i]);

    } else {
        printf("引き分け！\n");
        printf("両者の実力は互角.\n");
        printf("経験値15アップ.\n");
        expv[i] += 15;
        printf("経験値：%d", expv[i]);

    }
        }
    return 0;
}

int life2_14(int dice) {
    if(select12 == 1){
        printf("漁師として修業の日々");
        printf("経験値10アップ\n");
        expv[i] += 10;
        printf("経験値：%d", expv[i]);
    }else if(select12 == 2){
        printf("学業が忙しい\n");
        printf("経験値5アップ\n");
        expv[i] += 5;
        printf("経験値：%d", expv[i]);
    }
    
    return 0;
}

int life2_15(int dice) {
    if(select12 == 1){
      getchar();
      printf("漁の途中で%dが壊れてしった.残念!\n", lod1_name);
      getchar();
      printf("新しい釣竿を手に入れた!\n");
      printf("その名は?!");
      getchar();
      printf("%d\n!!", lod2_name);
      getchar(); 
    }else if(select12 == 2){
      printf("再び進路選択\n");
      printf("以下の番号のいずれかを答えてください\n");
      printf("1:高校に進学\n2:漁師の道へ進む\n");
      scanf("%d\n", &select15);
    }

    return 0;

}

int life2_16(int dice) {
    if(select12 == 1 || select15 == 1){
        printf("新たなライバル登場!その名も?!\n");
        getchar();
        printf("%s!!", friend2_name);
        printf("%sに勝つために猛特訓!\n");
        getchar();
        printf("経験値10アップ\n");
        expv[i] += 10;
        printf("経験値：%d", expv[i]);
    }else{
        printf("高校で部活に入ることになった\n");
        printf("その部活は!?\n");
        getchar();
        printf("%s", turn16_word);
        getchar();
        printf("練習に励む日々!\n");
        printf("経験値5アップ\n");
        expv[i] += 5;
        printf("経験値：%d", expv[i]);
    }
    return 0;
}

int life2_17(int dice) {
    if(select12 == 1 || select15 == 1){
        srand(time(NULL));
        int playerCatch3 = rand() % 30;
        int friendCatch3 = rand() % 30;
        getchar();
        printf("ライバルの%sが勝負を仕掛けてきた!", friend2_name);
        getchar();
        printf("勝負を受けますか?\n");
        printf("1:受ける 2:受けない\n");
        scanf("%d\n", &select17);
        if(select17 == 1){
            getchar();
            printf("ライバル%sとの釣り勝負!\n", friend2_name);
            printf("~集中する2人~\n");
            printf("結果は?!");

            printf("プレイヤーが釣った魚の数: %d\n", playerCatch3);
            printf("友達が釣った魚の数: %d\n", friendCatch3);

            if (playerCatch3 > friendCatch3) {
                printf("プレイヤーの勝利！\n");
                printf("やったー!\n");
                printf("経験値20アップ.\n");
                expv[i] += 20;
                printf("経験値：%d", expv[i]);
            } else if (playerCatch3 < friendCatch3) {
                printf("友達の勝利！\n");
                printf("悔しい\n");
                printf("経験値10アップ.\n");
                expv[i] += 10;
                printf("経験値：%d", expv[i]);
            } else {
                printf("引き分け！\n");
                printf("両者の実力は互角.\n");
                printf("経験値15アップ.\n");
                expv[i] += 15;
                printf("経験値：%d", expv[i]);
            }
            }else{
                printf("勝負を避けるのは恥だ.\n");
                printf("経験値20ダウン.\n");
                expv[i] -= 20;
                printf("経験値：%d", expv[i]);
            }
        }else{
            srand(time(NULL));
            int score = rand() % 101;
            printf("定期テストが返却された!その点数は?!\n");
            getchar();
            printf("%d点!!\n", score);
            if(score >= 80){
                printf("やった、高得点だ!");
                printf("経験値15アップ.\n");
                expv[i] += 15;
                printf("経験値：%d", expv[i]);
            }else if(score >= 50 && score < 80){
                printf("まあまあだ\n");
                printf("経験値10アップ.\n");
                expv[i] += 10;
                printf("経験値：%d", expv[i]);
            }else{
                printf("残念!\n");
                printf("経験値5アップ.\n");
                expv[i] += 5;
                printf("経験値：%d", expv[i]);
            }
        }
    return 0;    
}

int life2_18(int dice) {
    if(select12 == 1 || select15 ==1){
        printf("海外に漁を手伝いにくことに\n");
        printf("その行先は?\n");
        getchar();
        printf("%s!\n", turn18_word);
        printf("とても良い経験だった!!\n");
        printf("経験値50アップ.\n");
        expv[i] += 50;
        printf("経験値：%d", expv[i]);
    }else{
        printf("大学受験のために勉強中!\n");
        printf("経験値25アップ.\n");
        expv[i] += 25;
        printf("経験値：%d", expv[i]);
    }
    return 0;
}

int life2_19(int dice) {
    if(select12 == 1 || select15 == 1){
        srand(time(NULL));
        int playerCatch4 = rand() % 50;
        printf("漁船に乗って魚を釣りに行くことに!");
        printf("釣れた魚の数は?!\n");
        printf("%d\n匹!", playerCatch4);
        if(playerCatch4 >= 35){
            printf("大漁だ!\n");
            printf("経験値50アップ.\n");
            expv[i] += 50;
            printf("経験値：%d", expv[i]);
        }else if (playerCatch4 >= 20 && playerCatch4 < 35){
            printf("まあまあだ.\n");
            printf("経験値30アップ.\n");
            expv[i] += 30;
            printf("経験値：%d", expv[i]);
        }else{
            printf("もう少し釣りたかった...\n");
            printf("経験値15アップ.\n");
            expv[i] += 15;
            printf("経験値：%d", expv[i]);
        }
    }else{
        printf("大学受験の結果は?!\n");
        printf("やったー! 横浜国立大学に入学した!\n");
        printf("経験値40アップ.\n");
        expv[i] += 40;
        printf("経験値：%d", expv[i]);
    }
    return 0;
}

int life2_20(int dice) {
    srand(time(NULL));
    int playerCatch5 = rand() % 50;
    int friendCatch5 = rand() % 25;
    getchar();
    printf("再び%sとの釣り勝負!\n", friend1_name);
    getchar();
    printf("これまでの集大成を見せるとき!\n");
    printf("~集中する2人~\n");
    printf("結果は?!");

    printf("プレイヤーが釣った魚の数: %d\n", playerCatch5);
    printf("友達が釣った魚の数: %d\n", friendCatch5);

    if (playerCatch5 > friendCatch5){
        printf("プレイヤーの勝利！\n");
        printf("やったー!\n");
        printf("経験値100アップ.\n");
        expv[i] += 100;
        printf("経験値：%d", expv[i]);
    } else if (playerCatch5 < friendCatch5) {
        printf("友達の勝利！\n");
        printf("悔しい\n");
        printf("経験値30アップ.\n");
        expv[i] += 30;
        printf("経験値：%d", expv[i]);
    } else {
        printf("引き分け！\n");
        printf("両者の実力は互角.\n");
        printf("経験値50アップ.\n");
        expv[i] += 50;
        printf("経験値：%d", expv[i]);
    }

    getchar();
    printf("%s 「成長したな」", friend1_name);
    printf("これまでの総経験値:%d\n", expy[i]);
    printf("～漁師としての人生はまだまだ続く～\n");

    return 0;
}

}

// コンピュータの選択を生成する関数
int generateComputerChoice() {
    return rand() % 3 + 1; // 1-3の乱数を生成
}

// 勝者を判定する関数
void determineWinner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) {
        printf("引き分けです！\n");
    } else if ((playerChoice == 1 && computerChoice == 2) ||
               (playerChoice == 2 && computerChoice == 3) ||
               (playerChoice == 3 && computerChoice == 1)) {
        printf("あなたの勝ちです！\n");
    } else {
        printf("コンピュータの勝ちです！\n");
    }
}
