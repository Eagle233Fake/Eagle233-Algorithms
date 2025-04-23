#include <iostream>
#include <map>
#include <string>

using namespace std;

void calculateCode(int j, map<int, int>& maap);

int main(void)
{
    map <int, int> mp;
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < 10; i++)
    {
        mp[i] = 0;
    }

    for (int i = m; i <= n; i++)
    {
        calculateCode(i, mp);
    }

    for (auto p = mp.begin(); p != mp.end(); p++)
    {
        cout << p->second << " ";
    }

    cout << endl;
    return 0;
}

void calculateCode(int j, map<int, int>& maap)
{
    string s = to_string(j);
    for (char c : s)
    {
        maap[c - '0']++;
    }
}