#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
    cout << s << endl;
}