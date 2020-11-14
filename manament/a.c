
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 1000
// struct gread
// {
//     int English; //鑻辫??鎴愮哗
//     int c;       //c璇?瑷�鎴愮哗
//     int math;    //鏁板?︽垚缁?
//     int score;   //瀛︽湡鎬诲垎
// };
// struct student
// {
//     int id;
//     char name[10];
//     int class;
//     int semter;
//     struct gread stugread;
// };
// struct manament
// {
//     struct student me[MAX];
//     int size;
// };
// void readstu(struct manament *m)
// {
//     FILE *fp;
//     if ((fp = fopen("managent.txt", "r")) == NULL)
//     {
//         printf("文件打开失败");
//         exit(0);
//     }
//     while (fscanf(fp, "%d %s %d %d %d %d %d %d", &(m->me[m->size].id), m->me[m->size].name, &(m->me[m->size].class), &(m->me[m->size].semter), &(m->me[m->size].stugread.English), &(m->me[m->size].stugread.math), &(m->me[m->size].stugread.c), &(m->me[m->size].stugread.score))>0)
//     {
//         m->size++;
//     }

//     if (fclose(fp))
//     {
//         printf("文件关闭失败，");
//         exit(0);
//     }
// }
// void initstu(struct manament *m)
// {
//     if (m->size == MAX)
//     {
//         return;
//     }
//     else
//     {
//         memset(m->me, 0, sizeof(m->me));
//     }
//     m->size=0;
// }
// int main()
// {
//     struct manament ma;
//     initstu(&ma);
//     readstu(&ma);
// }
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char a[20] = "软件工程2021";
    char b[20] = "软件工程2022";
    printf("%d", strcmp(a, b));
    // if (strcmp(a,b))
    // {
    //     printf("t");
    // }
    // else
    // {
    //     printf("t111");
    // }

    system("pause");
}