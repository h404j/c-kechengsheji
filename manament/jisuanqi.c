
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265358979323846264338327
#define MAX 20
#define e 2.71828
//加载进入计算器需要输入的指令
void InitNews()
{
    printf("**********************\n");
    printf("请选择你想要进入的模块：\n");
    printf("**********************\n");
}
//加法
void Sum(double x, double y)
{

    double result = x + y;
    printf("%.2lf+%.2lf=%.2lf\n", x, y, result); //保留两位小数
    printf("\n");
}
//减法
void Cut(double x, double y)
{
    double result = x - y;
    printf("%.2lf-%.2lf=%.2lf\n", x, y, result);
}
//乘法
void Multiply(double x, double y)
{
    double result = x * y;
    printf("%.2lf*%.2lf=%.2lf\n", x, y, result);
}
//除法
void Divide(double x, double y)
{
    double result = x / y;
    printf("%.2lf/%.2lf=%.2lf\n", x, y, result);
}
//计算sinx，也就是正弦函数
void CalculateSinx(double n)
{
    double s;

    s = sin(n * 2 * pi / 360);         //求n的sin()值，并返回给n
    printf("sin %f = %.15lf\n", n, s); //输出
}
//计算cosx，也就是余弦函数
void CalculateCosx(double n)
{
    double c;

    c = cos(n * 2 * pi / 360);         //求n的cos()值，并返回给n
    printf("cos %f = %.15lf\n", n, c); //输出
}
//计算tanx，也就是正切函数
void CalculateTanx(double n)
{
    double t;

    t = tan(n * 2 * pi / 360);         //求n的tan()值，并返回给n
    printf("tan %f = %.15lf\n", n, t); //输出
}
//计算arcsin，反正弦函数
void CalculateArcSinx(double n)
{
    double t;

    t = asin(n);
    printf("arcsin %f = %.15lf\n", n, t); //输出
}
//计算arccos,反余弦函数
void CalculateArcCosx(double n)
{
    double t;

    t = acos(n);
    printf("acos %f = %.15lf\n", n, t); //输出
}
//计算arctan，反正切函数
void CalculateArcTanx(double n)
{
    double t;

    t = atan(n);
    printf("atan %f = %.15lf\n", n, t); //输出
}
//对数函数，Lnx 就是以e为低x的对数
void CalculateLnx()
{
    double n, res;
    scanf("%lf", &n);
    res = log(n);
    printf("以e为底%lf的对数是%.2lf\n", n, res);
}
//对数函数，log10(x)以10为底x的对数
void CalculateLogx()
{
    double n, res;
    scanf("%lf", &n);
    res = log10(n);
    printf("以10为底%lf的对数是%.2lf\n", n, res);
}
//计算e^x   e约等于：2.7182818
void CalculateEX()
{
    double n, res;
    scanf("%lf", &n);
    res = pow(e, n);

    printf("e^%f = %f\n", n, res);
}
//计算平方根，比如：4的平方跟是2
void CalculateSquareroot()
{
    double n, res;
    scanf("%lf", &n);
    res = sqrt(n);
    printf("%lf的平方根是%.2lf\n", n, res);
}
//计算x^y，就是x的y次方，比如2的2次方是4
void CalculateXY()
{
    double x, y, result;
    scanf("%lf %lf", &x, &y);
    result = pow(x, y);
    printf("x^y = %.2lf\n", result);
}
//基本四则运算  n为用户输入的指令
//n=1；做加法运算
//n=2；做减法运算
//n=3；做乘法运算
//n=4；做除法运算
void BasicOperations(int n)
{
    printf("请选择你想要计算的数字：\n");
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
//三角函数运算
void Triangulation(int n)
{
    printf("请选择你想要计算的数字：\n");
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
//对数函数运算
void LogOperations(int n)
{

    printf("请选择你想要计算的数字：\n");
    if (n == 1)
    {
        CalculateLnx();
    }
    else
    {
        CalculateLogx();
    }
}
//其它函数运算
void OtherOperations(int n)
{
    printf("请选择你想要计算的数字：\n");
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
    printf("您已进入计算器，欢迎使用！\n");
    printf("\n");
    printf("**********************************\n");
    printf("请输入对应编号，进入相应的运算模块！\n");

    printf("**********************************\n");
    printf("\n");
    printf("1：四则运算  2：三角运算  3：对数运算  4：其他运算\n"); //一共四种运算类型
    printf("\n");
    int ch;
    //接收用户输入的指令，进入相应的类型运算
    scanf("%d", &ch);
    //如果不在四种运算类型范围内，就返回错误代码0，并提示错误
    if (ch != 1 && ch != 2 && ch != 3 && ch != 4)
    {
        return 0;
    }
    //如果指令为1，则进入基本类型运算，加减乘除
    if (ch == 1)
    {
        printf("\n");
        printf("四则运算选择：\n");
        printf("\n");
        printf("1：加法\n");
        printf("2：减法\n");
        printf("3：乘法\n");
        printf("4：除法\n");
        printf("\n");
        InitNews();
        int n;
        scanf("%d", &n);
        //如果指令不对，返回错误代码0，提示错误信息
        if (n != 1 && n != 2 && n != 3 && n != 4)
        {
            return 0;
        }
        //调用四则运算方法，并将用户输入的指令传入
        BasicOperations(n);
    }
    else if (ch == 2)
    {
        printf("\n");
        printf("三角函数选择：\n");
        printf("\n");
        printf("1：sin(x)\n");
        printf("2：cos(x)\n");
        printf("3：tan(x)\n");
        printf("4：arcsin(x)\n");
        printf("5：arccos(x)\n");
        printf("6：arctan(x)\n");
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
        printf("对数函数选择：\n");
        printf("\n");
        printf("1：lnx\n");
        printf("2：lgx\n");
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
        printf("其它函数选择：\n");
        printf("\n");
        printf("1：e^x\n");
        printf("2：平方根计算\n");
        printf("3：x^y\n");
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

    printf("请输入 1 进入计算器\n");

    int i, n;

    scanf("%d", &n);
    for (i = 0;; i++)
    {
        if (n != 0)
        {
            //调用提示信息函数，获取返回状态码
            //如果为0，则代表有误
            int result = welecome();
            if (result == 0)
            {
                printf("指令有误！！！\n");
                printf("\n");
            }
            else
            {
                printf("计算结束！！！\n");
                printf("\n");
            }
        }
        printf("输入 0 退出计算\n");
        printf("输入 1 继续运算\n");
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