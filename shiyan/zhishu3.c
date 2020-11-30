#include <stdio.h>
#include <stdlib.h>

void output(int x, char *p[]);

int main()
{
    char *month[] = {"January", "Februray", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int m;
    printf("Please enter month: ");
    scanf("%d", &m);
    for (; m < 1 || m > 12; printf("Error!\nPlease enter month: "),scanf("%d", &m));
    output(m, month);
    system("pause");
    return 0;
}
void output(int x, char *p[])
{
    printf("%s\n", p[x - 1]);
}
