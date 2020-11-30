#include <stdio.h>
#include <stdlib.h>
void output(int *p)
{
    int n = 10;
    while (n--)
    {
        printf("%d ", *(p++));
    }
}
void input(int *p)
{
    puts("请输入十个数字\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", p++);
    }
}
void chuli(int *p)
{
    int *min = p;
    int *max = p;
    int *p1 = p;
    for (int i = 0; i < 9; i++)
    {
        p++;
        if (*min > *p)
        {
            min = p;
        }
        if (*max < *p)
        {
            max = p;
        }
    }
     if (max==p1&&min==p)
     {
         int f = *p1;
         *p1 = *min;
         *min = f;
         return;
     }
     if (max==p1)
     {
          int f = *p1;
         *p1 = *min;
         *min = f;
           
     }else
     {
         int f = *p1;
         *p1 = *min;
         *min = f;
         int h = *p;
         *p = *max;
         *max = h;
     }
     
     
    
    
}
int main()
{
    int arr[10];
    int *p = arr;
    input(p);
    chuli(p);
    output(p);

    system("pause"); //vscode防止输出窗口一闪而过，
}