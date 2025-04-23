#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector <int> v(2 * n);

    for (auto p = v.begin(); p != v.end(); p++)
    {
        cin >> *p;
    }

    int all = 0;
    int unhappiness = 0;
    for (auto p = v.begin(); p != v.end(); p += 2)
    {
        all += (*p + *(p + 1)) - 8;
        unhappiness += all;
    }

    cout << unhappiness << endl;
}