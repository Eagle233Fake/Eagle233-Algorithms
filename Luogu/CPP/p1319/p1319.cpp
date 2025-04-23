#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int number = 0;
    int allNumber = 0;
    int stored;
    bool one = true;

    while (allNumber < n * n)
    {
        one = !one;
        cin >> stored;
        for (int i = 0; i < stored; i++)
        {
            if (number < n)
            {
                if (one)
                {
                    cout << "1";
                    number++;
                    allNumber++;
                }
                else
                {
                    cout << "0";
                    number++;
                    allNumber++;
                }
            }
            else
            {
                if (one)
                {
                    cout << endl << "1";
                    number = 1;
                    allNumber++;
                }
                else
                {
                    cout << endl << "0";
                    number = 1;
                    allNumber++;
                }
            }    
        }
    }
}