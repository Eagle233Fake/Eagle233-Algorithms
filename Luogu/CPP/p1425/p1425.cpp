#include <iostream>

using namespace std;

int main(void)
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    int x = a * 60 + b;

    int y = c * 60 + d;

    int n = y - x;

    cout << n / 60 << " " << n % 60 << endl;
}