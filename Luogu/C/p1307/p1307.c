#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char n[11];
    scanf("%s", &n);

    int length = strlen(n);

    int number = atoi(n);
    if (number > 0)
    {
        int isFirst = 1;
        for (int i = length - 1; i >= 0; i--)
        {
            if (isFirst && n[i] == '0')
            {
                
            }
            else
            {
                printf("%c", n[i]);
                isFirst = 0;
            }
        }
        printf("\n");
    }
    else if (number < 0)
    {
        int isFirst = 1;
        printf("-");
        for (int i = length - 1; i > 0; i--)
        {
            if (isFirst && n[i] == '0')
            {
                
            }
            else
            {
                printf("%c", n[i]);
                isFirst = 0;
            }
        }
        printf("\n");
    }
    else
    {
        printf("0\n");
    }
}