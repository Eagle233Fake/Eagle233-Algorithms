#include <stdbool.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    double a[n];
    unsigned int t[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lf %u", &a[i], &t[i]);
    }

    bool lights[2000000];

    for (int i = 0; i < 2000000; i++)
    {
        lights[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t[i]; j++)
        {
            lights[(int)floor(a[i] * (j + 1)) - 1] = !lights[(int)floor(a[i] * (j + 1)) - 1];
        }
    }

    for (int i = 0; i < 2000000; i++)
    {
        if (lights[i])
        {
            printf("%i\n", i + 1);
        }
    }
}