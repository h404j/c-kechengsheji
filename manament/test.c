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
void save(struct manament *m);
void findstu(struct manament *m, int id);
void addstu(struct manament *m);
void updatestu(struct manament *m);
int deletestu(struct manament *m, int id);
void findallstu(struct manament *m);
void savestu(struct manament *m);
void readstu(struct manament *m);
void menu1()
{
    int id = 0;
    struct manament stu, *st;
    initstu(&stu);
    readstu(&stu);
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
            printf("请输入所要删除的学生id: ");
            scanf("%d", &id);
            findstu(&stu,id);
            id = 0;
            break;
        case 4:
            system("CLS");
            printf("查看所有学生成绩：\n");
            /* code */
            break;
        case 5:
            system("CLS");
            printf("删除学生成绩：\n");
            printf("请输入所要删除的学生id: ");
            scanf("%d", &id);
            if (deletestu(&stu, id))
            {
                printf("删除成功\n");
            }
            else
            {
                printf("查无此人\n");
            }
            id = 0;
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
    m->size = 0;
}
void addstu(struct manament *m)
{
    printf("添加学生成绩：\n");
    printf("请输入学生学号：\n");
    scanf("%d", &(m->me[m->size].id));
    printf("请输入学生姓名\n");
    scanf("%s", m->me[m->size].name); //姓名
    printf("请输入学生的班级：\n");
    scanf("%d", &(m->me[m->size].class));
    printf("请输入考试学期：\n");
    scanf("%d", &(m->me[m->size].semter)); //学期
    printf("请输入学生的英语成绩：\n");
    scanf("%d", &(m->me[m->size].stugread.English)); //英语成绩
    printf("请输入学生的数学成绩：\n");
    scanf("%d", &(m->me[m->size].stugread.math)); //数学成绩
    printf("请输入学生的c语言成绩：\n");
    scanf("%d", &(m->me[m->size].stugread.c));
    m->me[m->size].stugread.score = m->me[m->size].stugread.c + m->me[m->size].stugread.math + m->me[m->size].stugread.English; //计算总分
    savestu(m);
    m->size++;
    system("CLS"); //清空输出
    printf("添加成功\n");
}
void updatestu(struct manament *m)
{
}
int deletestu(struct manament *m, int id)
{
    int j = -1;
    for (int i = 0; i < m->size; i++)
    {
        if (m->me[i].id == id)
        {
            j = i;
            break;
        }
    }
    if (j != -1)
    {
        for (j; j < m->size; j++)
        {
            m->me[j] = m->me[j + 1];
        }
        m->size--;
        save(m);
        return 1;
    }
    return 0;
}
void findstu(struct manament *m, int id)
{
    int j = -1;
    for (int i = 0; i < m->size; i++)
    {
        if (m->me[i].id == id)
        {
            j = i;
            break;
        }
    }
    if (j!=-1)
    {
        printf("学号：%-4d 性名：%-4s 班级：%-3d 学期%-3d 英语%-3d 数学%-3d c语言：%-3d 总分：%-3d\n ", m->me[j].id, m->me[j].name, m->me[j].class, m->me[j].semter, m->me[j].stugread.English, m->me[j].stugread.math, m->me[j].stugread.c, m->me[j].stugread.score);
    }else
    {
        printf("查无此人\n");
    }
    
    
    
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
void save(struct manament *m)
{
    FILE *fp;
    if ((fp = fopen("managent.txt", "w")) == NULL)
    {
        printf("文件打开失败");
        exit(0);
    }
    for (int a = 0; a < m->size; a++)
    {
        fprintf(fp, "%d %s %d %d %d %d %d %d\n", m->me[a].id, m->me[a].name, m->me[a].class, m->me[a].semter, m->me[a].stugread.English, m->me[a].stugread.math, m->me[a].stugread.c, m->me[a].stugread.score);
    }

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