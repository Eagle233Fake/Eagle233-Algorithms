#include <stdio.h>

#define APPLE_COUNT 10

int main(void)
{
    int apple[10];
    for (int i = 0; i < APPLE_COUNT; i++)
    {
        scanf("%d", &apple[i]);
    }
    
    int height;
    int count = 0;
    scanf("%d", &height);

    for (int i = 0; i < APPLE_COUNT; i++)
    {
        if (height + 30 >= apple[i])
        {
            count++;
        }
    }

    printf("%d\n", count);
}