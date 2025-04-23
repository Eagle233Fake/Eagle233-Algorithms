#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int count = 0;
    int endup = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i] && i >= endup)
        {
            for (int j = i; j < n; j++)
            {
                if (a[j] > a[i])
                {
                    count++;
                    break;
                    int endup = j;
                }
            }
        }
    }

    printf("%d", count);
}