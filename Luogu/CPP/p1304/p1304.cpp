#include <iostream>

using namespace std;

bool isPrime(int n);

int main(void)
{
    int n;
    cin >> n;

    for (int i = 4; i <= n; i += 2)
    {
        for (int j = 2; j <= i / 2; j++)
        {
            if (isPrime(j) && isPrime(i - j))
            {
                cout << i << "=" << j << "+" << i - j << endl;
                break;
            }
        }
    }
}

bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}