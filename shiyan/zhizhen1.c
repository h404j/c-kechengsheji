#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    printf("����������������\n");
    scanf("%d %d %d",&a,&b,&c);
    int *x,*y,*z;
    x=&a;
    y=&b;
    z=&c;
    if (*x > *z)
    {
        int s = *x;
        *x = *z;
        *z = s;
    }
    if (*x>*y)
    {
        int s=*x;
        *x=*y;
        *y=s;
    }
    if (*y > *z)
    {
        int s = *y;
        *y = *z;
        *z = s;
    }
    
    printf("%d %d %d",a,b,c);
    
   system("pause"); //vscode��ֹ�������һ��������
}