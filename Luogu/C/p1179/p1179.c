#include <stdio.h>

int countDigit(int n);

int main(void)
{
    int l, r;
    scanf("%d %d", &l, &r);

    int number;
    int times = 0;
    for (int i = l; i <= r; i++)
    {
        number = i;
        for (int j = 0; j < countDigit(i); j++)
        {
            
            if (number % 10 == 2)
            {
                times++;
            }
            number /= 10;
        }
    }

    printf("%d\n", times);
}

int countDigit(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n /= 10;
    }
    return count;
}