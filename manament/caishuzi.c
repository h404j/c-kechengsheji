#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
    int o; //����һ����־o����������0���while(0)ֱ���˳�
           //����1���ܿ�ʼ��Ϸ

    do
    {
        printf("����1��ʼ��Ϸ\n");
        printf("����0�˳���Ϸ\n");
        scanf("%d", &o);
        int m = 0, n, s = 0, p = 100, flag = 0;
        srand(time(NULL)); // srand��������rand()�����������ʱ�����������
                           //ͨ����time(0)��Ϊ������time(time_t *t);��c��׼�⺯��
                           //���t�ǿ�ָ��ֱ�ӷ��ص�ǰʱ��
                           //and�����������������ÿ�β�һ������rand�õ������������
        //��һ��time(0)���ص�ǰʱ�䣬ÿʱÿ�̶���һ��������time(0)
        m = rand() % 100 + 1;
        printf("��Ϸ��ʼ\n");
        
    back:
        while (1)
        {
            flag++;
            printf("��������µ���:\n");
            scanf("%d", &n);
            if (!(n <= 100 && n >= 0))
            {
                printf("������[1,100]���ڵ���\n");

                //flag = 0;
                goto back;
            }
            if (m == n)
            {
                system("CLS");
                printf("�¶���,�������%d\n",n);
                break;
            }
            if (m > n)
            {
                printf("��С��\n");
                printf("��ʾ�����ķ�Χ��[%d,%d]\n", n, p);
                s = n; //�����С�˰Ѳ¹���������s��ʾ�´�ķ�Χ
            }
            if (m < n)
            {
                printf("�´���\n");
                printf("��ʾ�����ķ�Χ��[%d,%d]\n", s, n);
                p = n; //����´��˰Ѳ¹���������p�Ա���ʾ��С�ķ�Χ
            }
            
        }
        printf("��Ϸ����\n");
        printf("����%d��\n", flag);
    } while (o);
        printf("ллʹ��");
}
