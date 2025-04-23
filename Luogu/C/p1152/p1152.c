#include <stdbool.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int array[n];
    bool array_check[n - 1];
    int order;

    for (int i = 0; i < n - 1; i++)
    {
        array_check[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 1; i < n; i++)
    {
        order = abs(array[i] - array[i - 1]);

        // 检测 order 的值是否合法
        if (order > 0 && order < n)
        {
            array_check[order] = true;
        }
    }

    bool jolly = true;
    for (int i = 1; i < n - 1; i++)
    {
        if (!array_check[i])
        {
            jolly = false;
        }
    }

    if (jolly)
    {
        printf("Jolly\n");
    }
    else
    {
        printf("Not jolly\n");
    }
}