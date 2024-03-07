#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "life.h"

int PlayerIndex = -1;
int win_number = 0;
char weapon[100];
int weapon_kinds;
int choice;
int lost_love = 0;
char group[100];
char success_4[100];
char failure_4[100];
char success_5[100];
char failure_5[100];
char situation[100];
char success_10[100];
char dream[100];
char lover[100];
char success_14[100];
char failure_14[100];
int measure;
int result;
int last_battle;
int last_result;
int life3_1(int dice);
int life3_2(int dice);
int life3_3(int dice);
int life3_4(int dice);
int life3_5(int dice);
int life3_6(int dice);
int life3_7(int dice);
int life3_8(int dice);
int life3_9(int dice);
int life3_10(int dice);
int life3_11(int dice);
int life3_12(int dice);
int life3_13(int dice);
int life3_14(int dice);
int life3_15(int dice);
int life3_16(int dice);
int life3_17(int dice);
int life3_18(int dice);
int life3_19(int dice);
int life3_20(int dice);
char turn1_word[6][100]={};
char turn2_word[6][100]={};
char turn3_word[100];
char turn4_word[100];
char turn5_word[100];
char turn6_word[6][100]={};
char turn7_word[6][100]={};
char turn8_word[6][100]={};
char turn9_word[100];
char turn10_word[100];
char turn11_word[100];
char turn12_word[100];
char turn13_word[100];
char turn14_word[100];
char turn15_word[100];
char turn16_word_a[100];
char turn16_word_b[100];
char turn17_word_a[100];
char turn17_word_b[100];
char turn18_word_a[100];
char turn18_word_b[100];
char turn19_word[100];
char turn20_word_a_w[100];
char turn20_word_a_l[100];
char turn20_word_b_w[100];
char turn20_word_b_l[100];

//あとで関数を設定しなおす
//またあとで設定しなおしたいのは、for文でのエラー対策。

