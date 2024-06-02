#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int student_id;
    int math_score;
    int physics_score;
    int english_score;
    float average_score;
} Student;

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int input_integer(char *prompt, int min, int max) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            printf("輸入錯誤，請輸入一個數字。\n");
            while (getchar() != '\n'); // 清空緩衝區
        } else if (value < min || value > max) {
            printf("請輸入介於 %d 到 %d 之間的數字。\n", min, max);
        } else {
            return value;
        }
    }
}

void input_student_data(Student *students, int n) {
    for (int i = 0; i < n; ++i) {
        printf("輸入第 %d 個學生的資料：\n", i + 1);
        printf("姓名: ");
        scanf("%s", students[i].name);
        printf("學號（6位整數）: ");
        scanf("%d", &students[i].student_id);
        printf("數學成績（0~100）: ");
        students[i].math_score = input_integer("", 0, 100);
        printf("物理成績（0~100）: ");
        students[i].physics_score = input_integer("", 0, 100);
        printf("英文成績（0~100）: ");
        students[i].english_score = input_integer("", 0, 100);
        students[i].average_score = (students[i].math_score + students[i].physics_score + students[i].english_score) / 3.0;
    }
}//第四題

void display_students(Student *students, int n) {
    clear_screen();
    printf("學生資料:\n");
    printf("姓名\t\t學號\t\t數學\t物理\t英文\t平均成績\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; ++i) {
        printf("%-10s\t%d\t%d\t%d\t%d\t%.1f\n", students[i].name, students[i].student_id, students[i].math_score, students[i].physics_score, students[i].english_score, students[i].average_score);
    }
    printf("\n按下任意鍵返回主選單...\n");
    getchar();
    getchar();  // 等待使用者按下任意鍵
}//第六題

void search_student(Student *students, int n) {
    clear_screen();
    char search_name[MAX_NAME_LENGTH];
    printf("請輸入要搜尋的學生姓名: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < n; ++i) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("找到學生:\n");
            printf("姓名: %s\n學號: %d\n數學成績: %d\n物理成績: %d\n英文成績: %d\n平均成績: %.1f\n", 
                   students[i].name, students[i].student_id, students[i].math_score, students[i].physics_score, students[i].english_score, students[i].average_score);
            found = 1;
            break;
        }
    }//第五題
    if (!found) {
        printf("未找到學生: %s\n", search_name);
    }
    printf("\n按下任意鍵返回主選單...\n");
    getchar();
    getchar();  // 等待使用者按下任意鍵
}

int compare_students(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return (studentB->average_score - studentA->average_score) * 100; // 乘以100以避免浮點數比較的誤差
}

void display_sorted_students(Student *students, int n) {
    clear_screen();
    qsort(students, n, sizeof(Student), compare_students);
    printf("依平均成績排序的學生資料:\n");
    printf("姓名\t\t學號\t\t平均成績\n");
    printf("------------------------------------\n");
    for (int i = 0; i < n; ++i) {
        printf("%-10s\t%d\t%.1f\n", students[i].name, students[i].student_id, students[i].average_score);
    }
    printf("\n按下任意鍵返回主選單...\n");
    getchar();
    getchar();  // 等待使用者按下任意鍵
}

void enter_student_grades(Student *students) {
    int n = input_integer("請輸入學生人數（5~10）: ", 5,10);//第三題
    input_student_data(students, n);
    clear_screen();
    printf("輸入完成，返回主選單。\n");
}


void display_student_grades(Student *students, int n) {
    if (n > 0) {
        display_students(students, n);
    } else {
        clear_screen();
        printf("沒有學生資料可顯示。返回主選單。\n");
        printf("\n按下任意鍵返回主選單...\n");
        getchar();
    }
}

void search_student_grades(Student *students, int n) {
    if (n > 0) {
        search_student(students, n);
    } else {
        clear_screen();
        printf("沒有學生資料可搜尋。返回主選單。\n");
        printf("\n按下任意鍵返回主選單...\n");
        getchar();
        getchar();
    }
}

void display_student_ranking(Student *students, int n) {
    if (n > 0) {
        display_sorted_students(students, n);
    } else {
        clear_screen();
        printf("沒有學生資料可排序。返回主選單。\n");
        printf("\n按下任意鍵返回主選單...\n");
        getchar();
        getchar();
    }
}

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

    Student students[MAX_STUDENTS];
    char choice;
    int student_count = 0;

    while (1) {
        clear_screen();
        printf("-------[Grade System]-------\n");
        printf("<a.Enter student grades     >\n");
        printf("<b.Display student grades   >\n");
        printf("<c.Search for student grades>\n");
        printf("<d.Grade ranking            >\n");
        printf("<e.Exit system              >\n");
        printf("----------------------------\n");//第二題
        printf("請選擇: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                enter_student_grades(students);
                break;
            case 'b':
                display_student_grades(students, student_count);
                break;
            case 'c':
                search_student_grades(students, student_count);
                break;
            case 'd':
                display_student_ranking(students, student_count);
                break;
            case 'e':
                clear_screen();
                printf("確定離開？ (y/n): ");
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y') {
                    clear_screen();
                    printf("結束程式。\n");
                    return 0;
                }
                break;
            default:
                printf("無效的選擇，請重新輸入。\n");
                break;
        }
    }

    return 0;
}
//這個程式展示了如何使用結構體和函式來管理學生資料，並實現密碼保護、輸入檢查、資料顯示、搜尋和排序等功能。