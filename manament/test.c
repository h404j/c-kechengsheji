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
            findallstu(&stu);
            printf("��������Ҫ�޸ĳɼ���ѧ��id: (-1������һ��)\n");
            scanf("%d", &id);
            if (id >= 0)
            {
                updatestu(&stu, id);
            }
            id = 0;

            break;
        case 3:
            system("CLS");
            printf("��������Ҫ���ҵ�ѧ��id: (-1������һ��)\n");
            scanf("%d", &id);
            if (id >= 0)
            {
                findstu(&stu, id);
            }
            id = 0;
            break;
        case 4:
            system("CLS");
            printf("�鿴����ѧ���ɼ���\n");
            findallstu(&stu);
            break;
        case 5:
            system("CLS");
            findallstu(&stu);
            printf("��������Ҫɾ����ѧ��id: (-1������һ��)\n");
            scanf("%d", &id);
            if (id >= 0)
            {
                if (deletestu(&stu, id))
                {
                    printf("ɾ���ɹ�\n");
                }
                else
                {
                    printf("���޴���\n");
                }
            }

            id = 0;
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
    m->size = 0;
}
void addstu(struct manament *m)
{
    printf("���ѧ���ɼ���\n");
    printf("������ѧ��ѧ�ţ�\n");
    scanf("%d", &(m->me[m->size].id));
    printf("������ѧ������\n");
    scanf("%s", m->me[m->size].name); //����
    printf("������ѧ���İ༶��\n");
    scanf("%d", &(m->me[m->size].class));
    printf("�����뿼��ѧ�ڣ�\n");
    int se;
    while (scanf("%d", &se), se > 2)
    {
        printf("ֻ������ѧ�ڣ�����������\n");
    }
    m->me[m->size].semter = se;
    printf("������ѧ����Ӣ��ɼ���\n");
    int en;
    while (scanf("%d", &en), en > 100)
    {
        printf("Ӣ������ֻ��100������������\n");
    }
    m->me[m->size].stugread.English = en;
    printf("������ѧ������ѧ�ɼ���\n");
    int mt;
    while (scanf("%d", &mt), mt > 100)
    {
        printf("��ѧ����ֻ��100������������\n");
    }
    m->me[m->size].stugread.math = mt;
    printf("������ѧ����c���Գɼ���\n");
    int c;
    while (scanf("%d", &c), c > 100)
    {
        printf("c��������ֻ��100������������\n");
    }
    m->me[m->size].stugread.c = c;
    m->me[m->size].stugread.score = c + mt + en;
    // m->me[m->size].stugread.score = m->me[m->size].stugread.c + m->me[m->size].stugread.math + m->me[m->size].stugread.English; //�����ܷ�
    savestu(m);
    m->size++;
    system("CLS"); //������
    printf("��ӳɹ�\n");
}
int updatestu(struct manament *m, int id)
{

    int j = -1;
    for (int i = 0; i < m->size; i++)
    {
        if (m->me[i].id == id)
        {
            j = i; //�ҵ���Ӧid�������λ�ã���j��¼��
            break;
        }
    }
    printf("�����µ�Ӣ��ɼ�,�粻���ģ�������-1��\n");
    int Eng;
    while (scanf("%d", &Eng), Eng > 100)
    {
        printf("Ӣ��ɼ�����100��������ٴ�����\n");
    }
    if (Eng >= 0)
    {
        m->me[j].stugread.English = Eng;
    }
    printf("�����µ���ѧ�ɼ�,�粻���ģ�������-1��\n");
    int M;
    while (scanf("%d", &M), M > 100)
    {
        printf("Ӣ��ɼ�����100��������ٴ�����\n");
    }
    if (Eng >= 0)
    {
        m->me[j].stugread.English = Eng;
    }
    printf("�����µ�c���Գɼ�,�粻���ģ�������-1��\n");
    int C;
    while (scanf("%d", &C), C > 100)
    {
        printf("Ӣ��ɼ�����100��������ٴ�����\n");
    }
    if (C >= 0)
    {
        m->me[j].stugread.c = C;
    }
    printf("���ĳɹ���");
    save(m); //����ɾ���������
}
int deletestu(struct manament *m, int id)
{
    findstu(m, id);
    int j = -1;
    for (int i = 0; i < m->size; i++)
    {
        if (m->me[i].id == id)
        {
            j = i; //�ҵ���Ӧid�������λ�ã���j��¼��
            break;
        }
    }
    if (j != -1)
    {
        for (j; j < m->size; j++)
        {
            m->me[j] = m->me[j + 1]; //����Ҫɾ����id���������Ǩ��һλ���ﵽɾ����Ŀ��
        }
        m->size--;
        save(m); //����ɾ���������
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
            j = i; //�ҵ���Ӧid�������λ�ã���j��¼�����·����
            break;
        }
    }
    if (j != -1)
    {
        printf("ѧ��:%-4d ����:%-4s �༶��%-3d ѧ��:%-3d Ӣ��:%-3d ��ѧ:%-3d c����:%-3d �ܷ�:%-3d\n ", m->me[j].id, m->me[j].name, m->me[j].class, m->me[j].semter, m->me[j].stugread.English, m->me[j].stugread.math, m->me[j].stugread.c, m->me[j].stugread.score);
    }
    else
    {
        printf("���޴���\n");
    }
}
void findallstu(struct manament *m)
{
    printf("    ѧ��   ����   �༶   ѧ��   Ӣ��   ��ѧ   c����   �ܷ�\n");
    for (int j = 0; j < m->size; j++) //ѭ���ṹ�壬���
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
void save(struct manament *m)
{
    FILE *fp;
    if ((fp = fopen("managent.txt", "w")) == NULL)
    {
        printf("�ļ���ʧ��");
        exit(0);
    }
    for (int a = 0; a < m->size; a++)
    {
        fprintf(fp, "%d %s %d %d %d %d %d %d\n", m->me[a].id, m->me[a].name, m->me[a].class, m->me[a].semter, m->me[a].stugread.English, m->me[a].stugread.math, m->me[a].stugread.c, m->me[a].stugread.score);
    }

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