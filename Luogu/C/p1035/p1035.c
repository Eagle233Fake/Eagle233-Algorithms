#include <stdio.h>

int main(void)
{
    int k;
    scanf("%d", &k);
    double s = 0;
    int n = 0;

    for (double i = 1; s <= k; i++)
    {
        s += 1 / i;
        n++;
    }
    
    printf("%d\n", n);
}