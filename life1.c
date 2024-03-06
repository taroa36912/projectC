#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "life.h"

//この人生に選ばれたプレイヤーが何人目か
int PlayerIndex = -1;

char turn_word[20][6][100]={};
int turn18_hennsati[];

// life1 関数の宣言
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
    printf("このゲームでは経験値というシステムが採用されています。\n");
    getchar();
    printf("原則サイコロの目が大きいほど経験値が多くなります。\n");
    getchar();
    printf("そのことを踏まえてあなたにゲームのイベントを約20ターン設定してもらおうと思います。\n");
    getchar();
    //まず1年目の人生を設計する
    printf("ターン1の設定.\n");
    //ある程度のフォーマットは用意しておく. 各自，自分の作った人生のフォーマットに合わせればよい.
    printf("1ターン目で喋る言葉を書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時(経験値+%d(以降同様)): ", dice, 10*dice);
        scanf("%s", turn_word[1][dice-1]);//%sは，&がいらない
    }
    //printf("1ターン目で増える経験値を, -10~10の範囲で設定してください. : ");
    //scanf("%d",&turn1_exp);//%dは，&が必要


    //2年目の人生を設計する
    printf("ターン2の設定.\n");
    printf("初めてのお絵描きで何を描いたかを書いてください。\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時(経験値+%d): ", dice,10*dice);
        scanf("%s", turn_word[2][dice-1]);//%sは，&がいらない
    }
    printf("ターン3の設定.\n");
    printf("子供向けのイベントに参加し何をしたか, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice+=2){
        printf("サイコロの目が%dまたは%dの時: ", dice, dice+1);
        scanf("%s", turn_word[3][dice-1]);
        strcpy(turn_word[3][dice],turn_word[3][dice-1]);
    }
    printf("ターン4の設定.\n");
    printf("幼稚園の遠足で何をしたか, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice+=2){
        printf("サイコロの目が%dまたは%dの時: ", dice,dice+1);
        scanf("%s", turn_word[4][dice-1]);
        strcpy(turn_word[4][dice],turn_word[4][dice-1]);   
    }
    printf("ターン5の設定.\n");
    printf("始めた習い事を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn_word[5][dice-1]);
    }
    /*printf("ターン6の設定.\n");
    printf("6年目で起こる出来事を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn_word[6][dice-1]);
    }*/
    printf("ターン7の設定.\n");
    printf("小学校に入学してできた友達の特徴を教えてください。\n");
    for(int dice = 1; dice <= 6; dice+=2){
        printf("サイコロの目が%dまたは%dの時: ", dice, dice+1);
        scanf("%s", turn_word[7][dice-1]);
        strcpy(turn_word[7][dice],turn_word[7][dice-1]);
    }
    printf("ターン8の設定.\n");
    printf("できた友達とどう遊んだかを書いてください.\n");
    for(int dice = 1; dice <= 6; dice+=2){
        printf("サイコロの目が%dまたは%d,%sとの遊び: ", dice,dice+1,turn_word[7][dice-1]);
        scanf("%s", turn_word[8][dice-1]);
        strcpy(turn_word[8][dice],turn_word[8][dice-1]);
    }
    printf("ターン9の設定.\n");
    printf("学校でのイベントを, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice+=2){
        printf("サイコロの目が%dまたは%dの時: ", dice,dice+1);
        scanf("%s", turn_word[9][dice-1]);
        strcpy(turn_word[9][dice],turn_word[9][dice-1]);
    }
    printf("ターン10の設定.\n");
    printf("夏休みの自由研究でなにをつくったかを, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn_word[10][dice-1]);
    }
    printf("ターン11の設定.\n");
    printf("新たな興味分野を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn_word[11][dice-1]);
    }
    printf("ターン12の設定.\n");
    printf("中学受験にチャレンジ。どこ（どんな特徴の学校）に受かりましたか？\n");
    for(int dice = 3; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn_word[12][dice-1]);
    }
    printf("ターン13の設定.\n");
    printf("中学生になって入った部活を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn_word[13][dice-1]);
    }
    printf("ターン14の設定.\n");
    printf("部活で起きたイベントを, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%d,%sに入った時: ", dice,turn_word[13][dice-1]);
        scanf("%s", turn_word[14][dice-1]);
    }
    printf("ターン15の設定.\n");
    printf("勉強の出来を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice+=2){
        printf("サイコロの目が%dまたは%dの時: ", dice,dice+1);
        scanf("%s", turn_word[15][dice-1]);
        strcpy(turn_word[15][dice],turn_word[15][dice-1]);
    }
    printf("ターン16の設定.\n");
    printf("高校に入ってできる友人の特徴を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn_word[16][dice-1]);
    }
    /*printf("ターン17の設定.\n");
    printf("勉強の出来を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn_word[17][dice-1]);
    }*/
    printf("ターン18の設定.\n");
    printf("偏差値がどれだけ変化したかサイコロの目ごとに半角整数で書いてください（例：-10）\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%d", &turn18_hennsati[dice-1]);
    }
    printf("受験勉強の結果を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%d,偏差値増減%dの時: ", dice, turn18_hennsati[dice-1]);
        scanf("%s", turn_word[18][dice-1]);
    }
    /*printf("ターン19の設定.\n");
    printf("19年目で起こる出来事を, サイコロの目ごとに書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn_word[19][dice-1]);
    }*/

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

