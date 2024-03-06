#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "life.h"

int PlayerIndex = -1;
char turn_word[20][6][100]={};

// 関数の宣言
int welthy_life_1(int dice);
int welthy_life_2(int dice);
int welthy_life_3(int dice);
int welthy_life_4(int dice);
int welthy_life_5(int dice);
int welthy_life_6(int dice);
int welthy_life_7(int dice);
int welthy_life_8(int dice);
int welthy_life_9(int dice);
int welthy_life_10(int dice);
int welthy_life_11(int dice);
int welthy_life_12(int dice);
int welthy_life_13(int dice);
int welthy_life_14(int dice);
int welthy_life_15(int dice);
int welthy_life_16(int dice);
int welthy_life_17(int dice);
int welthy_life_18(int dice);
int welthy_life_19(int dice);
int welthy_life_20(int dice);

void input_life5(void){
    //まず1年目の人生を設計する
    printf("ターン1(1歳)の設定.\n");
    //ある程度のフォーマットは用意しておく. 各自，自分の作った人生のフォーマットに合わせればよい.
    printf("初めて喋った言葉は?6つ候補を書いてください(例：あぶらみ)\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[0][dice-1]);//%sは，&がいらない
    }
    //2年目の人生を設計する
    printf("ターン2(2歳)の設定.\n");
    printf("近所を散歩中にハプニング発生！\nそのハプニングとは??6つ書こう！(例：カラスにつつかれた！)\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[1][dice-1]);
    }
    //3年目の人生を設計する
    printf("ターン3(3歳)の設定.\n");
    printf("幼稚園に入学！仲良くなった友達の特徴を書こう!(例：超お金持ちの真奈美ちゃん)\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%d人目: ", dice);
        scanf("%s", turn_word[2][dice-1]);
    }
    //4年目の人生を設計する
    printf("ターン4(4歳)の設定.\n");
    printf("年中さんになる.3歳で出会った友達との幼稚園の思い出を3つ書こう!(例：真奈美ちゃんとけっこんしきをした)\n");
    for(int dice = 1; dice <= 3; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[3][dice-1]);
        turn_word[3][dice + 2] = turn_word[3][dice-1];
    }
    //5年目の人生を設計する
    printf("ターン5(5歳)の設定.\n");
    printf("年長さんになり、じゃんけん遊びにはまる。このターンは設定は不要です。\n");

    //6年目の人生を設計する
    printf("ターン6(6歳)の設定.\n");
    printf("小学校に入学！小学校でのキャラは？言われたことある性格6つ書こう！\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[5][dice-1]);
    }
    //7年目の人生を設計する
    printf("ターン7(7歳)の設定.\n");
    printf("小学校二年生。球技大会で活躍する！どうやって？6つ書こう！\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[6][dice-1]);
    }
    //8年目の人生を設計する
    printf("ターン8(8歳)の設定.\n");
    printf("小学校三年生！遠足に行く。行き先を6つ書いてくれ！\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[7][dice-1]);
    }
    //9年目の人生を設計する
    printf("ターン9(9歳)の設定.\n");
    printf("小学校四年生！当時放課後は何して遊んでた？6つ書こう\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[8][dice-1]);
    }
    //10年目の人生を設計する
    printf("ターン10(10歳)の設定.\n");
    printf("二分の一成人式、ということで当時の将来の夢を書いてみよう！\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[9][dice-1]);
    }
    //11年目の人生を設計する
    printf("ターン11(11歳)の設定.\n");
    printf("小六。修学旅行で行ったところを3つ書こう！\n");
    for(int dice = 1; dice <= 3; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[10][dice-1]);
        turn_word[3][dice + 2] = turn_word[3][dice-1];
    }
    //12年目の人生を設計する
    printf("ターン12(12歳)の設定.\n");
    printf("中学生になり勉強が忙しくなる。中学校で取ったことのある学年順位は？高い順に書こう\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[11][dice-1]);
    }
    //13年目の人生を設計する
    printf("ターン13(13歳)の設定.\n");
    printf("中２．中二病という言葉もあるが、当時はまっていたものは？勉強でもいいぞ！\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[12][dice-1]);
    }
    //14年目の人生を設計する
    printf("ターン14(14歳)の設定.\n");
    printf("中三。受験。受験候補だった高校名を書こう。\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%d校目: ", dice);
        scanf("%s", turn_word[13][dice-1]);
    }
    //15年目の人生を設計する
    printf("ターン15(15歳)の設定.\n");
    printf("高校入学おめでとう！入った高校の特徴教えて！\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[14][dice-1]);
    }
    //16年目の人生を設計する
    printf("ターン16(16歳)の設定.\n");
    printf("高校二年生。バカの真骨頂。バカな思いで教えて！\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[15][dice-1]);
    }
    //17年目の人生を設計する
    printf("ターン17(17歳)の設定.\n");
    printf("高三。当時の志望校は？志望順に教えて！六つもなかったら予備校かなんか書いといて笑\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[16][dice-1]);
    }
    //18年目の人生を設計する
    printf("ターン18(18歳)の設定.\n");
    printf("ついに受験。得意順に科目書いてって！\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%d番目: ", dice);
        scanf("%s", turn_word[2][dice-1]);
    }
    //19年目の人生を設計する
    printf("ターン19(19歳)の設定.\n");
    printf("浪人する（してないかもやけど）。浪人時代の楽しみ6つ書いてみよう\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[2][dice-1]);
    }
    //20年目の人生を設計する
    printf("ターン20(20歳)の設定.\n");
    printf("晴れて名門横浜国立大学に入学！！おめでとう！横国でやりたい事６つ書いて！\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("%dつ目: ", dice);
        scanf("%s", turn_word[2][dice-1]);
    }
}

