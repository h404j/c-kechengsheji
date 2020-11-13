#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
struct gread
{
    int English; //英�??成绩
    int c;       //c�?言成绩
    int math;    //数�?�成�?
    int score;   //学期总分
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
    while (flag) //��ѭ��ȷ��ϵͳһֱ���У����˳�ϵͳʱflag=1,����ѭ��
    {
        printf("----------------------ѧ���ɼ�����ϵͳ-----------------\n");
        printf("------------------1:���ѧ���ɼ�-----------------------\n");
        printf("------------------2:�޸�ѧ���ɼ�-----------------------\n");
        printf("------------------3������ѧ���ɼ�----------------------\n");
        printf("------------------4���鿴����ѧ���ɼ�-------------------\n");
        printf("------------------5��ɾ��ѧ���ɼ�-----------------------\n");
        printf("------------------6���˳�ϵͳ---------------------------\n");
        printf("��ѡ��������������Ĳ�����");
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
            printf("�޸�ѧ���ɼ���");
            break;
        case 3:
            system("CLS");
            printf("����ѧ���ɼ���\n");
            /* code */
            break;
        case 4:
            system("CLS");
            printf("�鿴����ѧ���ɼ���\n");
            /* code */
            break;
        case 5:
            system("CLS");
            printf("ɾ��ѧ���ɼ���\n");
            /* code */
            break;
        case 6:
            system("CLS");
            printf("ллʹ�ã���ӭ�´ι��٣�");
            flag = 0;
            break;
        default:
            system("CLS");
            printf("����������������룡\n");
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
    printf("���ѧ���ɼ���\n");
    printf("������ѧ��ѧ�ţ�\n");
    scanf("%d", &(m->me[m->size].id));
    printf("������ѧ������\n");
    scanf("%s", m->me[m->size].name);
    printf("������ѧ���İ༶��\n");
    scanf("%d", &(m->me[m->size].class));
    printf("�����뿼��ѧ�ڣ�\n");
    scanf("%d", &(m->me[m->size].semter));
    printf("������ѧ����Ӣ��ɼ���\n");
    scanf("%d", &(m->me[m->size].stugread.English));
    printf("������ѧ������ѧ�ɼ���\n");
    scanf("%d", &(m->me[m->size].stugread.math));
    printf("������ѧ����c���Գɼ���\n");
    scanf("%d", &(m->me[m->size].stugread.c));
    m->me[m->size].stugread.score = m->me[m->size].stugread.c + m->me[m->size].stugread.math + m->me[m->size].stugread.English;
    savestu(m);
    m->size++;
    system("CLS");
    printf("��ӳɹ�\n");
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
            printf("�ļ���ʧ��");
            exit(0);
        }
    }
    else
    {
        if ((fp = fopen("managent.txt", "a")) == NULL)
        {
            printf("�ļ���ʧ��");
            exit(0);
        }
    }
    fprintf(fp, "%d %s %d %d %d %d %d %d\n", m->me[m->size].id, m->me[m->size].name, m->me[m->size].class, m->me[m->size].semter, m->me[m->size].stugread.English, m->me[m->size].stugread.math, m->me[m->size].stugread.c, m->me[m->size].stugread.score);
    if (fclose(fp))
    {
        printf("�ļ��ر�ʧ�ܣ�");
        exit(0);
    }
}
void readstu(struct manament *m)
{
    FILE *fp;
    if ((fp = fopen("managent.txt", "r")) == NULL)
    {
        printf("�ļ���ʧ��");
        exit(0);
    }
    while (fscanf(fp, "%d %s %d %d %d %d %d %d", &(m->me[m->size].id), m->me[m->size].name, &(m->me[m->size].class), &(m->me[m->size].semter), &(m->me[m->size].stugread.English), &(m->me[m->size].stugread.math), &(m->me[m->size].stugread.c), &(m->me[m->size].stugread.score)) > 0)
    {
        m->size++;
    }

    if (fclose(fp))
    {
        printf("�ļ��ر�ʧ�ܣ�");
        exit(0);
    }
}
// void readstu(struct manament *m)
// {
//     FILE *fp;
//         if ((fp = fopen("managent.txt", "r")) == NULL)
//         {
//             printf("�ļ���ʧ��");
//             exit(0);
//         }
//     // fprintf(fp, "%d %s %d %d %d %d %d %d", m->me[m->size].id, m->me[m->size].name, m->me[m->size].class, m->me[m->size].semter, m->me[m->size].stugread.English, m->me[m->size].stugread.math, m->me[m->size].stugread.c, m->me[m->size].stugread.score);
//     fread(m,sizeof(m),1,fp);
//     if (fclose(fp))
//     {
//         printf("�ļ��ر�ʧ�ܣ�");
//         exit(0);
//     }
// }
// void exitsavestu(struct manament *m)
// {
//     FILE *fp;
//     if ((fp = fopen("managent.txt", "w")) == NULL)
//     {
//         printf("�ļ���ʧ��");
//         exit(0);
//     }
//     // fprintf(fp, "%d %s %d %d %d %d %d %d", m->me[m->size].id, m->me[m->size].name, m->me[m->size].class, m->me[m->size].semter, m->me[m->size].stugread.English, m->me[m->size].stugread.math, m->me[m->size].stugread.c, m->me[m->size].stugread.score);
//     fwrite(m, sizeof(m), 1, fp);
//     if (fclose(fp))
//     {
//         printf("�ļ��ر�ʧ�ܣ�");
//         exit(0);
//     }
// }