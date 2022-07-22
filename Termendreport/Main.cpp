// Main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#include "Termendreport.h"
struct numbers ans;
int main(){
    int predictLimit = getPredictLimit();
    printf("ヒットアンドブロー\n");
    printf("コンピュータがランダムで選んだ3桁の数字を当てよう！\n");
    printf("ルール説明\n");
    printf("数字と場所が合えばヒット、数字のみがあっていればブロー\n");
    printf("%d回以内に正解すればクリア\n\n", predictLimit);


    while (1) {
        

        ans = decideAnswer(ans);
        struct numbers predict[10];

        bool clearflag = false;
        int predictcount = 0;

        while (clearflag == false && predictcount < predictLimit) {
            predict[predictcount] = input(predict[predictcount]);
            clearflag = isSame(predict[predictcount], ans);
            predictcount++;
            fprintf_s(stdout, "%d\n", predictcount);
        }

        if (clearflag == true) {
            gameclear();
        }
        else {
            gameover(ans);
        }
        createResult(predict, ans, predictcount);

        char retry[CHARBUFF];
        fprintf_s(stdout, "もう一度プレイする場合はrを入力してください：");
        scanf_s("%s", retry, CHARBUFF);
        
        if (*retry!= 'r')break;

    }
    return 0;


}