void InputLife3(void){
    printf("このゲームでは経験値というシステムが採用されています.\n");
    getchar();
    printf("今回の場合、サイの目で貴方の経験値が決定しますので、ご留意ください.\n");
    getchar();
    printf("それでは貴方の人生を振り返りつつ、どうか楽しく人生を組み上げていってください\n");
    getchar();
    printf("ターン1を設定します.\n");
    printf("1ターン目でしゃべる言葉を書いてください.\n");
    for(int dice = 1; dice <= 6; dice++){
        printf("サイコロの目が%dの時: ", dice);
        scanf("%s", turn1_word[dice-1]);
    }
    
    printf("ターン2を設定します.\n");
    printf("ターン2で貴方の身に降りかかる災難や出来事を入力してください.\n");
    for(int dice = 1;dice <= 6;dice +=2){
        printf("サイコロの目が%dまたはそれ+1の目の時;",dice);
        scanf("%s",turn2_word[dice-2]);
        strcpy(turn2_word[dice-2],turn2_word[dice-1]);
    }
    printf("ターン3を設定します.\n");
    printf("ターン3で貴方が手に入れられる武器を考えて入力してください.\n");
    printf("ここでの武器は何でも構いません.\n");
    printf("人生は戦いだ！と覚悟を決めて、ペンを武器とし社会に抗うのも面白いでしょう.\n");
    scanf("%s",weapon);
    getchar();
    printf("その武器はどんな武器ですか？物理的な武器でないなら抽象的に近いなっと直感した解答で構いません。\n");
    printf("1:近接系2:遠距離系3:罠系\n");
    for(;;){
        scanf("%d",weapon_kinds);
        if(weapon_kinds==1||weapon_kinds==2||weapon_kinds==3){
            printf("正常な入力です。そのまま入力を続けてください\n");
            break;
        }
        else{
            printf("間違った入力です。再度、入力をお願いします。\n");
        }
    }
    printf("貴方はその武器を手に入れたことでどう思いましたか？\n");
    scanf("%s",turn3_word);
    
    printf("ターン4を設定します.\n");
    printf("ターン4では貴方は未来の戦闘に向けて準備します.\n");
    printf("貴方はどんな修行をしましたか？\n");
    scanf("%s",turn4_word);
    printf("修行の成果が良ければどんな成果が四歳で得られますか？\n");
    scanf("%s",success_4);
    printf("修行の成果が悪ければどんな苦しみが四歳の貴方に待っていますか？\n");
    scanf("%s",failure_4);
    
    printf("ターン5を設定します.\n");
    printf("ターン5では戦闘が発生します.\n");
    printf("貴方に立ちはだかった敵、もしくは苦難を入力してください。\n");
    scanf("%s",turn5_word);
    printf("もし戦闘に勝利すれば何が得られますか？\n");
    scanf("%s",success_5);
    printf("もし戦闘に敗北すれば何を失いますか？\n");
    scanf("%s",failure_5);
    
    printf("ターン6を設定します.\n");
    printf("ターン6では敵を打ち倒す、もしくは苦難を乗り越えた貴方に報酬が待っています.\n");
    printf("勝利できなくとも抗った報酬として何かを手にすることが出来ます.\n");
    printf("では、貴方が手に入れた報酬は何でしょうか？サイの目ごとに設定してください.\n");
    for(int dice = 1;dice <= 6;dice++){
        printf("サイコロの目が%dの時:",dice);
        scanf("%s",turn6_word);
    }
    
    printf("ターン7を設定します.\n");
    printf("ターン7では貴方は小学校や幼稚園、はたまた暗殺組織など、何らかの集団に属した状態で続きの人生が物語られます.\n");
    printf("貴方はどんな集団に属しましたか？\n");
    scanf("%s",group);
    printf("そこであり得そうなイベントを三つ入力してください");
    for(int dice = 1;dice <= 6;dice+=2){
        printf("貴方は%sにて:",group);
        scanf("%s",turn7_word[dice-2]);
        strcpy(turn7_word[dice-2],turn7_word[dice-1]);
    }

    printf("ターン8を設定します.\n");
    printf("貴方が属する集団の近況を教えてください\n");
    scanf("%s",situation);
    printf("どんなイベントが起きましたか？三つあり得そうなイベントを入力してください\n");
    for(int dice = 1;dice <= 6;dice+=2){
        printf("貴方は%sにて:",group);
        scanf("%s",turn8_word[dice-2]);
        strcpy(turn8_word[dice-2],turn8_word[dice-1]);
    }
    
    printf("ターン9を設定します.\n");
    printf("貴方はもうすぐ十歳になります。もう半分大人ですね.\n");
    printf("この歳になれば苦難の一つや二つ、降りかかってくるでしょう\n");
    printf("では貴方に立ちはだかった苦難は何でしょうか？\n");
    scanf("%s",turn9_word);
    
    printf("ターン10を設定します.\n");
    printf("貴方はこのターンで苦難と立ち向かい戦闘を行います。\n");
    printf("その苦難との戦いで何が起きますか？");
    scanf("%s",turn10_word);
    printf("もし勝利すれば何が得られますか？\n");
    scanf("%s",success_10);
    
    printf("ターン11を設定します.\n");
    printf("貴方はこのターンで将来の夢が決まってきます\n");
    printf("貴方が抱いた夢を教えてください。\n");
    scanf("%s",dream);
    printf("その夢をかなえるために今年どんな努力をしますか？\n");
    scanf("%s",turn11_word);
    
    printf("ターン12を設定します.\n");
    printf("貴方は将来の夢をかなえるため、努力を続けます。\n");
    printf("今年行う努力を教えてください\n");
    scanf("%s",turn12_word);
    
    printf("ターン13を設定します.\n");
    printf("歳の頃としては中学に上がった頃、貴方は気になる人が出来ました\n");
    printf("どんな人が気になり始めましたか？\n");
    scanf("%s",lover);
    printf("その子の気を惹くためにどんなことをしましたか？\n");
    scanf("%s",turn13_word);
    
    printf("ターン14を設定します.\n");
    printf("貴方は彼もしくは彼女、もしくは性別なしにアプローチをかけてみることにした\n");
    printf("どんな方法でアピールしましたか？\n");
    scanf("%s",turn14_word);
    printf("成功した時の心情を設定してください\n");
    scanf("%s",success_14);
    printf("失敗した時の心情を設定してください\n");
    scanf("%s",failure_14);
    
    printf("ターン15を設定します.\n");
    printf("夢を追うか、恋路に人生を懸けるか貴方は決断を迫られます.\n");
    printf("ただし、前のターンにて失恋していた場合、確定で夢を追います\n");
    getchar();
    printf("貴方はその決断をどう決めますか？\n");
    printf("以下の選択肢から選んでください\n");
    printf("1:自己選択2:経験値依存3:運\n");
    for(;;){
        scanf("%d",measure);
        if(measure==1||measure==2||measure==3){
            printf("正常な入力です。そのまま入力を続けてください\n");
            break;
        }
        else{
            printf("間違った入力です。再度、入力をお願いします。\n");
        }
    }
    
    printf("ターン16を設定します.\n");
    printf("恋路に人生を懸ける場合のイベントを入力します.\n");
    printf("貴方は恋人とデートに行きます。何処に行って、何をしましたか？\n");
    scanf("%s",turn16_word_a);
    printf("夢を追う場合のイベントを入力します\n");
    printf("貴方は夢に人生を懸ける為、何をしましたか？\n");
    scanf("%s",turn16_word_b);
    
    printf("ターン17を設定します.\n");
    printf("恋路に人生を懸ける場合のイベントを入力します.\n");
    printf("今日は貴方と恋人の特別な日です.どんな日ですか？\n");
    scanf("%s",turn17_word_a);
    printf("夢を追う場合のイベントを入力します.\n");
    printf("夢が叶う糸口が掴めました.\n");
    scanf("%s",turn17_word_b);
    
    
    printf("ターン18を設定します.\n");
    printf("恋路に人生を懸ける場合のイベントを入力します.\n");
    printf("貴方は恋人を特別なデートに誘いました.どこに行きましたか？\n");
    scanf("%s",turn18_word_a);
    printf("夢を追う場合のイベントを入力します.\n");
    printf("貴方は夢を叶えるための最後の障壁を乗り越えんとします\n");
    printf("その下準備として何をしますか？");
    scanf("%s",turn18_word_b);
    
    printf("ターン19を設定します.\n");
    printf("貴方の前に現れたのは最後の障害です。\n");
    printf("どんな障害が貴方の前に現れましたか？\n");
    scanf("%s",turn19_word);
    printf("その障害とどう戦いますか？");
    getchar();
    printf("1:運2:戦闘3:経験値\n");
    for(;;){
        scanf("%d",&last_battle);
        if(last_battle==1|last_battle==2|last_battle==3){
            printf("正常な入力です。そのまま入力を続けてください\n");
            break;
        }
        else{
            printf("間違った入力です。再度、入力をお願いします。\n");
        }
    }
    
    
    printf("ターン20（エンディング）を設定します.\n");
    printf("恋路に人生を懸ける場合、最後の障害との戦いに勝利した場合の結末を入力してください\n");
    scanf("%s",turn20_word_a_w);
    printf("恋路に人生を懸ける場合、最後の障害との戦いに敗北した場合の結末を入力してください\n");
    scanf("%s",turn20_word_a_l);
    printf("夢を追う場合、最後の障害との戦いに勝利した場合の結末を入力してください\n");
    scanf("%s",turn20_word_b_w);
    printf("夢を追う場合、最後の障害との戦いに敗北した場合の結末を入力してください\n");
    scanf("%s",turn20_word_b_l);

}



