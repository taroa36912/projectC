#ifndef LIFE_H
#define LIFE_H

//変数の宣言
extern int expv[6];
extern char player[6][100];
//上記の変数は, main関数でscanfした後, または定義した後であれば自由に使用可

// 関数の宣言
int life1(int i, int dice, int turn);
int life2(int i, int dice, int turn);
int life3(int i, int dice, int turn);
int life4(int i, int dice, int turn);
int life5(int i, int dice, int turn);
int life6(int i, int dice, int turn);
void InputLife1(void);
void InputLife2(void);
void InputLife3(void);
void InputLife4(void);
void InputLife5(void);
void InputLife6(void);
int Jyanken();
int minigame();
int All_minigame();



#endif