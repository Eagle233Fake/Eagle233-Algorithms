#include <stdio.h>
#include <string.h>

int main(void)
{
    char map[40001] = "";
    char text[40001];
    scanf("%s", text);
    strcat(map, text);

    int n = strlen(text);

    for (int i = 1; i < n; i++)
    {
        scanf("%s", text);
        strcat(map, text);
    }

    printf("%d ", n);

    int i = 0;
    int countOne = 0;
    int countZero = 0;
    int first = 1;

    while (map[i] != '\0')
    {
        if (map[i] == '0')
        {
            if (first)
            {
                first = 0;
            }
            if (countOne != 0)
            {
                printf("%d ", countOne);
            }
            countOne = 0;
            countZero++;
            i++;
        }

        else
        {
            if (first)
            {
                printf("0 ");
                first = 0;
            }
            if (countZero != 0)
            {
                printf("%d ", countZero);
            }
            countZero = 0;
            countOne++;
            i++;
        }
    }

    if (countOne != 0)
    {
        printf("%d ", countOne);
    }

    if (countZero != 0)
    {
        printf("%d ", countZero);
    }

}