int life3(int i, int dice, int turn) {
    PlayerIndex = i;
    switch (turn) {
        case 1:
            life3_1(dice);
            break;
        case 2:
            life3_2(dice);
            break;
        case 3:
            life3_3(dice);
            break;
        case 4:
            life3_4(dice);
            break;
        case 5:
            life3_5(dice);
            break;
        case 6:
            life3_6(dice);
            break;
        case 7:
            life3_7(dice);
            break;
        case 8:
            life3_8(dice);
            break;
        case 9:
            life3_9(dice);
            break;
        case 10:
            life3_10(dice);
            break;
        case 11:
            life3_11(dice);
            break;
        case 12:
            life3_12(dice);
            break;
        case 13:
            life3_13(dice);
            break;
        case 14:
            life3_14(dice);
            break;
        case 15:
            life3_15(dice);
            break;
        case 16:
            life3_16(dice);
            break;
        case 17:
            life3_17(dice);
            break;
        case 18:
            life3_18(dice);
            break;
        case 19:
            life3_19(dice);
            break;
        case 20:
            life3_20(dice);
            break;
        default:
            break;
    }

    return 0;
}

int life3_1(int dice){
    printf("一ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("貴方は初めて言葉を発した！\n");
    getchar();
    printf("「");
    printf("%s",turn1_word[dice-1]);
    printf("」");
    expv[PlayerIndex] += 10 * (dice-1);
    printf("新たな言葉を覚え経験値%dアップ！\n",10*(dice-1));
    printf("経験値:%d",expv[PlayerIndex]);
    getchar();
    return 0;
}
int life3_2(int dice){
    printf("二ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("イベント発生！貴方の身に災難や幸福が降りかかる！\n");
    getchar();
    printf("%s",turn2_word[dice-1]);
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
    
}

int life3_3(int dice){
    printf("三ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("生とは辛く、苦しいものだ。どんな時代であっても武器を持たねば生きていけぬ\n");
    printf("貴方は武器を選んだ...その武器とは...\n");
    getchar();
    printf("貴方は%sを手に入れた！\n",weapon);
    getchar();
    printf("貴方:「%s」",turn3_word);
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}
int life3_4(int dice){
    printf("四ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("貴方が見据える未来にはきっと多くの苦難が待っている事だろう\n");
    printf("貴方は「%s」をした！\n",turn4_word);
    if (dice > 3){
        printf("貴方は修行に成功した！\n");
        getchar();
        printf("%sを得た！",success_4);
        getchar();
        printf("経験値+50！\n");
        expv[PlayerIndex] += 50;
    }
    else{
        printf("貴方は修行に失敗した...\n");
        getchar();
        printf("%sを失った...",failure_4);
        printf("経験値+0\n");
        getchar();
        expv[PlayerIndex] += 0;
    }
    getchar();
    return 0;
    //バトルをまだ設定していませんが、おそらくBattle関数は2が勝利、1が引き分け、0が敗北を返す事になると思います。
}
int life3_5(int dice){
    printf("五ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("困難が立ちはだかる...");
    getchar();
    printf("貴方の前に現れたのは%s！",turn5_word);
    if (weapon_kinds==1){
        printf("%sは近接系武器だった！おかげであっという間に勝利した！\n",weapon);
        getchar();
        printf("%sを得た！\n",success_5);
        printf("経験値+50！\n");
        expv[PlayerIndex] += 50;
    }
    else{
        result = Battle();
        if (result == 2){
          printf("貴方は%sを振るい、勝利した！経験値+50！\n",weapon);
          getchar();
          printf("%sを得た！\n",success_5);
          expv[PlayerIndex] += 50;
        }
        else{
        printf("貴方は困難を乗り越えることが出来なかった...経験値+0...\n");
        getchar();
        printf("%sを失った...経験値+0...。\n",failure_5);
        expv[PlayerIndex] += 0;
        }
    }
    getchar();
    return 0;
}

int life3_6(int dice){
    printf("六ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("貴方は困難に立ち向かった事で何かを得た！\n");
    printf("%sを得た！",turn6_word[dice-1]);
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}
int life3_7(int dice){
    printf("七ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("貴方は%sに入ることになった...",group);
    getchar();
    printf("貴方は%sにて、%sに遭遇した！",group,turn7_word[dice-1]);
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}
int life3_8(int dice){
    printf("八ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("貴方が属する%sでは%sが起きている\n",group,situation);
    getchar();
    printf("貴方は%sにて%sに遭遇した！\n",group,turn8_word[dice-1]);
    getchar();
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}
int life3_9(int dice){
    printf("九ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("%sが立ちはだかった...\n",turn9_word);
    getchar();
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}
int life3_10(int dice){
    printf("十ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("立ちはだかった%sとの戦闘だ。貴方は決心を決めて向かう。\n",turn9_word);
    printf("途中、%sが起きた！だが貴方は強かに起き上がり、再び立ち向かった！\n",turn10_word);
    getchar();
    result = Battle();
    if (weapon_kinds==2){
        printf("%sは遠距離系武器だった！おかげであっという間に勝利した！\n",weapon);
        getchar();
        printf("%sを得た！\n",success_10);
        printf("経験値+50！\n");
        expv[PlayerIndex] += 50;
    }
    else{
        result = Battle();
        if (result == 2){
          printf("貴方は%sを振るい、勝利した！経験値+50！\n",weapon);
          getchar();
          printf("%sを得た！\n",success_10);
          expv[PlayerIndex] += 50;
        }
        else{
        printf("貴方は困難を乗り越えることが出来なかった...経験値+0...\n");
        getchar();
        printf("何も手に入れることが出来なかった...経験値+0...。\n");
        expv[PlayerIndex] += 0;
        }
    }
    
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}
int life3_11(int dice){
    printf("十一ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("貴方:「将来、%sになりたいなぁ」\n",dream);
    getchar();
    printf("貴方:「そうと決まれば頑張らなくちゃ！」\n");
    getchar();
    printf("貴方は%sになる夢を叶えるため、%sをした！\n",dream,turn11_word);
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}
int life3_12(int dice){
    printf("十二ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("将来の夢:%sを叶えるため、貴方は引き続き努力を行う！\n");
    getchar();
    printf("今年行った努力は...:%sだった！\n",turn12_word);
    getchar();
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}
int life3_13(int dice){
    printf("十三ターン目です\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("歳の頃としては中学に上がってすぐ、貴方には気になる人が出来ました\n");
    getchar();
    printf("その人の名前は%sです。",lover);
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}
int life3_14(int dice){
    printf("十四ターン目です\n");
    printf("ダイスの値:%d",dice);
    printf("貴方は%sにアプローチをかけることにした",lover);
    getchar();
    printf("貴方が考えついたアプローチ法は:%sです",turn14_word);
    getchar();
    printf("早速トライしてみる...\n");
    getchar();
    if(dice > 3){
    printf("貴方の言葉は思い人に響かなかったようだ...\n");
    getchar();
    printf("貴方:「%s」",success_14);
    getchar();
    printf("失恋体験により経験値+25！\n");
    expv[PlayerIndex] += 25;
    lost_love += 1;
    }
    else{
    printf("貴方の言葉が思い人に響いた！\n");
    getchar();
    printf("貴方「%d」",failure_14);
    getchar();
    printf("成功体験により経験値+25！\n");
    expv[PlayerIndex] += 25;
    }
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}
int life3_15(int dice){
    printf("十五ターン目です。\n");
    printf("ダイスの値:%d",dice);
    getchar();
    printf("夢を追うか、恋路に人生を捧げるか、貴方は決断に迫られた。\n");
    getchar();
    if(lost_love==1){
        printf("貴方には恋人がいなかった。これで心置きなく夢:%sを追える\n",dream);
        choice = 2;
    }
    else{
        if(measure == 1){
            printf("%sを目指すなら2を%sとの恋路を歩むなら1を入力してください\n",dream,lover);
            scanf("%d",&choice);
            if(choice==2){
              printf("貴方は夢:%sを追うことを決意し、%sに別れを告げた。\n",dream,lover);
            }
            else if(choice==1){
                printf("貴方は%sと共に恋路を歩むことにした",lover);
            }
            }
        else if(measure==2){
            if(expv[PlayerIndex]>250){
                printf("貴方は夢:%sを追うことを決意し、%sに別れを告げた。\n",dream,lover);
                choice = 2;
            }
            else{
                printf("貴方は%sと共に恋路を歩むことにした\n",lover);
                choice = 1;
            }
        }
        else{
            if(dice > 3){
                printf("貴方は夢:%sを追うことを決意し、%sに別れを告げた。\n",dream,lover);
                choice = 2;
            }
            else{
                printf("貴方は%sと共に恋路を歩むことにした\n",lover);
                choice = 1;
            }
            
        }
    }
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}

int life3_16(int dice){
    printf("十六ターン目です\n");
    printf("ダイスの値:%d",dice);
    if(choice == 1){
        printf("恋路ルート\n");
        getchar();
        printf("貴方は%sとデートに行くことにした。\n",lover);
        getchar();
        printf("デートの内容:%s。\n",turn16_word_a);
    }
    else{
        printf("夢追いルート\n");
        getchar();
        printf("貴方は夢:%sを叶えるための努力をすることにした。\n",dream);
        getchar();
        printf("貴方がした努力:%s。\n",turn16_word_b);
    }
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}
int life3_17(int dice){
    printf("十七ターン目です\n");
    printf("ダイスの値:%d",dice);
    if(choice == 1){
        printf("恋路ルート\n");
        getchar();
        printf("今日は貴方と恋人の%s特別な日です。\n",lover);
        getchar();
        printf("なぜなら:%sの日だから。\n",turn17_word_a);
        printf("貴方は%sと%sを楽しみました",lover,turn17_word_a);
    }
    else{
        printf("夢追いルート\n");
        getchar();
        printf("貴方は夢:%sを叶えるための糸口を見つけた。\n",dream);
        getchar();
        printf("貴方が見つけた糸口:%s。\n",turn17_word_b);
    }
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}

int life3_18(int dice){
    printf("十八ターン目です\n");
    printf("ダイスの値:%d",dice);
    if(choice == 1){
        printf("恋路ルート\n");
        getchar();
        printf("今日は貴方と恋人の%s特別な日です。\n",lover);
        getchar();
        printf("なぜなら:%sの日だから。\n",turn18_word_a);
        getchar();
        printf("貴方は%sと%sを楽しみました",lover,turn18_word_a);
    }
    else{
        printf("夢追いルート\n");
        getchar();
        printf("貴方は夢:%sを叶えるための糸口を見つけた。\n",dream);
        getchar();
        printf("貴方が見つけた糸口:%s。\n",turn18_word_b);
    }
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}

int life3_19(int dice){
    printf("貴方の前に現れたのは最後の障害:%sだ。",turn19_word);
    getchar();
    printf("%sと貴方は相対し、最後の戦いが始まった。",turn19_word);
    getchar();
    if(last_battle==1){
        if(dice > 3){
            printf("貴方は%sに勝利した！",turn19_word);
            getchar();
            last_result = 1;
        }
        else{
            printf("貴方は%sに敗北した！",turn19_word);
            getchar();
            last_result = 2;
        }
    }
    else if(last_battle==2){
        result == Battle();
        if(result == 2){
            printf("貴方は%sに勝利した！\n",turn19_word);
            getchar();
            last_result = 1;
        }
        else{
            printf("貴方は%sに敗北した！\n",turn19_word);
            getchar();
            last_result = 2;
        }
    }
    else{
        if(expv[PlayerIndex]>350){
            printf("貴方は%sに勝利した！\n",turn19_word);
            getchar();
            last_result = 1;
        }
        else{
            printf("貴方は%sに敗北した！\n",turn19_word);
            getchar();
            last_result = 2;
        }
    }
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    return 0;
}
int life3_20(int dice){
    if(choice==1){
        if(last_result==1){
            printf("%s",turn20_word_a_w);
        }
        else{
            printf("%s",turn20_word_a_l);
        }
    }
    else{
        if(last_result==1){
            printf("%s",turn20_word_b_w);
        }
        else{
            printf("%s",turn20_word_b_l);
        }
    }
    printf(":経験値＋%d！\n",10*(dice-1));
    expv[PlayerIndex] += 10*(dice-1);
    getchar();
    printf("これにて貴方の半生の全てが物語られました\n");
    getchar();
    printf("貴方が積んできた経験値は%dです。",expv[PlayerIndex]);
    getchar();
    printf("どうでしたか？もし満足いかなければもう一度初めからやってみるもいいでしょう。\n");
    getchar();
}