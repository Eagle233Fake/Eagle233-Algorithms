#include <stdio.h>
#include <string.h>

int main(void)
{
    char group[7], star[7];
    scanf("%s %s", &group, &star);

    int length_1 = strlen(group);
    int length_2 = strlen(star);

    int number_1 = 1;
    int number_2 = 1;

    for (int i = 0; i < length_1; i++)
    {
        number_1 *= (group[i] - 'A' + 1);
    }

    for (int i = 0; i < length_2; i++)
    {
        number_2 *= (star[i] - 'A' + 1);
    }

    if (number_1 % 47 == number_2 % 47)
    {
        printf("GO\n");
    }
    else
    {
        printf("STAY\n");
    }
}