#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    double s, x;
    cin >> s >> x;

    double n = 0;
    double i = 1.0;
    while (s - x - n > 0)
    {
        s -= 7 * i;
        i *= 0.98;
    }

    if (abs(s - n - 7 * i) > x)
    {
        cout << "n" << endl;
    }
    else
    {
        cout << "y" << endl;
    }
}