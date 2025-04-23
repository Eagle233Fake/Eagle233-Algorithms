#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int new_value;
    int remain_value;
    int all_value = n;

    while (n / k != 0)
    {
        new_value = n / k;
        remain_value = n % k;
        all_value += new_value;
        n = new_value + remain_value;
    }

    printf("%d\n", all_value);
}