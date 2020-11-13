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
int updatestu(struct manament *m, int id);
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
            findallstu(&stu);
            printf("请输入所要修改成绩的学生id: (-1返回上一级)\n");
            scanf("%d", &id);
            if (id >= 0)
            {
                updatestu(&stu, id);
            }
            id = 0;

            break;
        case 3:
            system("CLS");
            printf("请输入所要查找的学生id: (-1返回上一级)\n");
            scanf("%d", &id);
            if (id >= 0)
            {
                findstu(&stu, id);
            }
            id = 0;
            break;
        case 4:
            system("CLS");
            printf("查看所有学生成绩：\n");
            findallstu(&stu);
            break;
        case 5:
            system("CLS");
            findallstu(&stu);
            printf("请输入所要删除的学生id: (-1返回上一级)\n");
            scanf("%d", &id);
            if (id >= 0)
            {
                if (deletestu(&stu, id))
                {
                    printf("删除成功\n");
                }
                else
                {
                    printf("查无此人\n");
                }
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
    int se;
    while (scanf("%d", &se), se > 2)
    {
        printf("只有两个学期！请重新输入\n");
    }
    m->me[m->size].semter = se;
    printf("请输入学生的英语成绩：\n");
    int en;
    while (scanf("%d", &en), en > 100)
    {
        printf("英语满分只有100！请重新输入\n");
    }
    m->me[m->size].stugread.English = en;
    printf("请输入学生的数学成绩：\n");
    int mt;
    while (scanf("%d", &mt), mt > 100)
    {
        printf("数学满分只有100！请重新输入\n");
    }
    m->me[m->size].stugread.math = mt;
    printf("请输入学生的c语言成绩：\n");
    int c;
    while (scanf("%d", &c), c > 100)
    {
        printf("c语言满分只有100！请重新输入\n");
    }
    m->me[m->size].stugread.c = c;
    m->me[m->size].stugread.score = c + mt + en;
    // m->me[m->size].stugread.score = m->me[m->size].stugread.c + m->me[m->size].stugread.math + m->me[m->size].stugread.English; //计算总分
    savestu(m);
    m->size++;
    system("CLS"); //清空输出
    printf("添加成功\n");
}
int updatestu(struct manament *m, int id)
{

    int j = -1;
    for (int i = 0; i < m->size; i++)
    {
        if (m->me[i].id == id)
        {
            j = i; //找到对应id在数组的位置，用j记录，
            break;
        }
    }
    printf("输入新的英语成绩,如不更改，请输入-1：\n");
    int Eng;
    while (scanf("%d", &Eng), Eng > 100)
    {
        printf("英语成绩满分100，请检查后再次输入\n");
    }
    if (Eng >= 0)
    {
        m->me[j].stugread.English = Eng;
    }
    printf("输入新的数学成绩,如不更改，请输入-1：\n");
    int M;
    while (scanf("%d", &M), M > 100)
    {
        printf("英语成绩满分100，请检查后再次输入\n");
    }
    if (Eng >= 0)
    {
        m->me[j].stugread.English = Eng;
    }
    printf("输入新的c语言成绩,如不更改，请输入-1：\n");
    int C;
    while (scanf("%d", &C), C > 100)
    {
        printf("英语成绩满分100，请检查后再次输入\n");
    }
    if (C >= 0)
    {
        m->me[j].stugread.c = C;
    }
    printf("更改成功！");
    save(m); //保存删除后的数组
}
int deletestu(struct manament *m, int id)
{
    findstu(m, id);
    int j = -1;
    for (int i = 0; i < m->size; i++)
    {
        if (m->me[i].id == id)
        {
            j = i; //找到对应id在数组的位置，用j记录，
            break;
        }
    }
    if (j != -1)
    {
        for (j; j < m->size; j++)
        {
            m->me[j] = m->me[j + 1]; //将所要删除的id后面的数据迁移一位，达到删除的目的
        }
        m->size--;
        save(m); //保存删除后的数组
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
            j = i; //找到对应id在数组的位置，用j记录，在下方输出
            break;
        }
    }
    if (j != -1)
    {
        printf("学号:%-4d 性名:%-4s 班级：%-3d 学期:%-3d 英语:%-3d 数学:%-3d c语言:%-3d 总分:%-3d\n ", m->me[j].id, m->me[j].name, m->me[j].class, m->me[j].semter, m->me[j].stugread.English, m->me[j].stugread.math, m->me[j].stugread.c, m->me[j].stugread.score);
    }
    else
    {
        printf("查无此人\n");
    }
}
void findallstu(struct manament *m)
{
    printf("    学号   性名   班级   学期   英语   数学   c语言   总分\n");
    for (int j = 0; j < m->size; j++) //循环结构体，输出
    {
        printf("%7d%9s%5d%7d%8d%7d%8d%7d\n", m->me[j].id, m->me[j].name, m->me[j].class, m->me[j].semter, m->me[j].stugread.English, m->me[j].stugread.math, m->me[j].stugread.c, m->me[j].stugread.score);
    }
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