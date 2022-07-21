#pragma once
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#define CHARBUFF 124
const int digitnum = 3;

typedef struct numbers {
    int digit[digitnum];
    int ansvalue;
};

struct numbers ans;

void decideAnswer();
bool isSame(struct numbers);
struct numbers input(struct numbers predict);
void gameclear();
void gameover();
void createResult();