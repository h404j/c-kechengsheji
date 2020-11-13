
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
struct gread
{
    int English; //è‹±è??æˆç»©
    int c;       //cè¯?è¨€æˆç»©
    int math;    //æ•°å?¦æˆç»?
    int score;   //å­¦æœŸæ€»åˆ†
};
struct student
{
    int id;
    char name[10];
    int class;
    int semter;
    struct gread stugread;
};
struct manament
{
    struct student me[MAX];
    int size;
};
void readstu(struct manament *m)
{
    FILE *fp;
    if ((fp = fopen("managent.txt", "r")) == NULL)
    {
        printf("ÎÄ¼þ´ò¿ªÊ§°Ü");
        exit(0);
    }
    while (fscanf(fp, "%d %s %d %d %d %d %d %d", &(m->me[m->size].id), m->me[m->size].name, &(m->me[m->size].class), &(m->me[m->size].semter), &(m->me[m->size].stugread.English), &(m->me[m->size].stugread.math), &(m->me[m->size].stugread.c), &(m->me[m->size].stugread.score))>0)
    {
        m->size++;
    }

    if (fclose(fp))
    {
        printf("ÎÄ¼þ¹Ø±ÕÊ§°Ü£¬");
        exit(0);
    }
}
void initstu(struct manament *m)
{
    if (m->size == MAX)
    {
        return;
    }
    else
    {
        memset(m->me, 0, sizeof(m->me));
    }
    m->size=0;
}
int main()
{
    struct manament ma;
    initstu(&ma);
    readstu(&ma);
}