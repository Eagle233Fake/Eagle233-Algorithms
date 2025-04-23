#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int stored;
    int number = 0;
    bool one = true;
    int allNumber = 0;

    while (allNumber < n * n)
    {
        scanf("%d", &stored);
        one = !one;

        for(int i = 0; i < stored; i++)
        {
            if (number < n)
            {
                printf("%d", one);
                number++;
                allNumber++;
            }
            else
            {
                printf("\n%d", one);
                number = 1;
                allNumber++;
            }
        }
    }
}