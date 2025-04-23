#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector <int> a(n);

    for (auto p = a.begin(); p != a.end(); p++)
    {
        cin >> *p;
    }

    for (auto p = a.begin(); p != a.end(); p++)
    {
        int cute = 0;
        for (auto tem = p; tem != a.begin() - 1; tem--)
        {
            if (*tem < *p)
            {
                cute++;
            }
        }
        cout << cute << " ";
    }

    cout << endl;
}