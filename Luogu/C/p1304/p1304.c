#include <stdbool.h>
#include <stdio.h>

bool isPrime(int n);

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 4; i <= n; i += 2)
    {
        for (int j = 2; j <= i / 2; j++)
        {
            if (isPrime(j) && isPrime(i - j))
            {
                printf("%d=%d+%d\n", i, j, i - j);
                break;
            }
        }
    }
}

bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}