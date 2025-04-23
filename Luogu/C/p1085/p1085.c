#include <stdio.h>

#define WEEK 7
#define MAX_HOURS 8

int main(void)
{
    int hours[WEEK];
    int max = 0;
    int a = 0, b = 0;
    for (int i = 0; i < WEEK; i++)
    {
        scanf("%d %d", &a, &b);
        hours[i] = a + b;
    }

    for (int i = 0; i < WEEK; i++)
    {
        if (hours[i] > max)
        {
            max = hours[i];
        }
       
    }

    if (max <= 8)
    {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < WEEK; i++)
    {
        if (hours[i] == max && max > 8)
        {
            printf("%d\n", i + 1);
            return 0;
        }
    }

}