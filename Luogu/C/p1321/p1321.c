#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[256];
    scanf("%s", s);

    int l = strlen(s);

    int boy = 0;
    int girl = 0;

    for (int i = 0; i < l; i++)
    {
        if (s[i] == 'b')
        {
            boy++;
        }
        else if (i - 1 >= 0 && s[i] == 'o' && s[i - 1] != 'b')
        {
            boy++;
        }
        else if (i - 1 >= 0 && s[i] == 'y' && s[i - 1] != 'o')
        {
            boy++;
        }

        if (s[i] == 'g')
        {
            girl++;
        }
        else if (i - 1 >= 0 && s[i] == 'i' && s[i - 1] != 'g')
        {
            girl++;
        }
        else if (i - 1 >= 0 && s[i] == 'r' && s[i - 1] != 'i')
        {
            girl++;
        }
        else if (i - 1 >= 0 && s[i] == 'l' && s[i - 1] != 'r')
        {
            girl++;
        }
    }

    printf("%d\n%d\n", boy, girl);
}