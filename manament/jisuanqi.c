
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265358979323846264338327
#define MAX 20
#define e 2.71828
//���ؽ����������Ҫ�����ָ��
void InitNews()
{
    printf("**********************\n");
    printf("��ѡ������Ҫ�����ģ�飺\n");
    printf("**********************\n");
}
//�ӷ�
void Sum(double x, double y)
{

    double result = x + y;
    printf("%.2lf+%.2lf=%.2lf\n", x, y, result); //������λС��
    printf("\n");
}
//����
void Cut(double x, double y)
{
    double result = x - y;
    printf("%.2lf-%.2lf=%.2lf\n", x, y, result);
}
//�˷�
void Multiply(double x, double y)
{
    double result = x * y;
    printf("%.2lf*%.2lf=%.2lf\n", x, y, result);
}
//����
void Divide(double x, double y)
{
    double result = x / y;
    printf("%.2lf/%.2lf=%.2lf\n", x, y, result);
}
//����sinx��Ҳ�������Һ���
void CalculateSinx(double n)
{
    double s;

    s = sin(n * 2 * pi / 360);         //��n��sin()ֵ�������ظ�n
    printf("sin %f = %.15lf\n", n, s); //���
}
//����cosx��Ҳ�������Һ���
void CalculateCosx(double n)
{
    double c;

    c = cos(n * 2 * pi / 360);         //��n��cos()ֵ�������ظ�n
    printf("cos %f = %.15lf\n", n, c); //���
}
//����tanx��Ҳ�������к���
void CalculateTanx(double n)
{
    double t;

    t = tan(n * 2 * pi / 360);         //��n��tan()ֵ�������ظ�n
    printf("tan %f = %.15lf\n", n, t); //���
}
//����arcsin�������Һ���
void CalculateArcSinx(double n)
{
    double t;

    t = asin(n);
    printf("arcsin %f = %.15lf\n", n, t); //���
}
//����arccos,�����Һ���
void CalculateArcCosx(double n)
{
    double t;

    t = acos(n);
    printf("acos %f = %.15lf\n", n, t); //���
}
//����arctan�������к���
void CalculateArcTanx(double n)
{
    double t;

    t = atan(n);
    printf("atan %f = %.15lf\n", n, t); //���
}
//����������Lnx ������eΪ��x�Ķ���
void CalculateLnx()
{
    double n, res;
    scanf("%lf", &n);
    res = log(n);
    printf("��eΪ��%lf�Ķ�����%.2lf\n", n, res);
}
//����������log10(x)��10Ϊ��x�Ķ���
void CalculateLogx()
{
    double n, res;
    scanf("%lf", &n);
    res = log10(n);
    printf("��10Ϊ��%lf�Ķ�����%.2lf\n", n, res);
}
//����e^x   eԼ���ڣ�2.7182818
void CalculateEX()
{
    double n, res;
    scanf("%lf", &n);
    res = pow(e, n);

    printf("e^%f = %f\n", n, res);
}
//����ƽ���������磺4��ƽ������2
void CalculateSquareroot()
{
    double n, res;
    scanf("%lf", &n);
    res = sqrt(n);
    printf("%lf��ƽ������%.2lf\n", n, res);
}
//����x^y������x��y�η�������2��2�η���4
void CalculateXY()
{
    double x, y, result;
    scanf("%lf %lf", &x, &y);
    result = pow(x, y);
    printf("x^y = %.2lf\n", result);
}
//������������  nΪ�û������ָ��
//n=1�����ӷ�����
//n=2������������
//n=3�����˷�����
//n=4������������
void BasicOperations(int n)
{
    printf("��ѡ������Ҫ��������֣�\n");
    printf("\n");
    double x, y;
    scanf("%lf %lf", &x, &y);

    if (n == 1)
    {
        Sum(x, y);
    }
    else if (n == 2)
    {
        Cut(x, y);
    }
    else if (n == 3)
    {
        Multiply(x, y);
    }
    else
    {
        Divide(x, y);
    }
}
//���Ǻ�������
void Triangulation(int n)
{
    printf("��ѡ������Ҫ��������֣�\n");
    double x;
    scanf("%lf", &x);
    if (n == 1)
    {
        CalculateSinx(x);
    }
    else if (n == 2)
    {
        CalculateCosx(x);
    }
    else if (n == 3)
    {
        CalculateTanx(x);
    }
    else if (n == 4)
    {
        CalculateArcSinx(x);
    }
    else if (n == 5)
    {
        CalculateArcCosx(x);
    }
    else
    {
        CalculateArcTanx(x);
    }
}
//������������
void LogOperations(int n)
{

    printf("��ѡ������Ҫ��������֣�\n");
    if (n == 1)
    {
        CalculateLnx();
    }
    else
    {
        CalculateLogx();
    }
}
//������������
void OtherOperations(int n)
{
    printf("��ѡ������Ҫ��������֣�\n");
    if (n == 1)
    {
        CalculateEX();
    }
    else if (n == 2)
    {
        CalculateSquareroot();
    }
    else
    {
        CalculateXY();
    }
}
int welecome()
{
    printf("���ѽ������������ӭʹ�ã�\n");
    printf("\n");
    printf("**********************************\n");
    printf("�������Ӧ��ţ�������Ӧ������ģ�飡\n");

    printf("**********************************\n");
    printf("\n");
    printf("1����������  2����������  3����������  4����������\n"); //һ��������������
    printf("\n");
    int ch;
    //�����û������ָ�������Ӧ����������
    scanf("%d", &ch);
    //������������������ͷ�Χ�ڣ��ͷ��ش������0������ʾ����
    if (ch != 1 && ch != 2 && ch != 3 && ch != 4)
    {
        return 0;
    }
    //���ָ��Ϊ1�����������������㣬�Ӽ��˳�
    if (ch == 1)
    {
        printf("\n");
        printf("��������ѡ��\n");
        printf("\n");
        printf("1���ӷ�\n");
        printf("2������\n");
        printf("3���˷�\n");
        printf("4������\n");
        printf("\n");
        InitNews();
        int n;
        scanf("%d", &n);
        //���ָ��ԣ����ش������0����ʾ������Ϣ
        if (n != 1 && n != 2 && n != 3 && n != 4)
        {
            return 0;
        }
        //�����������㷽���������û������ָ���
        BasicOperations(n);
    }
    else if (ch == 2)
    {
        printf("\n");
        printf("���Ǻ���ѡ��\n");
        printf("\n");
        printf("1��sin(x)\n");
        printf("2��cos(x)\n");
        printf("3��tan(x)\n");
        printf("4��arcsin(x)\n");
        printf("5��arccos(x)\n");
        printf("6��arctan(x)\n");
        printf("\n");
        InitNews();
        int n;
        scanf("%d", &n);
        if (n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6)
        {
            return 0;
        }
        Triangulation(n);
    }
    else if (ch == 3)
    {
        printf("\n");
        printf("��������ѡ��\n");
        printf("\n");
        printf("1��lnx\n");
        printf("2��lgx\n");
        printf("\n");
        InitNews();

        int n;
        scanf("%d", &n);
        if (n != 1 && n != 2)
        {
            return 0;
        }

        LogOperations(n);
    }
    else
    {
        printf("\n");
        printf("��������ѡ��\n");
        printf("\n");
        printf("1��e^x\n");
        printf("2��ƽ��������\n");
        printf("3��x^y\n");
        printf("\n");
        InitNews();

        int n;
        scanf("%d", &n);
        if (n != 1 && n != 2 && n != 3)
        {
            return 0;
        }
        OtherOperations(n);
    }
    return 1;
}
int main()
{

    printf("������ 1 ���������\n");

    int i, n;

    scanf("%d", &n);
    for (i = 0;; i++)
    {
        if (n != 0)
        {
            //������ʾ��Ϣ��������ȡ����״̬��
            //���Ϊ0�����������
            int result = welecome();
            if (result == 0)
            {
                printf("ָ�����󣡣���\n");
                printf("\n");
            }
            else
            {
                printf("�������������\n");
                printf("\n");
            }
        }
        printf("���� 0 �˳�����\n");
        printf("���� 1 ��������\n");
        scanf("%d", &n);

        if (n == 0)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}