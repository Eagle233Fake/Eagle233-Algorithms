#include <bits/stdc++.h>

using namespace std;

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
#define M 100
#define N 100
//********** Specification of SortLines **********
void SortLines(int (*p)[M], int n, int m)
/* PreCondition:
p points to a two-dimensional array with n lines and
m integers in each line
PostCondition:
array is sorted satisfying to the specification
*/
{   //TODO: your function definition
    int *a[n];
    for (int i = 0; i < n; i++) {
        a[i] = p[i];
    }

    sort(a, a + n, [&](const int *a, const int *b) {
        int sa = 0, sb = 0;
        for (int j = 0; j < m; j++) {
            sa += a[j];
            sb += b[j];
        }

        if (sa != sb) {
            return sa < sb;
        }

        for (int j = 0; j < m; j++) {
            if (a[j] != b[j]) {
                return a[j] < b[j];
            }
        }

        return false;
    });

    int temp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = temp[i][j];
        }
    }
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