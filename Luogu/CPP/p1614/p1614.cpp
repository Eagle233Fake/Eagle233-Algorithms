#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main(void)
{
    long long n, m;
    cin >> n >> m;

    vector <int> v(n);
    for (auto p = v.begin(); p != v.end(); p++)
    {
        cin >> *p;
    }

    long long min = numeric_limits<long long>::max();
    long long temp = 0;
    for (auto p = v.begin(); p != v.end() - m + 1; p++)
    {
        temp = 0;

        for (long long i = 0; i < m; i++)
        {
            temp += *(p + i);
        }

        if (temp < min)
        {
            min = temp;
        }
    }

    cout << min << endl;
}