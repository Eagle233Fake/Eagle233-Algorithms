#include <iostream>

#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector <int> w(n);

    for (auto p = w.begin(); p != w.end(); p++)
    {
        cin >> *p;
    }

    int cons = 1;
    int i = 1;
    for (auto p = w.begin(); p != w.end(); p++)
    {
        if (p == w.begin())
        {
            continue;
        }

        if (*p > *(p - 1))
        {
            i++;
            if (i > cons)
            {
                cons = i;
            }
        }
        else
        {
            i = 1;
        }
    }

    cout << cons;
}