#include <numeric>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int trans1Int(string s);
int trans2Int(string s);
int digitNumber(double d);

int main(void)
{
    string a, b;
    cin >> a >> b;

    int a_1 = trans1Int(a);
    int a_2 = trans2Int(a);

    int b_1 = trans1Int(b);
    int b_2 = trans2Int(b);

    double number1 = static_cast<float>(a_1) / static_cast<float>(a_2);
    double number2 = static_cast<float>(b_1) / static_cast<float>(b_2);

    double number = number1 * number2;

    if (number - static_cast<float>(number) == 0)
    {
        cout << "1 " << static_cast<float>(number) << endl;
        return 0;
    }

    int number_upper = a_1 * b_1;
    int number_lower = a_2 * b_2;

    int gcd_number = gcd(number_upper, number_lower);

    cout << number_lower / gcd_number << " " << number_upper / gcd_number;
}

int trans1Int(string s)
{
    string s1;
    for (char c : s)
    {
        if (c == '/')
        {
            break;
        }
        s1 += c;
    }
    return stoi(s1);
}

int trans2Int(string s)
{
    bool isAfter = 0;
    string s2;
    for (char c : s)
    {
        if (isAfter)
        {
            s2 += c;
        }

        if (c == '/')
        {
            isAfter = !isAfter;
        }
    }
    return stoi(s2);
}

int digitNumber(double d)
{
    string s = to_string(d);

    bool isAfterPoint = 0;
    int digit = 0;
    for (char c : s)
    {
        if (c == '.')
        {
            isAfterPoint = 1;
        }

        if (isAfterPoint)
        {
            digit++;
        }
    }
    return digit;
}