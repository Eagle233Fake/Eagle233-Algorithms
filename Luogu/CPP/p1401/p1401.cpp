#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long x1, x2, y1, y2;

    cin >> x1 >> x2;
    cin >> y1 >> y2;

    bool xx = 0;

    if (x1 * y1 > 2147483647 || x2 * y2 > 2147483647 || 
        x2 * y1 < -2147483648 || x1 * y2 < -2147483648 ||
        x1 * y1 < -2147483648 || x2 * y2 < -2147483648 ||
        x2 * y1 > 2147483647 || x1 * y2 > 2147483647)
    {
        xx = 1;
    }

    if (!xx)
    {
        cout << "int" << endl;
    }
    else
    {
        cout << "long long int" << endl;
    }
}