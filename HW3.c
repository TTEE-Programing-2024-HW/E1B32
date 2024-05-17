#include<stdio.h>
#include<stdlib.h>
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
    int n=0,p;
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
    printf("歡迎!");
    system("clear");//清空控制台窗口的內容

    printf("----[Booking System]----\n");
    printf("<a.Available seats     >\n");
    printf("<b.Arrange for you     >\n");
    printf("<c.Choose by urself    >\n");
    printf("<d.Exit                >\n");
    printf("------------------------\n");//第二題主選單
}