//int turn(int);//この関数も不要です(main関数に同じものがあります)
//int dice;//この変数も不要です
//int exp = 0;//これは消して，expの部分は，expv[i]に書き直してください.

/*int turn(int i)
{
    getchar();
    printf("次は%d歳！\n", i);
    printf("Enterキーを押してサイコロを振ってください\n");
    getchar();
    srand(time(NULL));
}*/

int life1_1(int dice){
    //turn(1);                            // ターン開始セット
    //dice = rand() % 6 + 1;              // ターン開始セット
    //printf("サイコロの目：%d\n", dice); // ターン開始セット
    getchar();
    printf("初めてことばを喋った！その言葉は...\n");
    getchar();
    // 文字列の配列
    //char *word_list[] = {"One", "Two", "Three", "Four", "Five", "Six"};
    // 対応する文字列を取得
    //char *word = word_list[dice - 1];
    // 結果の出力;
    printf("「%s」！！！\n", turn_word[1][dice-1]);
    getchar();
    printf("なんでその言葉なのかはわかりませんが、とにかく可愛すぎます！%sちゃん！！\n", player[PlayerIndex]);
    getchar();
    printf("新しい言葉を覚えたので経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
}

int life1_2(int dice){
    //turn(2);                            // ターン開始セット
    //dice = rand() % 6 + 1;              // ターン開始セット
    //printf("サイコロの目：%d\n", dice); // ターン開始セット
    getchar();                          // ターン開始セット
    printf("初めてのお絵描き。何を書いた？\n");
    getchar();
    printf("%s\n", turn_word[2][dice-1]);
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
    /*switch (dice)
    {
    case 1:
    case 2:
        printf("初めてのハイハイ！経験値+15\n");
        expv[i] += 15;
        break;
    case 3:
    case 4:
        printf("恐竜のおもちゃを発見！興味津々。経験値+10\n");
        expv[i] += 10;
        break;
    case 5:
    case 6:
        printf("お誕生日おめでとう！ケーキでお祝い。経験値+5");
        expv[i] += 5;
        break;
    return 0;
    }*/
}

int life1_3(int dice){
    /*turn(3);
    dice = rand() % 6 + 1;
    printf("サイコロの目：%d\n", dice);*/
    getchar();
    printf("%s",turn_word[3][dice-1]);
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
    /*switch (dice)
    {
    case 1:
    case 2:
        printf("博物館で恐竜の声を真似！経験値+20\n");
        expv[i] += 20;
        break;
    case 3:
    case 4:
        printf("お気に入りの恐竜の絵本を見つけた。夢中で読む。経験値+10\n");
        expv[i] += 10;
        break;
    case 5:
    case 6:
        printf("恐竜のおもちゃを壊しちゃった…新しいおもちゃを買ってもらう。経験値+5\n");
        expv[i] += 5;
        break;
    return  0;
    }*/
}

int life1_4(int dice){
    getchar();
    printf("%s",turn_word[4][dice-1]);
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
    /*switch (dice)
    {
    case 1:
        printf("ティラノサウルス！かっこいい。経験値+30\n");
        expv[i] += 30;
        break;
    case 2:
        printf("トリケラトプス！経験値+15\n");
        expv[i] += 15;
        break;
    case 3:
        printf("ステゴサウルス！経験値+15\n");
        expv[i] += 15;
        break;
    case 4:
        printf("アンキロサウルス！硬そう。経験値+25\n");
        expv[i] += 25;
        break;
    case 5:
        printf("ブラキオサウルス！でかい！経験値+30\n");
        expv[i] += 30;
        break;
    case 6:
        printf("プテラノドン！経験値+15\n");
        expv[i] += 15;
        break;
    }*/
}

int life1_5(int dice){
    getchar();
    printf("%s",turn_word[5][dice-1]);
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
    /*switch (dice)
    {
    case 1:
    case 2:
        printf("博物館の特別イベント参加！経験値+15\n");
        expv[i] += 15;
        break;
    case 3:
    case 4:
        printf("博物館のスタッフとして1日お手伝い!感謝される。経験値+20\n");
        expv[i] += 20;
        break;
    case 5:
    case 6:
        printf("博物館の裏方を見せてもらう。興味津々！経験値+15\n");
        expv[i] += 15;
        break;
    }*/
}

int life1_6(int dice){
    getchar();
    minigame();
    getchar();
    printf("経験値%dアップ！\n",30*minigame());
    expv[PlayerIndex] += 30*minigame();
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
    /*turn(6);
    dice = rand() % 6 + 1;
    printf("サイコロの目：%d\n", dice);
    getchar();
    switch (dice)
    {
    case 1:
    case 2:
        printf("博物館の学習イベントに参加！知識が広がり、経験値+20\n");
        expv[i] += 20;
        break;
    case 3:
    case 4:
        printf("恐竜学者にインタビュー！貴重なアドバイスで経験値+30\n");
        expv[i] += 30;
        break;
    case 5:
    case 6:
        printf("博物館の展示物の解説を披露！素晴らしい説明で経験値+40\n");
        expv[i] += 40;
        break;
    }*/
}

int life1_friend;
int life1_7(int dice){
    printf("小学校に入学！できた友達は…\n");
    getchar();
    printf("%s",turn_word[7][dice-1]);
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    life1_friend = dice;
    return 0;
    /*switch (dice)
    {
    case 1:
        printf("同じ恐竜オタクな友達\n");
        break;
    case 2:
        printf("アクティブな友達\n");
        break;
    case 3:
        printf("科学者志望の天才少年\n");
        break;
    case 4:
        printf("芸術の才能を持つ友達\n");
        break;
    case 5:
        printf("イギリス人の友達\n");
        break;
    case 6:
        printf("未知のものへの好奇心旺盛な友達\n");
        break;
    }*/
}

int life1_8(int dice){
    getchar();
    printf("友達と一緒に遊ぶ。何をしようか…\n");
    getchar();
    dice = life1_friend;
    printf("%s",turn_word[8][dice-1]);
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
    /*switch (friend)
    {
    case 1:
        printf("恐竜クイズでバトルする。経験値+20\n");
        expv[i] += 20;
        break;
    case 2:
        printf("一緒にサッカーをする。経験値+25\n");
        expv[i] += 25;
        break;
    case 3:
        printf("友達の研究を見せてもらう。経験値+30\n");
        expv[i] += 30;
        break;
    case 4:
        printf("博物館の子供向けイベントにアートを取り入れた企画を提案。\nプロジェクトを進め、博物館イベントを盛り上げる。経験値+30\n");
        expv[i] += 30;
        break;
    case 5:
        printf("英語がペラペラになる。経験値+35\n");
        expv[i] += 35;
        break;
    case 6:
        printf("一緒に学校の近くの山を探検をする。経験値+25\n");
        expv[i] += 25;
        break;
    }*/
}

int life1_9(int dice){
    getchar();
    printf("学校でのイベント。\n");
    getchar();
    printf("%s",turn_word[9][dice-1]);
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
    /*switch (dice)
    {
    case 1:
    case 2:
        printf("博物館の子供向けイベントの企画に参加！みんなで楽しむ。経験値+20\n");
        expv[i] += 20;
        break;
    case 3:
    case 4:
        printf("学校のクラス代表に選ばれる！責任感で経験値+35\n");
        expv[i] += 35;
        break;
    case 5:
    case 6:
        printf("友達との冒険旅行！経験値+35\n");
        expv[i] += 35;
        break;
    }*/
}

int life1_10(int dice){    
    getchar();
    printf("夏休みの自由研究、何をした？\n");
    getchar();
    printf("%s",turn_word[10][dice-1]);
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
    /*switch (dice)
    {
    case 1:
    case 2:
        printf("学校の近くで新たな化石発見！博物館に寄贈！経験値+50\n");
        expv[i] += 50;
        break;
    case 3:
    case 4:
        printf("博物館の未知の展示物を解明！謎に挑戦して経験値+45\n");
        expv[i] += 45;
        break;
    case 5:
    case 6:
        printf("学校のプロジェクトで優秀賞を獲得！自信を持てた。経験値+35\n");
        expv[i] += 35;
        break;
    }*/
}

int life1_11(int dice){
    //int interest;
    getchar();
    printf("新たな興味分野を見つけた。果たしてそれは…\n");
    getchar();
    printf("%s",turn_word[10][dice-1]);
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
    /*interest = dice % 3;
    switch (dice)
    {
    case 1:
    case 4:
        printf("宇宙分野\n");
        expv[i] += 0;
        break;
    case 2:
    case 5:
        printf("コンピューター\n");
        expv[i] += 0;
        break;
    case 3:
    case 6:
        printf("音楽\n");
        expv[i] += 0;
        break;
    }*/
}

int life1_school = 0;
int life1_12(int dice){
    getchar();
    printf("将来の目標のために中学受験することにした。その結果は…\n");
    getchar();
    if (dice  > 2)
    {
        printf("%sに合格！おめでとう！\n",turn_word[10][dice-1]);
    }
    else
    {
        printf("残念ながら不合格。挫折を味わった。経験値+30\n");
        expv[PlayerIndex] += 30;
        life1_school = 1;
    }
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
}

int life1_club;
int life1_13(int dice){
    getchar();
    printf("中学に入って部活を始めた。その部活とは…\n");
    getchar();
    printf("%s",turn_word[13][dice-1]);
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    life1_club = dice;
    return 0;
    /*club = dice % 3;
    switch (dice)
    {
    case 1:
    case 4:
        printf("地学部！化石採集に勤しむ！経験値+20\n");
        expv[i] += 20;
        break;
    case 2:
    case 5:
        printf("サッカー部！クラスの人気者に！\n");
        expv[i] += 25;
        break;
    case 3:
    case 6:
        printf("帰宅部！色々なことに興味を持って自由に学生生活を過ごす。\n");
        expv[i] += 20;
        break;
    }*/
}

int life1_14(int dice){
    getchar();
    dice = life1_club;
    printf("%s",turn_word[14][dice-1]);
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
    /*switch (club)
    {
    case 1:
        printf("探索するうちにシダの化石を発見！経験値+40\n");
        expv[i] += 40;
        break;
    case 2:
        printf("彼女と付き合って経験値+40\n");
        expv[i] += 40;
        break;
    case 0:
        printf("ゲームにはまる。経験値+20\n");
        expv[i] += 20;
        break;
    }*/
}

int life1_15(int dice){
    if (life1_school == 0)
    {
        getchar();
        printf("%s",turn_word[15][dice-1]);
        getchar();
        printf("経験値%dアップ！\n",10*dice);
        expv[PlayerIndex] += 10*dice;
        printf("経験値：%d", expv[PlayerIndex]);
        getchar();
        return 0;    
        /*switch (club)
        {
        case 1:
            printf("化石を発見したうわさが広まり、部員増加！経験値+20\n");
            expv[i] += 20;
            break;
        case 2:
            if (dice % 2 == 0)
            {
                printf("彼女と博物館デート。色々教えてあげた。経験値+35\n");
                expv[i] += 35;
            }
            else
            {
                printf("彼女と別れてしまう…。しかし、いい人生経験だった。経験値+20\n");
                expv[i] += 20;
            }
            break;
        case 0:
            if (dice % 2 == 0)
            {
                printf("ゲームの日本大会で準優勝！経験値+50\n");
                expv[i] += 50;
            }
            else
            {
                printf("ゲームにはまって学校をさぼりがちに…\n");
            }
            break;
        }*/
    }
    else
    {
        printf("高校受験をする。今度こそ頑張って将来のためよい高校に受かりたい。\n");
        getchar();
        switch (dice)
        {
        case 1:
        case 2:
        case 3:
            printf("第一志望は不合格だったが、なんとか第二志望に合格。経験値+30\n");
            expv[PlayerIndex] += 30;
            break;
        case 4:
        case 5:
        case 6:
            printf("頑張って地元有数の進学校に合格！経験値+60\n");
            expv[PlayerIndex] += 60;
            break;
        }
        return 0;
    }
}

int life1_16(int dice){
    getchar();
    printf("高校生活が始まりました。どんな友達ができたでしょうか？\n");
    getchar();
    printf("%s",turn_word[16][dice-1]);
    getchar();
    printf("経験値%dアップ！\n",10*dice);
    expv[PlayerIndex] += 10*dice;
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    return 0;
    //int highschool_friend;
    /*switch (dice)
    {
    case 1:
        printf("理系の友達と仲良くなる。\n");
        expv[i] += 20;
        break;
    case 2:
        printf("文系の友達。意外な一面を発見\n");
        highschool_friend = 2;
        break;
    case 3:
        printf("部活の仲間。共に頑張ろう！\n");
        highschool_friend = 3;
        break;
    case 4:
        printf("文化祭の準備で一緒に頑張る友達\n");
        highschool_friend = 4;
        break;
    case 5:
        printf("\n");
        highschool_friend = 0;
        break;
    case 6:
        printf("留学生の友達。国際交流が広がる\n");
        highschool_friend = 5;
        break;
    }*/
}

int life1_brain = 60;
int life1_17(int dice){
    getchar();
    printf("高校二年生。大学受験に向けた勉強を本格的に始める。\n");
    getchar();
    printf("ここでミニゲームで勉強の実力を測ろう\n");
    switch (Jyanken())
    {
    case 0:
        printf("ゲーム。勉強は一切やらず、偏差値は50になる。\n");
        life1_brain = 50;
        break;
    case 1:
        printf("兄に勉強したほうがいいと言われ、仕方なくやる。偏差値は10上がる。\n");
        life1_brain += 10;
        break;
    case 2:
        printf("高校数学の面白さに気づいてしまった。偏差値75。\n");
        life1_brain = 75;
        break;
    }
    getchar();
    return 0;
}

//int flag = 0;
int life1_18(int dice){
    getchar();
    printf("高校三年生。否が応にも勉強し、基礎学力がつく偏差値60未満の場合は60まで上がる。\n");
    if (life1_brain < 60)
    {
        life1_brain = 60;
    }
    printf("ここで模試が返ってきた。偏差値は%dのようだ！", life1_brain+turn18_hennsati[dice-1]);
    life1_brain += turn18_hennsati[dice-1];
    getchar();
    printf("とはいえ周りも頑張っている！もうここからは自分の才能だ！受験勉強の結果やいかに...\n");
    getchar();
    printf("%s",turn_word[18][dice-1]);
    getchar();
    printf("経験値増減%d！\n",turn18_hennsati[dice-1]);
    expv[PlayerIndex] += turn18_hennsati[dice-1];
    printf("経験値：%d", expv[PlayerIndex]);
    getchar();
    /*switch (dice)
    {
    case 1:
        printf("才能アリ。偏差値は爆上がりし、模試は全国10位。偏差値は80。東大を目指す。\n");
        brain = 80;
        flag = 1;
        break;
    case 2:
        printf("才能はそこそこ。地道な努力が報われ、偏差値は10上がった。\n");
        brain += 10;
        break;
    case 3:
        printf("才能はないようだ。偏差値は上がらず、むしろ下がる。偏差値-10\n");
        brain -= 10;
        break;
    case 4:
        printf("ストレスに耐え切れず、受験勉強をさぼる。偏差値-20\n");
        brain -= 20;
        break;
    case 5:
        printf("化石発掘にはまる。勉強？何それおいしいの？経験値は+20,偏差値は-20。\n");
        expv[i] += 20;
        brain -= 20;
        break;
    case 6:
        printf("受験どころか高校卒業が怪しい。受験を放棄し、趣味にはまる。偏差値は50\n");
        brain = 50;
        expv[i] += 20;
    }*/
    srand(time(NULL));
    int chance = rand() % 6;
    if (chance == 1 && life1_brain <= 60){
        getchar();
        printf("ここで挽回のチャンス！ミニゲームをしよう\n");
        getchar();
        int brainup;
        brainup = minigame()*20;
        life1_brain = life1_brain + brainup;
        getchar();
        if (brainup == 20){
            printf("おめでとう！偏差値が20アップした！\n");
        }else{
            printf("チャレンジ失敗。偏差値は変わらず…\n");
        }
    }
    return 0;
}
int geneki = 0;
int life1_19(int dice){
        getchar();
        printf("年が明け、そんなこんなあって横浜国立大学を受験。偏差値70以上なら合格だが...?\n");
        getchar();
        if (life1_brain >= 80)
        {
            printf("東大は不合格だったが、後期で横浜国立大学に合格、進学した。\n");
            printf("%sさん、横浜国立大学へご入学、おめでとうございます。\n", player[PlayerIndex]);
            getchar();
            printf("この大学には様々な経験を経て入学してきた人がいます。\n");
            getchar();
            printf("あなたの経験値は...\n");
            getchar();
            printf("%dです。\n人と比べる必要はありませんが、あなたは多くの貴重な体験をしてきました。", expv[PlayerIndex]);
            printf("これから先もいろいろな経験を積んでいきましょう。\n");
            //printf("The end\n");
        }
        else if(life1_brain < 70)
        {
            printf("偏差値は%dで残念ながら不合格！浪人しよう。\n", life1_brain);
            life1_brain += 10;
            geneki = 1;
        }else{   
            printf("偏差値は%dで晴れて合格！おめでとう、%s\n", life1_brain, player[PlayerIndex]);
            // エンディング
            printf("%sさん、横浜国立大学へご入学、おめでとうございます。\n", player[PlayerIndex]);
            getchar();
            printf("この大学には様々な経験を経て入学してきた人がいます。\n");
            getchar();
            printf("あなたの経験値は...\n");
            getchar();
            printf("%dです。\n人と比べる必要はありませんが、あなたは多くの貴重な体験をしてきました。", expv[PlayerIndex]);
            printf("これから先もいろいろな経験を積んでいきましょう。\n");
            //printf("The end\n");
    }
    return 0;
}

int life1_20(int dice){
    getchar();
    if (geneki == 0){
        printf("最後にミニゲームをします。\n");
        minigame();
        return 0;
    }else{
    printf("1年浪人し、横浜国立大学を再受験。偏差値70以上なら合格だが...?\n");
    if (life1_brain >= 70)
    {
        printf("偏差値は%dで晴れて合格！おめでとう、%s\n", life1_brain, player[PlayerIndex]);
        // エンディング
        printf("%sさん、横浜国立大学へご入学、おめでとうございます。\n", player[PlayerIndex]);
        getchar();
        printf("この大学には様々な経験を経て入学してきた人がいます。\n");
        getchar();
        printf("あなたの経験値は...\n");
        getchar();
        printf("%dです。\n人と比べる必要はありませんが、あなたは多くの貴重な体験をしてきました。", expv[PlayerIndex]);
        printf("これから先もいろいろな経験を積んでいきましょう。\n");
        printf("The end\n");
        return 0;
    }
    else
    {
        printf("偏差値は%dで残念ながら不合格！のはずだったが…\n", life1_brain);
        getchar();
        printf("繰り上げ合格した！\n");
        life1_brain += (10 + dice);
        expv[PlayerIndex] += 40;
        printf("晴れて合格！おめでとう、%s！\n", player[PlayerIndex]);
        // エンディング
        printf("%sさん、横浜国立大学へご入学、おめでとうございます。\n", player[PlayerIndex]);
        getchar();
        printf("この大学には様々な経験を経て入学してきた人がいます。\n");
        getchar();
        printf("あなたの経験値は...\n");
        getchar();
        printf("%dです。\n人と比べる必要はありませんが、あなたは多くの貴重な体験をしてきました。", expv[PlayerIndex]);
        printf("これから先もいろいろな経験を積んでいきましょう。\n");
        printf("The end\n");
        return 0;
    }
    }
}
// life1 関数の定義
/*int life1_1(int dice) {
    printf("Dinosaur 1\n");
    return 0;
}

int life1_2(int dice) {
    printf("Dinosaur 2\n");
    return 0;
}

int life1_3(int dice) {
    printf("Dinosaur 3\n");
    return 0;
}

int life1_4(int dice) {
    printf("Dinosaur 4\n");
    return 0;
}

int life1_5(int dice) {
    printf("Dinosaur 5\n");
    return 0;
}

int life1_6(int dice) {
    printf("Dinosaur 6\n");
    return 0;
}

int life1_7(int dice) {
    printf("Dinosaur 7\n");
    return 0;
}

int life1_8(int dice) {
    printf("Dinosaur 8\n");
    return 0;
}

int life1_9(int dice) {
    printf("Dinosaur 9\n");
    return 0;
}

int life1_10(int dice) {
    printf("Dinosaur 10\n");
    return 0;
}

int life1_11(int dice) {
    printf("Dinosaur 11\n");
    return 0;
}

int life1_12(int dice) {
    printf("Dinosaur 12\n");
    return 0;
}

int life1_13(int dice) {
    printf("Dinosaur 13\n");
    return 0;
}

int life1_14(int dice) {
    printf("Dinosaur 14\n");
    return 0;
}

int life1_15(int dice) {
    printf("Dinosaur 15\n");
    return 0;
}

int life1_16(int dice) {
    printf("Dinosaur 16\n");
    return 0;
}

int life1_17(int dice) {
    printf("Dinosaur 17\n");
    return 0;
}

int life1_18(int dice) {
    printf("Dinosaur 18\n");
    return 0;
}

int life1_19(int dice) {
    printf("Dinosaur 19\n");
    return 0;
}

int life1_20(int dice) {
    printf("Dinosaur 20\n");
    return 0;
}*/
