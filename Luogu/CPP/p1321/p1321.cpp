#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int boy = 0;
    int girl = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'b')
        {
            boy++;
        }
        else if (i - 1 >= 0 && s[i] == 'o' && s[i - 1] != 'b')
        {
            boy++;
        }
        else if (i - 1 >= 0 && s[i] == 'y' && s[i - 1] != 'o')
        {
            boy++;
        }

        if (s[i] == 'g')
        {
            girl++;
        }
        else if (i - 1 >= 0 && s[i] == 'i' && s[i - 1] != 'g')
        {
            girl++;
        }
        else if (i - 1 >= 0 && s[i] == 'r' && s[i - 1] != 'i')
        {
            girl++;
        }
        else if (i - 1 >= 0 && s[i] == 'l' && s[i - 1] != 'r')
        {
            girl++;
        }
    }

    cout << boy << "\n" << girl << "\n";
}