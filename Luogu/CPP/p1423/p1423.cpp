#include <iostream>

using namespace std;

int main(void)
{
    float s;
    cin >> s;

    int n = 0;
    float i = 1.0;
    while (s > 0)
    {
        s -= 2 * i;
        i *= 0.98;
        n++;
    }

    cout << n << endl;
}