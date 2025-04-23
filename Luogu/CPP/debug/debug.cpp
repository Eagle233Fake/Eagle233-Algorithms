#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    double a, b;
    cin >> a >> b;

    cout << 5 * (2 * b - a) * log(b - a) / a << endl;
}