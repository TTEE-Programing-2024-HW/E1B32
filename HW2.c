#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("-----------\n");
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
    printf("<         >\n");
    printf("<         >\n");
    printf("<         >\n");
    printf("<         >\n");
    printf("<         >\n");
    printf("<         >\n");
    printf("-----------\n");//個人風格
    int n,p;
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
	}while(p!=2024);//第一題
    system("clear");//清空控制台窗口的內容
    
    printf("------------\n");
    printf("<直角三角形>\n");
    printf("< 99乘法表 >\n");
    printf("<   結束   >\n");
    printf("------------\n");
	
}