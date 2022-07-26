#pragma once
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#define CHARBUFF 124
const int digitnum = 3; //桁数

//最初に生成する3桁の数字と、プレイヤーが入力する3桁の数字を管理する構造体
typedef struct numbers {
    int digit[digitnum];    //それぞれの桁ごとの数字を格納
    int ansvalue;
};

struct numbers decideAnswer(struct numbers ans);
int getPredictLimit();
bool isSame(struct numbers predict, struct numbers ans);
struct numbers input(struct numbers predict);
void gameclear();
void gameover(struct numbers ans);
void createResult(struct numbers predict[], struct numbers ans, int predictcount);
int countResult();