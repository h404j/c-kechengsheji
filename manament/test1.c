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
    char class[20];
    char semter[20];
    struct gread stugread;
};
struct manament
{
    struct student me[MAX];
    int size;
};
void initstu(struct manament *m);
void save(struct manament *m);
void findclassstu(struct manament *m, char class[20], int see);
void findscoreorder(struct manament *m, char class[20], char course[20], int see);
void findscoreEorder(struct manament *m, char class[20], int see);
void findscoreSorder(struct manament *m, char class[20], int see);
void findscoreMorder(struct manament *m, char class[20], int see);
void findscoreCorder(struct manament *m, char class[20], int see);
int ishaved(struct manament *m, int id);
void findstu(struct manament *m, int id);
void addstu(struct manament *m);
int updatestu(struct manament *m, int id);
int deletestu(struct manament *m, int id);
void findallstu(struct manament *m);
void savestu(struct manament *m);
void readstu(struct manament *m);
void menu1() //主界面，负责人：王豪杰
{
    int id = 0;
    struct manament stu, *st;
    initstu(&stu);
    readstu(&stu);
    int flag = 1;
    while (flag) //死循环确保系统一直运行，当退出系统时flag=1,跳出循环
    {
        printf("\t\t\t学生成绩管理系统\n");
        printf("----------------------------------------------------------------\n");
        printf("   0:退出系统\t\t\t");
        printf("   1:添加学生成绩\n");
        printf("----------------------------------------------------------------\n");
        printf("   2:修改学生成绩\t\t");
        printf("   3：查找学生成绩\n");
        printf("----------------------------------------------------------------\n");
        printf("   4：查看所有学生成绩\t\t");
        printf("   5：删除学生成绩\n");
        printf("----------------------------------------------------------------\n");
        printf("   6：按班级查找学生成绩\t");
        printf("   7：降序输出某班某课程的成绩。\n");
        printf("----------------------------------------------------------------\n");
        printf("\n请选择操作数来完成你的操作：");
        int a;
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            system("CLS"); //system函数清空屏幕，
            addstu(&stu);
            break;
        case 2:
            /* code */
            system("CLS");    //system函数清空屏幕，
            findallstu(&stu); //显示所有学生函数，之说以在这里显示所有学生是为了修改方便，防止记错id;
            printf("请输入所要修改成绩的学生id: (-1返回上一级)\n");
            scanf("%d", &id);
            if (id >= 0)
            {
                updatestu(&stu, id); //修改成绩函数
            }
            id = 0;

            break;
        case 3:
            system("CLS"); //system函数清空屏幕，
            printf("请输入所要查找的学生id: (-1返回上一级)\n");
            scanf("%d", &id);
            if (id >= 0)
            {
                findstu(&stu, id); //调用findstu()函数，显示指定id的学生信息
            }
            id = 0;
            break;
        case 4:
            system("CLS"); //system函数清空屏幕，
            printf("查看所有学生成绩：\n");
            findallstu(&stu); //显示所有学生的信息
            break;
        case 5:
            system("CLS");    //system函数清空屏幕，
            findallstu(&stu); //显示所有学生函数，之说以在这里显示所有学生是为了删除方便，防止记错id;
            printf("请输入所要删除的学生id: (-1返回上一级)\n");
            scanf("%d", &id); //输入id
            if (id >= 0)
            {
                int shanchu = deletestu(&stu, id);
                if (shanchu == 1)
                {
                    printf("删除成功\n");
                }
                else if (shanchu == 0)
                {
                    // system("CLS"); //system函数清空屏幕，

                    printf("查无此人\n");
                }
                else
                {
                    printf("退出，不进行删除\n");
                }
            }
            id = 0;
            /* code */
            break;
        case 6:
            system("CLS"); //system函数清空屏幕，
            printf("请输入班级：\n");
            char cla[20];

            scanf("%s", cla);
            int see;
            do
            {
                printf("请输入学期 （第一学期输入1，第二·学期输入2）：\n");
                scanf("%d", &see);
            } while (see < 1 || see > 2);
            findclassstu(&stu, cla, see);
            break;
        case 0:
            system("CLS"); //system函数清空屏幕，
            printf("谢谢使用，欢迎下次光临：");
            flag = 0; //flag=0,不满足循环条件，跳出大循环，
            break;
        case 7:
            system("CLS"); //system函数清空屏幕，
            printf("降序输出某班某课程的成绩。\n");
            printf("请输入班级\n");
            char clas[20];
            int see1=0;
          scanf("%s", clas);
            do
            {
                printf("请输入学期 （第一学期输入1，第二·学期输入2）：\n");
                scanf("%d", &see1);
            } while (see1 < 1 || see1 > 2);
            printf("请输入需要排序的课程名称，也可按输入“总分”，按总分排序，输入课程名的可以为中文全称、英文全称或者英文的首字母（大小写都可以）\n");
            char co[20];
            scanf("%s", co);
            findscoreorder(&stu, clas, co, see1);
            break;
        default:
            system("CLS"); //system函数清空屏幕，
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
    system("pause"); //vscode防止输出窗口一闪而过，
    return 0;
}
void initstu(struct manament *m) //初始化数组函数，完成人：王豪杰
{                                //初始化
    if (m->size == MAX)
    {
        return;
    }
    else
    {
        memset(m->me, 0, sizeof(m->me)); //使用string.h中的mamect()函数将结构数组的所有初始化为0
    }
    m->size = 0; //size初始化为0
}
void addstu(struct manament *m) //添加函数，完成人：侯航宇
{
    printf("添加学生成绩：\n");
    printf("请输入学生学号(四位数字))：\n");
    int id, tu;
    while (scanf("%d", &id))
    {
        if (ishaved(m, id)) //判断，id是否已存在，存在返回1，不存在返回0
        {
            printf("学号已存在，请选择，1、重新输入，0、退出输入\n");
            scanf("%d", &tu);
            if (tu) //判断tu,tu=1继续输入,否则退出该函数
            {
                printf("请输入学生学号：\n");
                continue;
            }
            else
            {
                printf("退出添加函数\n");
                return;
            }
        }
        break;
    }

    // do
    // {
    //     scanf("%d", &id);
    // } while (ishaved(m, id));
    m->me[m->size].id = id; //m是传入的结构指针，m->me[m->size]是manament结构中定义的student结构数组，m->size是当前系统中保存的学生信息的数目 ,m->me[m->size].semter是manament结构中定义的student结构数组中定义的学期
    printf("请输入学生姓名\n");
    scanf("%s", m->me[m->size].name); // //m是传入的结构指针，m->me[m->size]是manament结构中定义的student结构数组，m->size是当前系统中保存的学生信息的数目 ,m->me[m->size].semter是manament结构中定义的student结构数组中定义的学期
    printf("请输入学生的班级（专业+班级）：\n");
    scanf("%s", (m->me[m->size].class)); //m是传入的结构指针，m->me[m->size]是manament结构中定义的student结构数组，m->size是当前系统中保存的学生信息的数目 ,m->me[m->size].semter是manament结构中定义的student结构数组中定义的学期
    printf("请输入考试学期（第一学期输入1，第二学期输入2）：\n");
    int se;
    char a[20];                                 //学期
    while (scanf("%d", &se), se>2 || se<1) //判断输入的数是否符合常规
    {
        printf("请重新输入\n");
    }
    if (se == 1)
    {
        strcpy(m->me[m->size].semter, "第一学期");
    }
    else if (se == 2)
    {
        strcpy(m->me[m->size].semter, "第二学期");
    }
    //m是传入的结构指针，m->me[m->size]是manament结构中定义的student结构数组，m->size是当前系统中保存的学生信息的数目 ,m->me[m->size].semter是manament结构中定义的student结构数组中定义的学期
    printf("请输入学生的英语成绩：\n");
    int en;                                      //英语分数
    while (scanf("%d", &en), en > 100 || en < 0) //判断英语成绩输入是否在范围内
    {
        printf("英语满分只有100！,最低0分！，请重新输入\n");
    }
    m->me[m->size].stugread.English = en; //m是传入的结构指针，m->me[m->size]是manament结构中定义的student结构数组，m->size是当前系统中保存的学生信息的数目 ,m->me[m->size].stugread.c是manament结构中定义的student结构数组中定义的gread结构中的英语成绩
    printf("请输入学生的数学成绩：\n");
    int mt;                                      //数学分数
    while (scanf("%d", &mt), mt > 100 || mt < 0) //判断数学成绩输入是否在范围内
    {
        printf("数学满分只有100！,最低0分请重新输入\n");
    }
    m->me[m->size].stugread.math = mt; //m是传入的结构指针，m->me[m->size]是manament结构中定义的student结构数组，m->size是当前系统中保存的学生信息的数目 ,m->me[m->size].stugread.math是manament结构中定义的student结构数组中定义的gread结构中的数学成绩
    printf("请输入学生的C语言成绩：\n");
    int c;
    while (scanf("%d", &c), c > 100 || c < 0) //判断c语言成绩输入是否在范围内
    {
        printf("C语言满分只有100！,最低0分请重新输入\n");
    }
    m->me[m->size].stugread.c = c;               //m是传入的结构指针，m->me[m->size]是manament结构中定义的student结构数组，m->size是当前系统中保存的学生信息的数目 ,m->me[m->size].stugread.c是manament结构中定义的student结构数组中定义的gread结构中的c语言成绩
    m->me[m->size].stugread.score = c + mt + en; //总成绩
    // m->me[m->size].stugread.score = m->me[m->size].stugread.c + m->me[m->size].stugread.math + m->me[m->size].stugread.English; //计算总分
    savestu(m); //调用保存函数
    m->size++;  //添加后，size加一
    // system("CLS"); //system函数清空屏幕， //清空输出
    printf("添加成功\n");
}
int updatestu(struct manament *m, int id) //更新成绩函数，完成人：李函磊
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
    if (j == -1)
    {
        printf("查无此人\n");
        return 0;
    }
    findstu(m, id); //调用find()函数，m是传入的显示要更改的学生的信息，容易操作，
    printf("输入新的英语成绩,如不更改，请输入-1：\n");
    int Eng;
    while (scanf("%d", &Eng), Eng > 100) //判断更改的英语成绩是否超出范围，若失误将成绩输为负数，系统将不做更改
    {
        printf("英语成绩满分100，请检查后再次输入,如不更改，请输入-1：\n");
    }
    if (Eng >= 0)
    {
        m->me[j].stugread.English = Eng; //m是传入的结构指针，m->me[m->size]是manament结构中定义的student结构数组，m->size是当前系统中保存的学生信息的数目 ,m->me[m->size].English是manament结构中定义的student结构数组中定义的英语成绩
    }
    printf("输入新的数学成绩,如不更改，请输入-1：\n");
    int M;
    while (scanf("%d", &M), M > 100) //判断更改的成绩是否超出范围，若失误将成绩输为负数，系统将不做更改
    {
        printf("数学成绩满分100，请检查后再次输入,如不更改，请输入-1：\n");
    }
    if (M >= 0)
    {
        m->me[j].stugread.math = M; //m是传入的结构指针，m->me[m->size]是manament结构中定义的student结构数组，m->size是当前系统中保存的学生信息的数目 ,m->me[m->size].math是manament结构中定义的student结构数组中定义的数学成绩
    }
    printf("输入新的C语言成绩,如不更改，请输入-1：\n");
    int C;
    while (scanf("%d", &C), C > 100)
    //判断更改的成绩是否超出范围，若失误将成绩输为负数，系统将不做更改
    {
        printf("C语言成绩满分100，，请检查后再次输入,如不更改，请输入-1：\n");
    }
    if (C >= 0)
    {
        m->me[j].stugread.c = C; //m是传入的结构指针，m->me[m->size]是manament结构中定义的student结构数组，m->size是当前系统中保存的学生信息的数目 ,m->me[m->size].c是manament结构中定义的student结构数组中定义的c语言成绩
    }
    m->me[j].stugread.score = m->me[j].stugread.c + m->me[j].stugread.math + m->me[j].stugread.English; //计算总分
    printf("更改成功！\n");
    save(m); //保存删除后的数组
}
int deletestu(struct manament *m, int id) //根据id删除学生信息，完成人：郭鑫宇
{
    int j = -1;
    for (int i = 0; i < m->size; i++)
    {
        if (m->me[i].id == id) //循环，遍历数组，查找是否有这个id
        {
            j = i; //找到对应id在数组的位置，用j记录，
            break; //找到这个id后跳出循环
        }
    }
    if (j == -1)
    {
        return 0;
    }
    printf("要删除的学生信息如下：\n");
    findstu(m, id); //显示要删除的学生信息，防止误删，错删
    printf("确认要删除的信息，确认无误后输入1,删除这个信息..若不想删除，输入0，返回上一层，不进行删除\n");
    int fl;
    scanf("%d", &fl); //
    if (fl)
    {
        if (j != -1) //判断是否找到了对应id
        {
            for (j; j < m->size; j++)
            {
                m->me[j] = m->me[j + 1];
                //将所要删除的id后面的数据迁移一位，达到删除的目的
                //m是传入的结构指针，m->me[m->size]是manament结构中定义的student结构数组，m->size是当前系统中保存的学生信息的数目 ，通过数据向前移位来删除指定id处的数据
            }
            m->size--; //删除了一个学生的信息，学生数减少1位，size-1
            save(m);   //保存删除后的数组
            return 1;  //删除成功返回1
        }
        return 0; //删除失败返回0
    }
    return -1; //不进行删除返回-1
}
void findstu(struct manament *m, int id) //完成人：
{
    int j = -1;
    for (int i = 0; i < m->size; i++) //循环，遍历数组，查找是否有这个id
    {
        if (m->me[i].id == id)
        {
            j = i; //找到对应id在数组的位置，用j记录，
            break; //找到这个id后跳出循环
        }
    }
    if (j != -1) //判断是否找到了对应id
    {
        printf("学号:\t%d 姓名:\t%s 班级：%s 学期:%s 英语:\t%d 数学:\t%d C语言:\t%d 总分:\t%d\n ", m->me[j].id, m->me[j].name, m->me[j].class, m->me[j].semter, m->me[j].stugread.English, m->me[j].stugread.math, m->me[j].stugread.c, m->me[j].stugread.score); //输出对应id的学生信息
    }
    else
    {
        printf("查无此人\n"); //j=-1说明没说找到id所对应的人，
    }
}
void findallstu(struct manament *m) //显示所有的学生信息，完成人：董辰宇
{
    printf("学 号\t姓名\t   班   级\t  学  期\t英语\t数学\tC语言\t总分\n"); //打印表头

    for (int j = 0; j < m->size; j++) //循环结构体，输出
    {
        printf("%d\t%s\t %s\t %s\t%d\t%d\t%d\t%d\n", m->me[j].id, m->me[j].name, m->me[j].class, m->me[j].semter, m->me[j].stugread.English, m->me[j].stugread.math, m->me[j].stugread.c, m->me[j].stugread.score);
    }
}
void findclassstu(struct manament *m, char class[20], int see)
{
    printf("学 号\t姓名\t   班   级\t 学  期\t英语\t数学\tC语言\t总分\n"); //打印表头
    // printf("学 号\t姓名\t   班   级\t学  期\t英语\t数学\tC语言\t总分\t排名\n"); //打印表头
    int ii = 0;
    for (int j = 0; j < m->size; j++)
    {
        int a=5;
        int b=6;
        int c=6;
        a = strcmp(m->me[j].class, class);
        if (see == 1)
        {

            b = strcmp(m->me[j].semter, "第一学期");
        }
        else if (see == 2)
        {
            c = strcmp(m->me[j].semter, "第二学期");
        }

        {
            /* code */
        }

        if (a == 0 && b == 0 || a == 0 && c == 0)
        {
            ii++;
            printf("%d\t%s\t %s \t %s\t%d\t%d\t%d\t%d\t%d\n", m->me[j].id, m->me[j].name, m->me[j].class, m->me[j].semter, m->me[j].stugread.English, m->me[j].stugread.math, m->me[j].stugread.c, m->me[j].stugread.score, ii);
        }
    }
}
void savestu(struct manament *m) //完成人：王豪杰
{
    FILE *fp;         //创建文件指针
    if (m->size == 0) //判断是否已经有数据，有数据进行追加写入，无数据直接写入
    {
        if ((fp = fopen("managent.txt", "w")) == NULL) //判断文件是否打开失败
        {
            printf("文件打开失败"); //文件打开失败提示
            exit(0);                //退出系统
        }
    }
    else
    {
        if ((fp = fopen("managent.txt", "a")) == NULL) //判断函数是否打开失败
        {
            printf("文件打开失败"); //文件打开失败提示
            exit(0);                //退出系统
        }
    }
    fprintf(fp, "%d %s %s %s %d %d %d %d\n", m->me[m->size].id, m->me[m->size].name, m->me[m->size].class, m->me[m->size].semter, m->me[m->size].stugread.English, m->me[m->size].stugread.math, m->me[m->size].stugread.c, m->me[m->size].stugread.score); //fprint()函数将数据写入文件
    if (fclose(fp))                                                                                                                                                                                                                                         //文件关闭
    {
        printf("文件关闭失败，"); //文件打开失败提示
        exit(0);                  //退出系统
    }
}
void save(struct manament *m) //完成人：王豪杰
{
    FILE *fp;                                      //文件指针
    if ((fp = fopen("managent.txt", "w")) == NULL) //判断是否打开文件
    {
        printf("文件打开失败"); //文件打开失败提示
        exit(0);                //退出系统
    }
    for (int a = 0; a < m->size; a++) //把结构数组重新保存一遍
    {
        fprintf(fp, "%d %s %s %s %d %d %d %d\n", m->me[a].id, m->me[a].name, m->me[a].class, m->me[a].semter, m->me[a].stugread.English, m->me[a].stugread.math, m->me[a].stugread.c, m->me[a].stugread.score);
        //fprintf()函数格式化写进文件
    }

    if (fclose(fp)) //判断文件是否关闭
    {
        printf("文件关闭失败，"); //文件关闭失败提示
        exit(0);                  //退出系统
    }
}
void readstu(struct manament *m) //初始化读取文件，初始化数组，负责人：王豪杰
{
    FILE *fp;                                      //定义稳健指针
    if ((fp = fopen("managent.txt", "r")) == NULL) //判断是否打开
    {
        FILE *fp1;                                      //文件指针
        if ((fp1 = fopen("managent.txt", "w")) == NULL) //判断是否打开文件
        {
            printf("文件打开失败"); //文件打开失败提示
            exit(0);                //退出系统
        }
        fclose(fp1);
        //退出系统
        fp = fopen("managent.txt", "r");
    }
    while (fscanf(fp, "%d %s %s %s %d %d %d %d", &(m->me[m->size].id), m->me[m->size].name, &(m->me[m->size].class), &(m->me[m->size].semter), &(m->me[m->size].stugread.English), &(m->me[m->size].stugread.math), &(m->me[m->size].stugread.c), &(m->me[m->size].stugread.score)) > 0)
    //判断是否读到最后一位，每读一位保存在结构数组一位
    {
        m->size++;
    }

    if (fclose(fp)) //判断文件是否关闭
    {
        printf("文件关闭失败，"); //文件打开失败提示
        exit(0);                  //退出系统
    }
}
int ishaved(struct manament *m, int id) //判断id是否已经存在，存在返回1，不存在返回0，负责人：王豪杰
{
    int j = -1;
    for (int i = 0; i < m->size; i++) //循环，遍历数组，查找是否有这个id
    {
        if (m->me[i].id == id)
        {
            j = i; //找到对应id在数组的位置，用j记录，
            break; //找到这个id后跳出循环
        }
    }
    if (j == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void findscoreorder(struct manament *m, char class[20], char course[20],int see)
{
    int flag = 0;
    if (strcmp(course, "English") == 0 || strcmp(course, "english") == 0 || strcmp(course, "英语") == 0 || strcmp(course, "外") == 0 || strcmp(course, "E") == 0 || strcmp(course, "e") == 0)
    {
        flag = 1;
    }
    else if (strcmp(course, "Math") == 0 || strcmp(course, "math") == 0 || strcmp(course, "数学") == 0 || strcmp(course, "M") == 0 || strcmp(course, "m") == 0)
    {
        flag = 2;
    }
    else if (strcmp(course, "C语言") == 0 || strcmp(course, "C") == 0 || strcmp(course, "c") == 0)
    {
        flag = 3;
    }
    else if (strcmp(course, "总分") == 0)
    {
        flag = 4;
    }
    switch (flag)
    {
    case 1:
        findscoreEorder(m, class,see);
        break;
    case 2:
        findscoreMorder(m, class,see);
        break;
    case 3:
        findscoreCorder(m, class,see);
        break;
    case 4:
        findscoreSorder(m, class,see);
        break;
    default:
        printf("没有这个课程\n");
        break;
    }
}
void findscoreEorder(struct manament *m, char class[20], int see)
{
    for (int i = 0; i < m->size - 1; i++)
    {
        for (int j = 0; j < m->size - 1; j++)
        {
            if (m->me[j].stugread.English < m->me[j + 1].stugread.English) //根据成绩冒泡排序
            {
                struct student st;
                st = m->me[j];
                m->me[j] = m->me[j + 1];
                m->me[j + 1] = st;
            }
        }
    }
    findclassstu(m, class, see); //打印数据
    save(m);                     //保存数据
}
void findscoreMorder(struct manament *m, char class[20], int see)
{
    for (int i = 0; i < m->size - 1; i++)
    {
        for (int j = 0; j < m->size - 1; j++)
        {
            if (m->me[j].stugread.math < m->me[j + 1].stugread.math) //根据成绩冒泡排序
            {
                struct student st;
                st = m->me[j];
                m->me[j] = m->me[j + 1];
                m->me[j + 1] = st;
            }
        }
    }
    findclassstu(m, class, see); //打印数据
    save(m);
    //保存数据
}
void findscoreCorder(struct manament *m, char class[20], int see)
{
    for (int i = 0; i < m->size - 1; i++)
    {
        for (int j = 0; j < m->size - 1; j++)
        {
            if (m->me[j].stugread.c < m->me[j + 1].stugread.c) //根据成绩冒泡排序
            {
                struct student st;
                st = m->me[j];
                m->me[j] = m->me[j + 1];
                m->me[j + 1] = st;
            }
        }
    }
    findclassstu(m, class, see); //打印数据
    save(m);
    //保存数据
}
// void findscoreMorder(struct manament *m, char class[20])
// {
//     for (int i = 0; i < m->size - 1; i++)
//     {
//         for (int j = 0; j < m->size - 1; j++)
//         {
//             if (m->me[j].stugread.math < m->me[j + 1].stugread.math)
//             {
//                 struct student st;
//                 st = m->me[j];
//                 m->me[j] = m->me[j + 1];
//                 m->me[j + 1] = st;
//             }
//         }
//     }
//     findclassstu(m, class);
//     save(m);
// }
void findscoreSorder(struct manament *m, char class[20], int see)
{
    for (int i = 0; i < m->size - 1; i++)
    {
        for (int j = 0; j < m->size - 1; j++)
        {
            if (m->me[j].stugread.score < m->me[j + 1].stugread.score) //根据成绩冒泡排序
            {
                struct student st;
                st = m->me[j];
                m->me[j] = m->me[j + 1];
                m->me[j + 1] = st;
            }
        }
    }
    findclassstu(m, class, see); //打印数据
    save(m);
    //保存数据
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