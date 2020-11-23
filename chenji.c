#include<stdio.h>
#include<stdlib.h>
int pinjun1(int arr[11][11]){
for (int i = 1; i <11; i++)
{
    double sum=0;
   for (int j = 1; j <6; j++)
   {
       sum+=arr[i][j];
   }
printf("第%d位学生的平均分%f\n",i,sum/5);
}
for (int i = 1; i < 6; i++)
{
    double sum = 0;
    for (int j = 1; j < 11; j++)
    {
        sum += arr[j][i];
    }
    printf("第%d门成绩的平均分%f\n", i, sum / 5);
}
}
// int pinjun1(int score[][])
// {
//     for (int i = 1; i <6; i++)
//     {
//         double sum = 0;
//         for (int j = 1; j < 11; j++)
//         {
//             sum += arr[j][i];
//         }
//         printf("第%d门成绩的平均分%f\n", i, sum / 5);
//     }
// }
int main(){
    int score[11][11];
    for (int i = 1; i <11; i++)
    {
        int j=1;
        printf("请输入第%d位学生的第%d门成绩\n",i,j);
        scanf("%d",&score[i][j]);
        j++;
        printf("请输入第%d位学生的第%d门成绩\n", i, j);
        scanf("%d", &score[i][j]);
        j++;
        printf("请输入第%d位学生的第%d门成绩\n", i, j);
        scanf("%d", &score[i][j]);
        j++;
        printf("请输入第%d位学生的第%d门成绩\n", i, j);
        scanf("%d", &score[i][j]);
        j++;
        printf("请输入第%d位学生的第%d门成绩\n", i, j);
        scanf("%d", &score[i][j]);
    }
    pinjun1(score);
    
system("pause");
}