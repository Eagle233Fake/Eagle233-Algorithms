#include <stdio.h>

#define MONTHS 12
#define REGULAR 300

int main(void)
{
    int expectation[MONTHS];
    for (int i = 0; i < MONTHS; i++)
    {
        scanf("%d", &expectation[i]);
    }

    int remain = 0;
    int stock = 0;

    for (int i = 0; i < MONTHS; i++)
    {
        remain += REGULAR;
        remain -= expectation[i];

        if (remain < 0)
        {
            printf("-%d\n", i + 1);
            return 0;
        }

        if (remain / 100 >= 0)
        {
            stock += (remain - remain % 100);
            remain %= 100;
        }
    }

    int get = remain + (int)(stock * 1.2);
    printf("%d", get);
}