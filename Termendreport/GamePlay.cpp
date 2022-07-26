#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define CHARBUFF 124
const int digitnum = 3;

typedef struct numbers {
    int digit[digitnum];
    int ansvalue;
};

struct numbers input(struct numbers predict) {
    int a;
    char input[256];
    bool inputflag = false;

    //���͓��e���������Ȃ�܂œ��͂��J��Ԃ��B
    while (inputflag == false) {
        printf("%d���̐�������́F", digitnum);
        scanf_s("%s", input, CHARBUFF);
        inputflag = true;

        //���͂��ꂽ���̂̌�����������������
        if (strlen(input) != digitnum) {
            fprintf_s(stdout, "�������Ⴂ�܂�\n");
            inputflag = false;
        }

        //�����ȊO�����͂���Ă��Ȃ����𔻒�
        for (int i = 0; i < digitnum; i++) {
            if (!isdigit(input[i])) {
                fprintf_s(stdout, "�����ȊO�����͂���Ă��܂�\n");
                inputflag = false;
            }
        }

    }

    //������^�𐮐��^�ɕϊ�
    predict.ansvalue = atoi(&input[0]);

    //�ꌅ���z��Ɋi�[
    for (int i = 0; i < digitnum; i++) {
        predict.digit[i] = (int)(predict.ansvalue / pow(10, 2 - i)) % 10;
    }

    return predict;
}

bool isSame(struct numbers predict, struct numbers ans) {
    int hitcount = 0;
    int blowcount = 0;
    /*
    ���͂��ꂽ�������A�ŏ��ɐ������������ƈ�v���邩����B
    �������ŁA�����̌����m�̐��������Ȃ��hitcount��1���₷�B
    �Ⴄ���ŁA���̌������������Ȃ��blowcount��1���₷�B
    */
    for (int i = 0; i < digitnum; i++) {
        for (int j = 0; j < digitnum; j++) {
            if (i == j) {
                if (predict.digit[i] == ans.digit[j]) {
                    hitcount++;
                }
            }
            else {
                if (predict.digit[i] == ans.digit[j]) {
                    blowcount++;
                }
            }
        }
    }

   // hitcount��digitnum�A����ł�3�ł����true��Ԃ��B�����łȂ����false��Ԃ��B
    fprintf_s(stdout, "%d�q�b�g�A%d�u���[\n", hitcount, blowcount);
    if (hitcount == digitnum) {
        return true;
    }
    return false;
}