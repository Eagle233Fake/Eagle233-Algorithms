#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    double heart = 10;
    int exp = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int get_exp;
        double heart_lose;
        scanf("%lf %d", &heart_lose, &get_exp);
        heart -= heart_lose;

        if (heart <= 0)
        {
            break;
        }
        if (heart > 10)
        {
            heart = 10;
            exp += get_exp;
        }
        else
        {
            exp += get_exp;
        }
    }

    int level = 0;
    while (exp - (pow(2, level)) >= 0)
    {
        exp -= pow(2, level);
        level++;
    }

    printf("%d %d\n", level, exp);
}