//ターンを認識
int life5(int i, int dice, int turn) {
    int PlayerIndex = i;
    switch (turn) {
    case 1:
        welthy_life_1(dice);
        break;
    case 2:
        welthy_life_2(dice);
        break;
    case 3:
        welthy_life_3(dice);
        break;
    case 4:
        welthy_life_4(dice);
        break;
    case 5:
        welthy_life_5(dice);
        break;
    case 6:
        welthy_life_6(dice);
        break;
    case 7:
        welthy_life_7(dice);
        break;
    case 8:
        welthy_life_8(dice);
        break;
    case 9:
        welthy_life_9(dice);
        break;
    case 10:
        welthy_life_10(dice);
        break;
    case 11:
        welthy_life_11(dice);
        break;
    case 12:
        welthy_life_12(dice);
        break;
    case 13:
        welthy_life_13(dice);
        break;
    case 14:
        welthy_life_14(dice);
        break;
    case 15:
        welthy_life_15(dice);
        break;
    case 16:
        welthy_life_16(dice);
        break;
    case 17:
        welthy_life_17(dice);
        break;
    case 18:
        welthy_life_18(dice);
        break;
    case 19:
        welthy_life_19(dice);
        break;
    case 20:
        welthy_life_20(dice);
        break;
    default:
        break;
    }

    return 0;
}

//各ターン
int welthy_life_1(int dice) {
    printf("初めて言葉をしゃべった!その言葉とは...?\n");
    getchar();
    printf("「%s」!!!!\n",turn_word[0][dice-1]);
    getchar();
    printf("なんでその言葉なのかはわかりませんが、とにかく可愛すぎます、%sちゃん!!経験値+10\n",player[PlayerIndex]);
    expv[4] += 10;
    return 0;
}

int welthy_life_2(int dice) {
    printf("散歩中にハプニング発生！何が起きた！？\n");
    getchar();
    printf("%s!!!!\n",turn_word[1][dice-1]);
    getchar();
    printf("ドンマイ!!でもいい経験になっただろう。経験値+%d\n",(dice-1)*10);
    expv[4] += (dice-1)*10
    return 0;
}

int welthy_life_3(int dice) {
    printf("幼稚園に入学！仲良くなった友達は…\n");
    getchar();
    printf("%s\n",turn_word[2][dice-1]);
    getchar();
    printf("いい友達ができてよかった！経験値+%d\n",(dice-1)*10);
    expv[4] += (dice-1)*10
    return 0;
}

int welthy_life_4(int dice) {
    printf("年中さんになる。%sさんとの幼稚園の思い出は？\n",turn_word[2][dice-1]);
    getchar();
    printf("%s\n",turn_word[3][dice-1]);
    getchar();
    printf("サイコーじゃないか！経験値+%d\n",(dice-1)*10);
    expv[4] += (dice-1)*10
    return 0;
}

int welthy_life_5(int dice) {
    printf("年長さんになり、じゃんけん遊びにはまる。じゃんけんで勝った回数だけ経験値を得る。\n");
    getchar();
    int tmp = Jyanken();
    getchar();
    printf("ナイストライだ、%s！経験値+%d\n",tmp);//実装する
    expv[4] += tmp;
    return 0;
}

int welthy_life_6(int dice) {
    printf("小学校に入学！小学校でのキャラは？\n");
    getchar();
    printf("%s\n",turn_word[5][dice-1]);
    getchar();
    printf("なるほど、そういう感じだったんだな、%s！経験値+%d\n",player[PlayerIndex],(dice-1)*10);
    expv[4] += (dice-1)*10
    return 0;
}

int welthy_life_7(int dice) {
    printf("小学校二年生。球技大会で活躍する！どうやって？\n");
    getchar();
    printf("%s\n",turn_word[6][dice-1]);
    getchar();
    printf("さすが！経験値+%d\n",(dice-1)*10);
    expv[4] += (dice-1)*10
    return 0;
}

int welthy_life_8(int dice) {
    printf("小学校三年生！遠足に行く。行き先は？\n");
    getchar();
    printf("%s\n",turn_word[7][dice-1]);
    getchar();
    printf("なるほど、やっぱローカルいいよな！経験値+%d\n",(dice-1)*10);
    expv[4] += (dice-1)*10
    return 0;
}

