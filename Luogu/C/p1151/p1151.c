#include <stdio.h>
int main(void)
{
    int k;
    int check = 0;
    scanf("%d", &k);
    for (int i = 10000; i <= 30000; i++)
    {
        int sub1 = i / 100;
        int sub2 = (i - i / 10000 * 10000) / 10;
        int sub3 = (i - i / 1000 * 1000);
        if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0)
        {
            printf("%i\n", i);
            check = 1;
        }
    }
    if (check == 0)
    {
        printf("No\n");
    }
}