#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    string group, star;
    cin >> group >> star;
    
    int number_1 = 1;
    int number_2 = 1;

    for (char c : group)
    {
        number_1 *= (c - 'A' + 1);
    }

    for (char c : star)
    {
        number_2 *= (c - 'A' + 1);
    }

    if (number_1 % 47 == number_2 % 47)
    {
        cout << "GO" << endl;
    }
    else
    {
        cout << "STAY" << endl;
    }
}