int welthy_life_9(int dice) {
    printf("小学校四年生！当時放課後は何して遊んでた？\n");
    getchar();
    printf("%s\n",turn_word[8][dice-1]);
    getchar();
    printf("だよな、みんなそんな感じだと思う、多分。経験値+%d\n",(dice-1)*10);
    expv[4] += (dice-1)*10
    return 0;
}

int welthy_life_10(int dice) {
    printf("二分の一成人式ということで、当時の夢を語ってもらいましょう。当時の夢は...\n");
    getchar();
    printf("%s\n",turn_word[9][dice-1]);
    getchar();
    printf("すばらしい！！！今もその夢、追いかけてるのかい？とにかく経験値+70だ！！\n");
    expv[4] += 70;
    return 0;
}

int welthy_life_11(int dice) {
    printf("小六。修学旅行ではどこ行った？\n");
    getchar();
    printf("%s\n",turn_word[10][dice-1]);
    getchar();
    printf("いいなー！うらやましいぜ。経験値+%d\n",(dice-1)*10);
    expv[4] += (dice-1)*10;
    return 0;
}

int welthy_life_12(int dice) {
    printf("中学生になり勉強が忙しくなる。当時取った学年順位を教えてくれ！\n");
    getchar();
    printf("%s\n",turn_word[11][dice-1]);
    getchar();
    printf("すげえな！さすが昔から優秀なんだな！経験値+%d\n",70-((dice-1)*10));
    expv[4] += 70-((dice-1)*10);
    return 0;
}

int welthy_life_13(int dice) {
    printf("中２。中二病という言葉もあるが、当時はまっていたものは？\n");
    getchar();
    printf("%s\n",turn_word[12][dice-1]);
    getchar();
    printf("なるほど。仲間はたくさんいるはずだ。頑張れ%s。経験値+%d\n",player[PlayerIndex],(dice-1)*10);
    expv[4] += (dice-1)*10;
    return 0;
}

int welthy_life_14(int dice) {
    printf("中三。受験。受験候補だった学校を一つ教えてくれ！\n");
    getchar();
    printf("%s\n",turn_word[13][dice-1]);
    getchar();
    printf("なるほど、名門っぽい名前だな...よくわからんけど。とにかく幸運を祈る！経験値+%d\n",(dice-1)*10);
    expv[4] += (dice-1)*10;
    return 0;
}

int welthy_life_15(int dice) {
    printf("高校入学おめでとう！入った高校の特徴は？\n");
    getchar();
    printf("%s\n",turn_word[14][dice-1]);
    getchar();
    printf("へえー！そんなところもあるのね！経験値+%d\n",(dice-1)*10);
    expv[4] += (dice-1)*10;
    return 0;
}

int welthy_life_16(int dice) {
    printf("高校二年生。思い出を教えてください！\n");
    getchar();
    printf("%s\n",turn_word[15][dice-1]);
    getchar();
    printf("うわー！バカですねえ～。経験値+%d\n",(dice-1)*10);
    expv[4] += (dice-1)*10;
    return 0;
}

int welthy_life_17(int dice) {
    printf("高三。当時の志望校を一個教えて！\n");
    getchar();
    printf("%s\n",turn_word[16][dice-1]);
    getchar();
    printf("なるほど。いいとこじゃないか。頑張れ%s。経験値+%d\n",player[PlayerIndex],70-((dice-1)*10));
    expv[4] += 70-((dice-1)*10);
    return 0;
}

int welthy_life_18(int dice) {
    printf("ついに受験本番だ！得意科目で差がつくといいが、果たしてどれで差がつくのか...\n");
     getchar();
    printf("%s\n",turn_word[17][dice-1]);
    getchar();
    if(dice <3){
        printf("割と得意な科目が来た！チャンス。経験値+%d\n",70-((dice-1)*10));
    }else{
        printf("やばい、苦手科目だ！踏ん張るしかない！経験値+%d\n",70-((dice-1)*10));
    }
    expv[4] += 70-((dice-1)*10);
    return 0;
}

int welthy_life_19(int dice) {
    printf("受験結果は振るわず浪人。浪人時代の思い出は？\n");
    getchar();
    printf("%s\n",turn_word[18][dice-1]);
    getchar();
    printf("おい！遊んでる場合か！経験値+%d\n",(dice-1)*10);
    expv[4] += (dice-1)*10;
    return 0;
}

int welthy_life_20(int dice) {
    printf("晴れて名門横浜国立大学に入学！！おめでとう！横国でやりたい事は？\n");
    getchar();
    printf("%s\n",turn_word[19][dice-1]);
    getchar();
    printf("すばらしい！これからの君の活躍を祈る！！経験値+%d\n",(dice-1)*10);
    expv[4] += (dice-1)*10;
    return 0;
}