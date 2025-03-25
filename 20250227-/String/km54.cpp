#include <bits/stdc++.h>
// #include <cctype>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    int count = 0;
    int index1 = s.size() - 1;
    for (char c : s) {
        if (isdigit(c)) {
            count++;
        }
    }
    s.resize(s.size() + count * 5);
    int index2 = s.size() - 1;
    for (int i = index1; i >= 0; i--) {
        if (isdigit(s[i])) {
            s[index2--] = 'r';
            s[index2--] = 'e';
            s[index2--] = 'b';
            s[index2--] = 'm';
            s[index2--] = 'u';
            s[index2--] = 'n';
        } else {
            s[index2--] = s[i];
        }
    }
    cout << s << endl;
}