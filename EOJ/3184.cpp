#define M 100
//********** Specification of SortLines**********
void SortLines(int (*p)[M], int n, int m);
/* PreCondition:
p points to a two-dimensional array with n lines and
m integers in each line
PostCondition:
array is sorted satisfying to the specification
*/

/***************************************************************/
/*                                                             */
/*  DON'T MODIFY main function ANYWAY!                         */
/*                                                             */
/***************************************************************/
#include <bits/stdc++.h>
#define M 100
#define N 100


bool cmp(int *a, int *b) {
    int sumA = 0;
    int sumB = 0;
    for (inmt)
}

//********** Specification of SortLines **********
void SortLines(int (*p)[M], int n, int m)
/* PreCondition:
p points to a two-dimensional array with n lines and
m integers in each line
PostCondition:
array is sorted satisfying to the specification
*/
{   //TODO: your function definition
    qsort(p, n, sizeof(p[0]), cmp);
}
/***************************************************************/
int main()
{
    int a[N][M];
    int n,m,i,j;
    int t,cas;
    scanf("%d",&cas);
    for(t=0; t<cas; t++)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                scanf("%d",&a[i][j]);
        /***** function SortLines is called here *****/
        SortLines(a,n,m);
        /****************************************/
        printf("case #%d:\n",t);
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                printf("%d%c",a[i][j],j<m-1?' ':'\n');
    }
    return 0;
}