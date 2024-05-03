#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
int main(void){
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
    int n=0,p,d,e,f;//n是輸入密碼次數，p是密碼，d是九九乘法表的上限，e是外部循環計數器，f是內部循環計數器
    char ch,a,b,c,y;
	do
	{
		printf("請輸入密碼");
		scanf("%d",&p);
		n++;
		if(n>=3)
		{
			printf("超過3次\n");
			printf("\a");
			break;
		}
	}while(p!=2024);//第一題p若不是2024則繼續迴圈
    system("clear");//清空控制台窗口的內容
    do{
    printf("--------------\n");
    printf("<a.直角三角形>\n");
    printf("<b. 99乘法表 >\n");
    printf("<c.   結束   >\n");
    printf("--------------\n");//第二題，輸入a,b,c
    fflush(stdin);//清除緩存
    scanf(" %c", &ch);
    switch(ch) {
        case 'A':
        case 'a':
            printf("輸入一個a~n的字母: ");//a~n
            fflush(stdin);
            scanf(" %c", &a);
            if(a < 'a' || a > 'n') {
                printf("錯誤,輸入一個a~n的字母\n");
            }else {
                for( b = a; b >= 'a'; b--) {
                    for( c = b; c <= a; c++) {
                        printf("%c", c);
                    }
                    printf("\n");
                }
            }
            break;//第三題

        case 'B':
        case 'b':
            printf("請輸入一個1~9的數字: ");//1~9
            scanf("%d", &d);// 使用者輸入的九九乘法表上限
            if(d >= 1 && d <= 9) {
                for(e = 1; e <= d; e++) {// 外部循環，控制行數
                    for(f = 1; f <= e; f++) {// 內部循環，控制列數
                        printf("%d ", e * f);
                    }
                    printf("\n");
                }
            } else {
                printf("輸入錯誤\n");
            }
            break;//第四題

        case 'C':
        case 'c':
            printf("Continue? (Y/N): ");
            scanf(" %c", &y);
            if(y == 'n' || y == 'N') {
                printf("夾束\n");
                return 0;
            } else if (y == 'y' || y == 'Y') {
                break;
            } else {
                printf("請輸入Y或N\n");//Y/y or N/n
            }
            break;//第五題

        default:
            printf("請輸入有效的選擇 (A/B/C)\n");//若是除了ABC以外的輸入則輸出這行
            break;
    }
    } while(1);

    return 0;
}