#include <iostream>

using namespace std;

int main(void)
{
    long long x, n;

    cin >> x >> n;

    long long s = 0;

    for (long long i = x; i < x + n; i++)
    {
        if (i % 7 >= 1 && i % 7 <= 5)
        {
            s += 250;
        }
    }

    cout << s << endl;
}