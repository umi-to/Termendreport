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
const int digitnum = 3; //����

//�ŏ��ɐ�������3���̐����ƁA�v���C���[�����͂���3���̐������Ǘ�����\����
typedef struct numbers {
    int digit[digitnum];    //���ꂼ��̌����Ƃ̐������i�[
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