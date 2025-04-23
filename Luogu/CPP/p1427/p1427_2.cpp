#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector <int> n(100);

    int i = 0;
    for (auto p = n.begin(); p != n.end(); p++)
    {
        cin >> *p;
        i++;
        if (*p == 0)
        {
            break;
        }
    }

    n.resize(i);
    for (auto p = n.end() - 2; p != n.begin() - 1; p--)
    {
        cout << *p << " ";
    }

    cout << endl;
}