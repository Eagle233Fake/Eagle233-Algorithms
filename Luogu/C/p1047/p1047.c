#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int l, m;
    scanf("%d %d", &l, &m);

    bool trees[l + 1];
    for (int i = 0; i < l + 1; i++)
    {
        trees[i] = true;
    }

    int range_1[m], range_2[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &range_1[i], &range_2[i]);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = range_1[i] - 1; j < range_2[i]; j++)
        {
            if (trees[j])
            {
                trees[j] = false;
            }
        }
    }

    int tree = 0;
    for (int i = 0; i < l + 1; i++)
    {
        if (trees[i])
        {
            tree++;
        }
    }

    printf("%d\n", tree);
}
