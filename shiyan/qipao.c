#include <stdio.h>
#include <stdlib.h>
void out(int arr[])
{
    for (int i = 0; i <10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void paixu1(int arr[10])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int a = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = a;
            }
        }
    }
}
void paixu(int arr[10])
{
    for (int i = 0; i <9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
           if (arr[j]>arr[j+1])
           {
              int a=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=a;
           }
           
        }
    }
}
int main()
{
    int arr[10] = {9,4,6,7,3,8,1,5,0,2};
   puts("----����ǰ-----");
   out(arr);
   puts("----���������-----");
   paixu(arr);
   out(arr);
   puts("----���������-----");
   paixu1(arr);
   out(arr);
   system("pause"); //vscode��ֹ�������һ��������
}