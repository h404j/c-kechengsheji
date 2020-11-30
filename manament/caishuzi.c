#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
    int o; //定义一个标志o如果输入的是0外层while(0)直接退出
           //输入1才能开始游戏

    do
    {
        printf("输入1开始游戏\n");
        printf("输入0退出游戏\n");
        scanf("%d", &o);
        int m = 0, n, s = 0, p = 100, flag = 0;
        srand(time(NULL)); // srand用来设置rand()产生的随机数时的随机数种子
                           //通常用time(0)作为参数，time(time_t *t);是c标准库函数
                           //如果t是空指针直接返回当前时间
                           //and是种下随机种子数，每次不一样，用rand得到的随机数才能
        //不一样time(0)返回当前时间，每时每刻都不一样所以用time(0)
        m = rand() % 100 + 1;
        printf("游戏开始\n");
        
    back:
        while (1)
        {
            flag++;
            printf("请输入你猜的数:\n");
            scanf("%d", &n);
            if (!(n <= 100 && n >= 0))
            {
                printf("请输入[1,100]以内的数\n");

                //flag = 0;
                goto back;
            }
            if (m == n)
            {
                system("CLS");
                printf("猜对了,这个数是%d\n",n);
                break;
            }
            if (m > n)
            {
                printf("猜小了\n");
                printf("提示猜数的范围是[%d,%d]\n", n, p);
                s = n; //如果猜小了把猜过的数放入s提示猜大的范围
            }
            if (m < n)
            {
                printf("猜大了\n");
                printf("提示猜数的范围是[%d,%d]\n", s, n);
                p = n; //如果猜大了把猜过的数放入p以便提示猜小的范围
            }
            
        }
        printf("游戏结束\n");
        printf("猜了%d次\n", flag);
    } while (o);
        printf("谢谢使用");
}
