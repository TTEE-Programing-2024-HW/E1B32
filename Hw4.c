#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("-----------\n");
    printf("<  E1B32  >\n");
    printf("<   黃    >\n");
    printf("<   韋    >\n");
    printf("<   捷    >\n");
    printf("<         >\n");
    printf("<         >\n");
    printf("<         >\n");
    printf("<   請    >\n");
    printf("<   輸    >\n");
    printf("<   入    >\n");
    printf("<   密    >\n");
    printf("<   碼    >\n");
    printf("<    :    >\n");
    printf("<         >\n");
    printf("<         >\n");
    printf("<         >\n");
    printf("<         >\n");
    printf("<         >\n");
    printf("<         >\n");
    printf("<         >\n");
    printf("-----------\n");//個人風格

    int n = 0, p;
    do {
        printf("請輸入密碼: ");
        scanf("%d", &p);
        n++;
        if (n >= 3) {
            printf("超過3次\n");
            printf("\a");
            return 1;  // 結束程式
        }
    } while (p != 2024);  // 第一題
    printf("歡迎!\n");
    getchar();  // 清除緩衝區中的多餘字符
    clear_screen();  // 清空控制台窗口的內容