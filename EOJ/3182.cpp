//********** Specification of SortStrings**********
void SortStrings(char *p[ ], int n);
/* PreCondition:
p points to an array with n pointers which point to strings
PostCondition:
array is sorted satisfying to the specification
*/

/***************************************************************/
/*                                                             */
/*  DON'T MODIFY main function ANYWAY!                         */
/*                                                             */
/***************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define N 100
#define LEN 80
/********** Specification of SortStrings **********/
void SortStrings(char *p[], int n)
/* PreCondition:
p points to an array with n pointers which point to strings
PostCondition:
array is sorted satisfying to the specification
*/
{   //TODO: your function definition
    char *s[n];
    for (int i = 0; i < n; i++) {
        s[i] = p[i];
    }

    sort(s, s + n, [&](const char *a, const char *b) {
        char c1 = ':', c2 = ':';
        string s1 = a, s2 = b;
        for (char c : s1) {
            if (isdigit(c)) {
                c1 = c;
                break;
            }
        }

        for (char c : s2) {
            if (isdigit(c)) {
                c2 = c;
                break;
            }
        }

        if (c1 != ':' && c2 != ':') {
            if (c1 != c2) {
                return c1 < c2;
            }
            return s1 < s2;
        }

        if (c1 == ':' && c2 != ':') {
            return true;
        }
        if (c1 != ':' && c2 == ':') {
            return false;
        }

        return s1 < s2;
    });

    char *temp[n];
    memcpy(temp, s, sizeof(*temp) * n);
    memcpy(p, temp, sizeof(*temp) * n);
}
/***************************************************************/
int main()
{   char s[N][LEN],*a[N];
    int n,i,t,cas;
    scanf("%d",&cas);
    for(t=0; t<cas; t++)
    {   scanf("%d",&n);
        getchar();
        for (i=0; i<n; i++) scanf("%s",a[i]=s[i]);
        /***** function SortStrings is called here *****/
        SortStrings(a,n);
        /****************************************/
        printf("case #%d:\n",t);
        for (i=0; i<n; i++) printf("%s%c",a[i],i<n-1?' ':'\n');
    }
    return 0;
}