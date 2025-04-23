#include <iostream>

using namespace std;

int main(void)
{
    string map;
    string test;

    cin >> test;
    map += test;

    int n = test.size();

    for (int i = 1; i < n; i++)
    {
        cin >> test;
        map += test;
    }

    cout << n << " ";

    int countZero = 0;
    int countOne = 0;
    bool first = true;

    for (char c : map)
    {
        if (c == '0')
        {
            if (first)
            {
                first = !first;
            }
            if (countOne)
            {
                cout << countOne << " ";
                countOne = 0;
            }
            countZero++;
        }

        else
        {
            if (first)
            {
                cout << "0 ";
                first = !first;
            }
            if (countZero)
            {
                cout << countZero << " ";
                countZero = 0;
            }
            countOne++;
        }
    }

    if (countZero)
    {
        cout << countZero << " ";
    }

    else if (countOne)
    {
        cout << countOne << " ";
    }
}