#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
struct gread
{
    int English; //鑻辫??鎴愮哗
    int c;       //c璇?瑷�鎴愮哗
    int math;    //鏁板?︽垚缁?
    int score;   //瀛︽湡鎬诲垎
};
struct student
{
    int id;
    char name[10];
    int class;
    int semter;
    struct gread stugread;
};
struct manament
{
    struct student me[MAX];
    int size;
};
void initstu(struct manament *m);
void addstu(struct manament *m);
void updatestu(struct manament *m);
void deletetu(struct manament *m);
void findstu(struct manament *m);
void findallstu(struct manament *m);
void savestu(struct manament *m);

void readstu(struct manament *m);
void menu1()
{
    struct manament stu;
    initstu(&stu);
    // readstu(&stu);
    int flag = 1;
    while (flag) //死循环确保系统一直运行，当退出系统时flag=1,跳出循环
    {
        printf("----------------------学生成绩管理系统-----------------\n");
        printf("------------------1:添加学生成绩-----------------------\n");
        printf("------------------2:修改学生成绩-----------------------\n");
        printf("------------------3：查找学生成绩----------------------\n");
        printf("------------------4：查看所有学生成绩-------------------\n");
        printf("------------------5：删除学生成绩-----------------------\n");
        printf("------------------6：退出系统---------------------------\n");
        printf("请选择操作数来完成你的操作：");
        int a;
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            system("CLS");
            addstu(&stu);
            break;
        case 2:
            /* code */
            system("CLS");
            printf("修改学生成绩：");
            break;
        case 3:
            system("CLS");
            printf("查找学生成绩：\n");
            /* code */
            break;
        case 4:
            system("CLS");
            printf("查看所有学生成绩：\n");
            /* code */
            break;
        case 5:
            system("CLS");
            printf("删除学生成绩：\n");
            /* code */
            break;
        case 6:
            system("CLS");
            printf("谢谢使用，欢迎下次光临：");
            flag = 0;
            break;
        default:
            system("CLS");
            printf("输入错误，请重新输入！\n");
            break;
        }
    }
}
int main()
{
    // void addstu(&stu);
    // initstu(&stu);
    menu1();
    system("pause");
    return 0;
}
void initstu(struct manament *m)
{
    if (m->size == MAX)
    {
        return;
    }
    else
    {
        memset(m->me, 0, sizeof(m->me));
    }
    m->size=0;
}
void addstu(struct manament *m)
{
    printf("添加学生成绩：\n");
    printf("请输入学生学号：\n");
    scanf("%d", &(m->me[m->size].id));
    printf("请输入学生姓名\n");
    scanf("%s", m->me[m->size].name);
    printf("请输入学生的班级：\n");
    scanf("%d", &(m->me[m->size].class));
    printf("请输入考试学期：\n");
    scanf("%d", &(m->me[m->size].semter));
    printf("请输入学生的英语成绩：\n");
    scanf("%d", &(m->me[m->size].stugread.English));
    printf("请输入学生的数学成绩：\n");
    scanf("%d", &(m->me[m->size].stugread.math));
    printf("请输入学生的c语言成绩：\n");
    scanf("%d", &(m->me[m->size].stugread.c));
    m->me[m->size].stugread.score = m->me[m->size].stugread.c + m->me[m->size].stugread.math + m->me[m->size].stugread.English;
    savestu(m);
    m->size++;
    system("CLS");
    printf("添加成功\n");
}
void updatestu(struct manament *m)
{
}
void deletestu(struct manament *m)
{
}
void findstu(struct manament *m)
{
}
void findallstu(struct manament *m)
{
}
void savestu(struct manament *m)
{
    FILE *fp;
    if (m->size == 0)
    {
        if ((fp = fopen("managent.txt", "w")) == NULL)
        {
            printf("文件打开失败");
            exit(0);
        }
    }
    else
    {
        if ((fp = fopen("managent.txt", "a")) == NULL)
        {
            printf("文件打开失败");
            exit(0);
        }
    }
    fprintf(fp, "%d %s %d %d %d %d %d %d\n", m->me[m->size].id, m->me[m->size].name, m->me[m->size].class, m->me[m->size].semter, m->me[m->size].stugread.English, m->me[m->size].stugread.math, m->me[m->size].stugread.c, m->me[m->size].stugread.score);
    if (fclose(fp))
    {
        printf("文件关闭失败，");
        exit(0);
    }
}
void readstu(struct manament *m)
{
    FILE *fp;
    if ((fp = fopen("managent.txt", "r")) == NULL)
    {
        printf("文件打开失败");
        exit(0);
    }
    while (fscanf(fp, "%d %s %d %d %d %d %d %d", &(m->me[m->size].id), m->me[m->size].name, &(m->me[m->size].class), &(m->me[m->size].semter), &(m->me[m->size].stugread.English), &(m->me[m->size].stugread.math), &(m->me[m->size].stugread.c), &(m->me[m->size].stugread.score)) > 0)
    {
        m->size++;
    }

    if (fclose(fp))
    {
        printf("文件关闭失败，");
        exit(0);
    }
}
// void readstu(struct manament *m)
// {
//     FILE *fp;
//         if ((fp = fopen("managent.txt", "r")) == NULL)
//         {
//             printf("文件打开失败");
//             exit(0);
//         }
//     // fprintf(fp, "%d %s %d %d %d %d %d %d", m->me[m->size].id, m->me[m->size].name, m->me[m->size].class, m->me[m->size].semter, m->me[m->size].stugread.English, m->me[m->size].stugread.math, m->me[m->size].stugread.c, m->me[m->size].stugread.score);
//     fread(m,sizeof(m),1,fp);
//     if (fclose(fp))
//     {
//         printf("文件关闭失败，");
//         exit(0);
//     }
// }
// void exitsavestu(struct manament *m)
// {
//     FILE *fp;
//     if ((fp = fopen("managent.txt", "w")) == NULL)
//     {
//         printf("文件打开失败");
//         exit(0);
//     }
//     // fprintf(fp, "%d %s %d %d %d %d %d %d", m->me[m->size].id, m->me[m->size].name, m->me[m->size].class, m->me[m->size].semter, m->me[m->size].stugread.English, m->me[m->size].stugread.math, m->me[m->size].stugread.c, m->me[m->size].stugread.score);
//     fwrite(m, sizeof(m), 1, fp);
//     if (fclose(fp))
//     {
//         printf("文件关闭失败，");
//         exit(0);
//     }
// }