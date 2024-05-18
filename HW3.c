#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h> 

#define ROWS 9
#define COLS 9
#define RESERVED_SEATS 10

void initialize_seats(char seats[ROWS][COLS]);
void display_seats(char seats[ROWS][COLS]);
void reserve_random_seats(char seats[ROWS][COLS]);
void clear_screen();
int manual_select_seats(char seats[ROWS][COLS]);

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
    system("cls");//清空控制台窗口的內容

    printf("----[Booking System]----\n");
    printf("<a.Available seats     >\n");
    printf("<b.Arrange for you     >\n");
    printf("<c.Choose by urself    >\n");
    printf("<d.Exit                >\n");
    printf("------------------------\n");//第二題主選單

    char seats[ROWS][COLS];
    char choice;

    srand(time(NULL));

    initialize_seats(seats);
    reserve_random_seats(seats);

    while (1) {
        printf("請按 'a' 顯示座位表，按 'b' 預訂座位，按 'c' 手動選座，或按 'q' 退出：");
        choice = getchar();
        getchar();  // 捕捉並忽略 Enter 鍵

        if (choice == 'q') {
            break;
        } else if (choice == 'a') {//第三題
            display_seats(seats);
            printf("按任意鍵返回主選單...");
            _getch();  // 只適用於 Windows 平台
            clear_screen();
        } else if (choice == 'b') {//第四題
            int num_seats;
            printf("請輸入需要的座位數量（1-4）：");
            scanf("%d", &num_seats);
            getchar();  // 捕捉並忽略 Enter 鍵

            if (num_seats < 1 || num_seats > 4) {
                printf("無效的座位數量！\n");
                continue;
             }

            printf("這些座位滿意嗎？（y/n）：");
            char satisfaction = getchar();
            getchar();  // 捕捉並忽略 Enter 鍵

            if (satisfaction == 'y') {
                printf("座位已預訂。\n");
            } else {
                printf("重新選擇座位。\n");
            }
            printf("按任意鍵返回主選單...");
            _getch();  // 只適用於 Windows 平台
            clear_screen();
        } else if (choice == 'c') {//第五題
            if (manual_select_seats(seats)) {
                display_seats(seats);
                printf("按任意鍵確認選擇的座位...");
                _getch();  // 只適用於 Windows 平台
                clear_screen();
            } else {
                printf("選擇座位失敗。\n");
                printf("按任意鍵返回主選單...");
                _getch();  // 只適用於 Windows 平台
                clear_screen();
            }
        }
    }

    return 0;
}

void initialize_seats(char seats[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            seats[i][j] = '-';
        }
    }
}

void display_seats(char seats[ROWS][COLS]) {
    printf("  123456789\n");
    for (int i = 0; i < ROWS; ++i) {
        printf("%d ", ROWS - i);
        for (int j = 0; j < COLS; ++j) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

void reserve_random_seats(char seats[ROWS][COLS]) {
    int reserved = 0;
    while (reserved < RESERVED_SEATS) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            reserved++;
        }
    }
}

int manual_select_seats(char seats[ROWS][COLS]) {
    char input[10];
    int selected_seats[ROWS * COLS][2];
    int num_selected_seats = 0;

    printf("請逐一輸入座位選擇，如1-2、2-9（輸入 'done' 結束選擇）：\n");
    while (1) {
        printf("請輸入座位：");
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "done", 4) == 0) {
            break;
        }

        int row, col;
        if (sscanf(input, "%d-%d", &row, &col) != 2 || row < 1 || row > ROWS || col < 1 || col > COLS) {
            printf("格式錯誤，請重新輸入！\n");
            continue;
        }

        row = ROWS - row;  // 轉換為內部表示的行號
        col = col - 1;     // 轉換為內部表示的列號

        if (seats[row][col] != '-') {
            printf("座位已被預訂或無效，請重新輸入！\n");
            continue;
        }

        selected_seats[num_selected_seats][0] = row;
        selected_seats[num_selected_seats][1] = col;
        num_selected_seats++;
        seats[row][col] = '@';
    }

    return (num_selected_seats > 0);
}

void clear_screen() {
    // 清除螢幕，適用於 Windows 平台
    system("cls");
}