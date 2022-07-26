
#include <stdio.h>
#define CHARBUFF 124

const int digitnum = 3;
typedef struct numbers {
    int digit[digitnum];
    int ansvalue;
};

void gameclear() {
    fprintf_s(stdout, "�Q�[���N���A�I�I�I�I\n");
}

void gameover(struct numbers ans) {
    fprintf_s(stdout, "�Q�[���I�[�o�[...\n������");
    for (int i = 0; i < digitnum; i++) {
        fprintf_s(stdout, "%d", ans.digit[i]);
    }
    fprintf_s(stdout, "\n");
}
/*
�v���O�������s���x�ɐV�������ʃt�@�C���𐶐�����B���łɂ��錋�ʃt�@�C���̏㏑����h���B
���̃Q�[���̌��ʃt�@�C�����������݂��邩���Ǘ����Ă���B
�����錋�ʃt�@�C���̌����Ǘ�����e�L�X�g�t�@�C�����쐬���A���̒l��ǂݍ���
ResultCount.txt�����݂���΂����ɏ�����Ă���l��ǂݎ�肻���ɏ�����Ă���l��Ԃ��B
���݂��Ȃ���ΐV�������̃t�@�C�����쐬��0��Ԃ��B
*/
int countResult() {
    int fileCount = 0;
    FILE* fp;
    char filename[CHARBUFF];
    int fc = 0;
    errno_t error;
    error = fopen_s(&fp, "ResultCount.txt", "a+");
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {

        while (fscanf_s(fp, "%d", &fc) != EOF) {
            fileCount = fc;
            fprintf_s(stdout, "%d", fc);
        };

        fprintf(fp, "%d\n", fileCount + 1);
        fclose(fp);
    }
    return fileCount;
}

void createResult(struct numbers predict[], struct numbers ans, int predictcount) {
    FILE* fp;
    char filename[CHARBUFF];
    int fileCount = countResult();  //���ʃt�@�C�����������݂��Ă��邩�𐔂���B
    int fc = 0;
    errno_t error;

    //�t�@�C�����́uHit&BlowResult_�t�@�C���ԍ��v
    sprintf_s(filename, "Hit&BlowResult_%d.csv", fileCount + 1);

    error = fopen_s(&fp, filename, "w");
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {

        fprintf(fp, "%s,", "����");
        for (int i = 0; i < digitnum; i++) {
            fprintf(fp, "%d,", ans.digit[i]);
        }
        fprintf(fp, "\n");
        for (int i = 0; i < predictcount; i++) {
            fprintf(fp, "%d��ڂ̓���,", i + 1);
            for (int j = 0; j < digitnum; j++) {
                fprintf(fp, "%d,", predict[i].digit[j]);
            }
            fprintf(fp, "\n");
        }

        fclose(fp);
    }

    //ResultCount.txt�P�ɐV�����t�@�C���̌�����������
    error = fopen_s(&fp, "ResultCount.txt", "w");
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {

        fprintf(fp, "%d\n", fileCount + 1);
        fclose(fp);
    }
}