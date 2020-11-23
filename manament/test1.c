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
void menu1() //�����棬�����ˣ�������
{
    int id = 0;
    struct manament stu, *st;
    initstu(&stu);
    readstu(&stu);
    int flag = 1;
    while (flag) //��ѭ��ȷ��ϵͳһֱ���У����˳�ϵͳʱflag=1,����ѭ��
    {
        printf("\t\t\tѧ���ɼ�����ϵͳ\n");
        printf("----------------------------------------------------------------\n");
        printf("   0:�˳�ϵͳ\t\t\t");
        printf("   1:���ѧ���ɼ�\n");
        printf("----------------------------------------------------------------\n");
        printf("   2:�޸�ѧ���ɼ�\t\t");
        printf("   3������ѧ���ɼ�\n");
        printf("----------------------------------------------------------------\n");
        printf("   4���鿴����ѧ���ɼ�\t\t");
        printf("   5��ɾ��ѧ���ɼ�\n");
        printf("----------------------------------------------------------------\n");
        printf("   6�����༶����ѧ���ɼ�\t");
        printf("   7���������ĳ��ĳ�γ̵ĳɼ���\n");
        printf("----------------------------------------------------------------\n");
        printf("\n��ѡ��������������Ĳ�����");
        int a;
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            system("CLS"); //system���������Ļ��
            addstu(&stu);
            break;
        case 2:
            /* code */
            system("CLS");    //system���������Ļ��
            findallstu(&stu); //��ʾ����ѧ��������֮˵����������ʾ����ѧ����Ϊ���޸ķ��㣬��ֹ�Ǵ�id;
            printf("��������Ҫ�޸ĳɼ���ѧ��id: (-1������һ��)\n");
            scanf("%d", &id);
            if (id >= 0)
            {
                updatestu(&stu, id); //�޸ĳɼ�����
            }
            id = 0;

            break;
        case 3:
            system("CLS"); //system���������Ļ��
            printf("��������Ҫ���ҵ�ѧ��id: (-1������һ��)\n");
            scanf("%d", &id);
            if (id >= 0)
            {
                findstu(&stu, id); //����findstu()��������ʾָ��id��ѧ����Ϣ
            }
            id = 0;
            break;
        case 4:
            system("CLS"); //system���������Ļ��
            printf("�鿴����ѧ���ɼ���\n");
            findallstu(&stu); //��ʾ����ѧ������Ϣ
            break;
        case 5:
            system("CLS");    //system���������Ļ��
            findallstu(&stu); //��ʾ����ѧ��������֮˵����������ʾ����ѧ����Ϊ��ɾ�����㣬��ֹ�Ǵ�id;
            printf("��������Ҫɾ����ѧ��id: (-1������һ��)\n");
            scanf("%d", &id); //����id
            if (id >= 0)
            {
                int shanchu = deletestu(&stu, id);
                if (shanchu == 1)
                {
                    printf("ɾ���ɹ�\n");
                }
                else if (shanchu == 0)
                {
                    // system("CLS"); //system���������Ļ��

                    printf("���޴���\n");
                }
                else
                {
                    printf("�˳���������ɾ��\n");
                }
            }
            id = 0;
            /* code */
            break;
        case 6:
            system("CLS"); //system���������Ļ��
            printf("������༶��\n");
            char cla[20];

            scanf("%s", cla);
            int see;
            do
            {
                printf("������ѧ�� ����һѧ������1���ڶ���ѧ������2����\n");
                scanf("%d", &see);
            } while (see < 1 || see > 2);
            findclassstu(&stu, cla, see);
            break;
        case 0:
            system("CLS"); //system���������Ļ��
            printf("ллʹ�ã���ӭ�´ι��٣�");
            flag = 0; //flag=0,������ѭ��������������ѭ����
            break;
        case 7:
            system("CLS"); //system���������Ļ��
            printf("�������ĳ��ĳ�γ̵ĳɼ���\n");
            printf("������༶\n");
            char clas[20];
            int see1=0;
          scanf("%s", clas);
            do
            {
                printf("������ѧ�� ����һѧ������1���ڶ���ѧ������2����\n");
                scanf("%d", &see1);
            } while (see1 < 1 || see1 > 2);
            printf("��������Ҫ����Ŀγ����ƣ�Ҳ�ɰ����롰�ܷ֡������ܷ���������γ����Ŀ���Ϊ����ȫ�ơ�Ӣ��ȫ�ƻ���Ӣ�ĵ�����ĸ����Сд�����ԣ�\n");
            char co[20];
            scanf("%s", co);
            findscoreorder(&stu, clas, co, see1);
            break;
        default:
            system("CLS"); //system���������Ļ��
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
    system("pause"); //vscode��ֹ�������һ��������
    return 0;
}
void initstu(struct manament *m) //��ʼ�����麯��������ˣ�������
{                                //��ʼ��
    if (m->size == MAX)
    {
        return;
    }
    else
    {
        memset(m->me, 0, sizeof(m->me)); //ʹ��string.h�е�mamect()�������ṹ��������г�ʼ��Ϊ0
    }
    m->size = 0; //size��ʼ��Ϊ0
}
void addstu(struct manament *m) //��Ӻ���������ˣ����
{
    printf("���ѧ���ɼ���\n");
    printf("������ѧ��ѧ��(��λ����))��\n");
    int id, tu;
    while (scanf("%d", &id))
    {
        if (ishaved(m, id)) //�жϣ�id�Ƿ��Ѵ��ڣ����ڷ���1�������ڷ���0
        {
            printf("ѧ���Ѵ��ڣ���ѡ��1���������룬0���˳�����\n");
            scanf("%d", &tu);
            if (tu) //�ж�tu,tu=1��������,�����˳��ú���
            {
                printf("������ѧ��ѧ�ţ�\n");
                continue;
            }
            else
            {
                printf("�˳���Ӻ���\n");
                return;
            }
        }
        break;
    }

    // do
    // {
    //     scanf("%d", &id);
    // } while (ishaved(m, id));
    m->me[m->size].id = id; //m�Ǵ���Ľṹָ�룬m->me[m->size]��manament�ṹ�ж����student�ṹ���飬m->size�ǵ�ǰϵͳ�б����ѧ����Ϣ����Ŀ ,m->me[m->size].semter��manament�ṹ�ж����student�ṹ�����ж����ѧ��
    printf("������ѧ������\n");
    scanf("%s", m->me[m->size].name); // //m�Ǵ���Ľṹָ�룬m->me[m->size]��manament�ṹ�ж����student�ṹ���飬m->size�ǵ�ǰϵͳ�б����ѧ����Ϣ����Ŀ ,m->me[m->size].semter��manament�ṹ�ж����student�ṹ�����ж����ѧ��
    printf("������ѧ���İ༶��רҵ+�༶����\n");
    scanf("%s", (m->me[m->size].class)); //m�Ǵ���Ľṹָ�룬m->me[m->size]��manament�ṹ�ж����student�ṹ���飬m->size�ǵ�ǰϵͳ�б����ѧ����Ϣ����Ŀ ,m->me[m->size].semter��manament�ṹ�ж����student�ṹ�����ж����ѧ��
    printf("�����뿼��ѧ�ڣ���һѧ������1���ڶ�ѧ������2����\n");
    int se;
    char a[20];                                 //ѧ��
    while (scanf("%d", &se), se>2 || se<1) //�ж���������Ƿ���ϳ���
    {
        printf("����������\n");
    }
    if (se == 1)
    {
        strcpy(m->me[m->size].semter, "��һѧ��");
    }
    else if (se == 2)
    {
        strcpy(m->me[m->size].semter, "�ڶ�ѧ��");
    }
    //m�Ǵ���Ľṹָ�룬m->me[m->size]��manament�ṹ�ж����student�ṹ���飬m->size�ǵ�ǰϵͳ�б����ѧ����Ϣ����Ŀ ,m->me[m->size].semter��manament�ṹ�ж����student�ṹ�����ж����ѧ��
    printf("������ѧ����Ӣ��ɼ���\n");
    int en;                                      //Ӣ�����
    while (scanf("%d", &en), en > 100 || en < 0) //�ж�Ӣ��ɼ������Ƿ��ڷ�Χ��
    {
        printf("Ӣ������ֻ��100��,���0�֣�������������\n");
    }
    m->me[m->size].stugread.English = en; //m�Ǵ���Ľṹָ�룬m->me[m->size]��manament�ṹ�ж����student�ṹ���飬m->size�ǵ�ǰϵͳ�б����ѧ����Ϣ����Ŀ ,m->me[m->size].stugread.c��manament�ṹ�ж����student�ṹ�����ж����gread�ṹ�е�Ӣ��ɼ�
    printf("������ѧ������ѧ�ɼ���\n");
    int mt;                                      //��ѧ����
    while (scanf("%d", &mt), mt > 100 || mt < 0) //�ж���ѧ�ɼ������Ƿ��ڷ�Χ��
    {
        printf("��ѧ����ֻ��100��,���0������������\n");
    }
    m->me[m->size].stugread.math = mt; //m�Ǵ���Ľṹָ�룬m->me[m->size]��manament�ṹ�ж����student�ṹ���飬m->size�ǵ�ǰϵͳ�б����ѧ����Ϣ����Ŀ ,m->me[m->size].stugread.math��manament�ṹ�ж����student�ṹ�����ж����gread�ṹ�е���ѧ�ɼ�
    printf("������ѧ����C���Գɼ���\n");
    int c;
    while (scanf("%d", &c), c > 100 || c < 0) //�ж�c���Գɼ������Ƿ��ڷ�Χ��
    {
        printf("C��������ֻ��100��,���0������������\n");
    }
    m->me[m->size].stugread.c = c;               //m�Ǵ���Ľṹָ�룬m->me[m->size]��manament�ṹ�ж����student�ṹ���飬m->size�ǵ�ǰϵͳ�б����ѧ����Ϣ����Ŀ ,m->me[m->size].stugread.c��manament�ṹ�ж����student�ṹ�����ж����gread�ṹ�е�c���Գɼ�
    m->me[m->size].stugread.score = c + mt + en; //�ܳɼ�
    // m->me[m->size].stugread.score = m->me[m->size].stugread.c + m->me[m->size].stugread.math + m->me[m->size].stugread.English; //�����ܷ�
    savestu(m); //���ñ��溯��
    m->size++;  //��Ӻ�size��һ
    // system("CLS"); //system���������Ļ�� //������
    printf("��ӳɹ�\n");
}
int updatestu(struct manament *m, int id) //���³ɼ�����������ˣ����
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
    if (j == -1)
    {
        printf("���޴���\n");
        return 0;
    }
    findstu(m, id); //����find()������m�Ǵ������ʾҪ���ĵ�ѧ������Ϣ�����ײ�����
    printf("�����µ�Ӣ��ɼ�,�粻���ģ�������-1��\n");
    int Eng;
    while (scanf("%d", &Eng), Eng > 100) //�жϸ��ĵ�Ӣ��ɼ��Ƿ񳬳���Χ����ʧ�󽫳ɼ���Ϊ������ϵͳ����������
    {
        printf("Ӣ��ɼ�����100��������ٴ�����,�粻���ģ�������-1��\n");
    }
    if (Eng >= 0)
    {
        m->me[j].stugread.English = Eng; //m�Ǵ���Ľṹָ�룬m->me[m->size]��manament�ṹ�ж����student�ṹ���飬m->size�ǵ�ǰϵͳ�б����ѧ����Ϣ����Ŀ ,m->me[m->size].English��manament�ṹ�ж����student�ṹ�����ж����Ӣ��ɼ�
    }
    printf("�����µ���ѧ�ɼ�,�粻���ģ�������-1��\n");
    int M;
    while (scanf("%d", &M), M > 100) //�жϸ��ĵĳɼ��Ƿ񳬳���Χ����ʧ�󽫳ɼ���Ϊ������ϵͳ����������
    {
        printf("��ѧ�ɼ�����100��������ٴ�����,�粻���ģ�������-1��\n");
    }
    if (M >= 0)
    {
        m->me[j].stugread.math = M; //m�Ǵ���Ľṹָ�룬m->me[m->size]��manament�ṹ�ж����student�ṹ���飬m->size�ǵ�ǰϵͳ�б����ѧ����Ϣ����Ŀ ,m->me[m->size].math��manament�ṹ�ж����student�ṹ�����ж������ѧ�ɼ�
    }
    printf("�����µ�C���Գɼ�,�粻���ģ�������-1��\n");
    int C;
    while (scanf("%d", &C), C > 100)
    //�жϸ��ĵĳɼ��Ƿ񳬳���Χ����ʧ�󽫳ɼ���Ϊ������ϵͳ����������
    {
        printf("C���Գɼ�����100����������ٴ�����,�粻���ģ�������-1��\n");
    }
    if (C >= 0)
    {
        m->me[j].stugread.c = C; //m�Ǵ���Ľṹָ�룬m->me[m->size]��manament�ṹ�ж����student�ṹ���飬m->size�ǵ�ǰϵͳ�б����ѧ����Ϣ����Ŀ ,m->me[m->size].c��manament�ṹ�ж����student�ṹ�����ж����c���Գɼ�
    }
    m->me[j].stugread.score = m->me[j].stugread.c + m->me[j].stugread.math + m->me[j].stugread.English; //�����ܷ�
    printf("���ĳɹ���\n");
    save(m); //����ɾ���������
}
int deletestu(struct manament *m, int id) //����idɾ��ѧ����Ϣ������ˣ�������
{
    int j = -1;
    for (int i = 0; i < m->size; i++)
    {
        if (m->me[i].id == id) //ѭ�����������飬�����Ƿ������id
        {
            j = i; //�ҵ���Ӧid�������λ�ã���j��¼��
            break; //�ҵ����id������ѭ��
        }
    }
    if (j == -1)
    {
        return 0;
    }
    printf("Ҫɾ����ѧ����Ϣ���£�\n");
    findstu(m, id); //��ʾҪɾ����ѧ����Ϣ����ֹ��ɾ����ɾ
    printf("ȷ��Ҫɾ������Ϣ��ȷ�����������1,ɾ�������Ϣ..������ɾ��������0��������һ�㣬������ɾ��\n");
    int fl;
    scanf("%d", &fl); //
    if (fl)
    {
        if (j != -1) //�ж��Ƿ��ҵ��˶�Ӧid
        {
            for (j; j < m->size; j++)
            {
                m->me[j] = m->me[j + 1];
                //����Ҫɾ����id���������Ǩ��һλ���ﵽɾ����Ŀ��
                //m�Ǵ���Ľṹָ�룬m->me[m->size]��manament�ṹ�ж����student�ṹ���飬m->size�ǵ�ǰϵͳ�б����ѧ����Ϣ����Ŀ ��ͨ��������ǰ��λ��ɾ��ָ��id��������
            }
            m->size--; //ɾ����һ��ѧ������Ϣ��ѧ��������1λ��size-1
            save(m);   //����ɾ���������
            return 1;  //ɾ���ɹ�����1
        }
        return 0; //ɾ��ʧ�ܷ���0
    }
    return -1; //������ɾ������-1
}
void findstu(struct manament *m, int id) //����ˣ�
{
    int j = -1;
    for (int i = 0; i < m->size; i++) //ѭ�����������飬�����Ƿ������id
    {
        if (m->me[i].id == id)
        {
            j = i; //�ҵ���Ӧid�������λ�ã���j��¼��
            break; //�ҵ����id������ѭ��
        }
    }
    if (j != -1) //�ж��Ƿ��ҵ��˶�Ӧid
    {
        printf("ѧ��:\t%d ����:\t%s �༶��%s ѧ��:%s Ӣ��:\t%d ��ѧ:\t%d C����:\t%d �ܷ�:\t%d\n ", m->me[j].id, m->me[j].name, m->me[j].class, m->me[j].semter, m->me[j].stugread.English, m->me[j].stugread.math, m->me[j].stugread.c, m->me[j].stugread.score); //�����Ӧid��ѧ����Ϣ
    }
    else
    {
        printf("���޴���\n"); //j=-1˵��û˵�ҵ�id����Ӧ���ˣ�
    }
}
void findallstu(struct manament *m) //��ʾ���е�ѧ����Ϣ������ˣ�������
{
    printf("ѧ ��\t����\t   ��   ��\t  ѧ  ��\tӢ��\t��ѧ\tC����\t�ܷ�\n"); //��ӡ��ͷ

    for (int j = 0; j < m->size; j++) //ѭ���ṹ�壬���
    {
        printf("%d\t%s\t %s\t %s\t%d\t%d\t%d\t%d\n", m->me[j].id, m->me[j].name, m->me[j].class, m->me[j].semter, m->me[j].stugread.English, m->me[j].stugread.math, m->me[j].stugread.c, m->me[j].stugread.score);
    }
}
void findclassstu(struct manament *m, char class[20], int see)
{
    printf("ѧ ��\t����\t   ��   ��\t ѧ  ��\tӢ��\t��ѧ\tC����\t�ܷ�\n"); //��ӡ��ͷ
    // printf("ѧ ��\t����\t   ��   ��\tѧ  ��\tӢ��\t��ѧ\tC����\t�ܷ�\t����\n"); //��ӡ��ͷ
    int ii = 0;
    for (int j = 0; j < m->size; j++)
    {
        int a=5;
        int b=6;
        int c=6;
        a = strcmp(m->me[j].class, class);
        if (see == 1)
        {

            b = strcmp(m->me[j].semter, "��һѧ��");
        }
        else if (see == 2)
        {
            c = strcmp(m->me[j].semter, "�ڶ�ѧ��");
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
void savestu(struct manament *m) //����ˣ�������
{
    FILE *fp;         //�����ļ�ָ��
    if (m->size == 0) //�ж��Ƿ��Ѿ������ݣ������ݽ���׷��д�룬������ֱ��д��
    {
        if ((fp = fopen("managent.txt", "w")) == NULL) //�ж��ļ��Ƿ��ʧ��
        {
            printf("�ļ���ʧ��"); //�ļ���ʧ����ʾ
            exit(0);                //�˳�ϵͳ
        }
    }
    else
    {
        if ((fp = fopen("managent.txt", "a")) == NULL) //�жϺ����Ƿ��ʧ��
        {
            printf("�ļ���ʧ��"); //�ļ���ʧ����ʾ
            exit(0);                //�˳�ϵͳ
        }
    }
    fprintf(fp, "%d %s %s %s %d %d %d %d\n", m->me[m->size].id, m->me[m->size].name, m->me[m->size].class, m->me[m->size].semter, m->me[m->size].stugread.English, m->me[m->size].stugread.math, m->me[m->size].stugread.c, m->me[m->size].stugread.score); //fprint()����������д���ļ�
    if (fclose(fp))                                                                                                                                                                                                                                         //�ļ��ر�
    {
        printf("�ļ��ر�ʧ�ܣ�"); //�ļ���ʧ����ʾ
        exit(0);                  //�˳�ϵͳ
    }
}
void save(struct manament *m) //����ˣ�������
{
    FILE *fp;                                      //�ļ�ָ��
    if ((fp = fopen("managent.txt", "w")) == NULL) //�ж��Ƿ���ļ�
    {
        printf("�ļ���ʧ��"); //�ļ���ʧ����ʾ
        exit(0);                //�˳�ϵͳ
    }
    for (int a = 0; a < m->size; a++) //�ѽṹ�������±���һ��
    {
        fprintf(fp, "%d %s %s %s %d %d %d %d\n", m->me[a].id, m->me[a].name, m->me[a].class, m->me[a].semter, m->me[a].stugread.English, m->me[a].stugread.math, m->me[a].stugread.c, m->me[a].stugread.score);
        //fprintf()������ʽ��д���ļ�
    }

    if (fclose(fp)) //�ж��ļ��Ƿ�ر�
    {
        printf("�ļ��ر�ʧ�ܣ�"); //�ļ��ر�ʧ����ʾ
        exit(0);                  //�˳�ϵͳ
    }
}
void readstu(struct manament *m) //��ʼ����ȡ�ļ�����ʼ�����飬�����ˣ�������
{
    FILE *fp;                                      //�����Ƚ�ָ��
    if ((fp = fopen("managent.txt", "r")) == NULL) //�ж��Ƿ��
    {
        FILE *fp1;                                      //�ļ�ָ��
        if ((fp1 = fopen("managent.txt", "w")) == NULL) //�ж��Ƿ���ļ�
        {
            printf("�ļ���ʧ��"); //�ļ���ʧ����ʾ
            exit(0);                //�˳�ϵͳ
        }
        fclose(fp1);
        //�˳�ϵͳ
        fp = fopen("managent.txt", "r");
    }
    while (fscanf(fp, "%d %s %s %s %d %d %d %d", &(m->me[m->size].id), m->me[m->size].name, &(m->me[m->size].class), &(m->me[m->size].semter), &(m->me[m->size].stugread.English), &(m->me[m->size].stugread.math), &(m->me[m->size].stugread.c), &(m->me[m->size].stugread.score)) > 0)
    //�ж��Ƿ�������һλ��ÿ��һλ�����ڽṹ����һλ
    {
        m->size++;
    }

    if (fclose(fp)) //�ж��ļ��Ƿ�ر�
    {
        printf("�ļ��ر�ʧ�ܣ�"); //�ļ���ʧ����ʾ
        exit(0);                  //�˳�ϵͳ
    }
}
int ishaved(struct manament *m, int id) //�ж�id�Ƿ��Ѿ����ڣ����ڷ���1�������ڷ���0�������ˣ�������
{
    int j = -1;
    for (int i = 0; i < m->size; i++) //ѭ�����������飬�����Ƿ������id
    {
        if (m->me[i].id == id)
        {
            j = i; //�ҵ���Ӧid�������λ�ã���j��¼��
            break; //�ҵ����id������ѭ��
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
    if (strcmp(course, "English") == 0 || strcmp(course, "english") == 0 || strcmp(course, "Ӣ��") == 0 || strcmp(course, "��") == 0 || strcmp(course, "E") == 0 || strcmp(course, "e") == 0)
    {
        flag = 1;
    }
    else if (strcmp(course, "Math") == 0 || strcmp(course, "math") == 0 || strcmp(course, "��ѧ") == 0 || strcmp(course, "M") == 0 || strcmp(course, "m") == 0)
    {
        flag = 2;
    }
    else if (strcmp(course, "C����") == 0 || strcmp(course, "C") == 0 || strcmp(course, "c") == 0)
    {
        flag = 3;
    }
    else if (strcmp(course, "�ܷ�") == 0)
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
        printf("û������γ�\n");
        break;
    }
}
void findscoreEorder(struct manament *m, char class[20], int see)
{
    for (int i = 0; i < m->size - 1; i++)
    {
        for (int j = 0; j < m->size - 1; j++)
        {
            if (m->me[j].stugread.English < m->me[j + 1].stugread.English) //���ݳɼ�ð������
            {
                struct student st;
                st = m->me[j];
                m->me[j] = m->me[j + 1];
                m->me[j + 1] = st;
            }
        }
    }
    findclassstu(m, class, see); //��ӡ����
    save(m);                     //��������
}
void findscoreMorder(struct manament *m, char class[20], int see)
{
    for (int i = 0; i < m->size - 1; i++)
    {
        for (int j = 0; j < m->size - 1; j++)
        {
            if (m->me[j].stugread.math < m->me[j + 1].stugread.math) //���ݳɼ�ð������
            {
                struct student st;
                st = m->me[j];
                m->me[j] = m->me[j + 1];
                m->me[j + 1] = st;
            }
        }
    }
    findclassstu(m, class, see); //��ӡ����
    save(m);
    //��������
}
void findscoreCorder(struct manament *m, char class[20], int see)
{
    for (int i = 0; i < m->size - 1; i++)
    {
        for (int j = 0; j < m->size - 1; j++)
        {
            if (m->me[j].stugread.c < m->me[j + 1].stugread.c) //���ݳɼ�ð������
            {
                struct student st;
                st = m->me[j];
                m->me[j] = m->me[j + 1];
                m->me[j + 1] = st;
            }
        }
    }
    findclassstu(m, class, see); //��ӡ����
    save(m);
    //��������
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
            if (m->me[j].stugread.score < m->me[j + 1].stugread.score) //���ݳɼ�ð������
            {
                struct student st;
                st = m->me[j];
                m->me[j] = m->me[j + 1];
                m->me[j + 1] = st;
            }
        }
    }
    findclassstu(m, class, see); //��ӡ����
    save(m);
    //��������
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