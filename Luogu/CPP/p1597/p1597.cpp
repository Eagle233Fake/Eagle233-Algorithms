#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

int main(void)
{
    char a, b;

    // 注意到 vector 的数据类型为 char ，因此初始化因为'0'而不是0.
    vector <char> v(3, '0');
    while (scanf(" %c:=%c;", &a, &b) == 2)
    {
        if (isdigit(b))
        {
            v[a - 'a'] = b;
        }
        else
        {
            v[a - 'a'] = v[b - 'a'];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}