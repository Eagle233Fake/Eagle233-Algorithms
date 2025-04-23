#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int length;
    cin >> length;
    int number[length];

    for (int i = 0; i < length; i++)
    {
        cin >> number[i];
    }

    int n = 1;
    bool cons = 0;
    int ans = 0;
    for (int i = 1; i < length; i++)
    {
        if (number[i - 1] + 1 == number[i])
        {
            cons = 1;
            n++;
            ans = max(ans, n);
        }
        else
        {
            ans = max(ans, n);
            n = 1;
        }
    }
    if (cons)
        cout << ans;
    else
        cout << ans - 1;
}
