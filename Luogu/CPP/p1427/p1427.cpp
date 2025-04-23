#include <iostream>

using namespace std;

int main(void)
{
    int number[100];
    
    int i = -1;
    do
    {
        i++;
        cin >> number[i];
    } while (number[i] != 0);
    
    for (int j = i - 1; j >= 0; j--)
    {
        cout << number[j] << " ";
    }
    cout << endl;
}