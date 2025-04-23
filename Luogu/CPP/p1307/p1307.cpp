#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string n;
    cin >> n;

    int number = stoi(n);

    if (number > 0)
    {
        bool isFirst = true;

        for (int i = n.length() - 1; i >= 0; i--)
        {
            if (isFirst && n[i] == '0')
            {
                continue;
            }

            else
            {
                cout << n[i];
                isFirst = false;
            }
        }
        cout << endl;
    }

    else if (number == 0)
    {
        cout << "0" << endl;
    }

    else
    {
        bool isFirst = true;

        cout << "-";
        for (int i = n.length() - 1; i > 0; i--)
        {
            if (isFirst && n[i] == '0')
            {
                continue;
            }

            else
            {
                cout << n[i];
                isFirst = false;
            }
        }
        cout << endl;
    }
}