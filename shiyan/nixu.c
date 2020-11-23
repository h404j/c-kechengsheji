#include <stdio.h>
#include <stdlib.h>
void out(int arr[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void shuzu(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                break;
            }
            int a = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = a;
        }
    }
    out(arr);
}
int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    out(arr);
    printf("-----行列互换-----\n");
    shuzu(arr);
    system("pause"); //vscode防止输出窗口一闪而过，
}