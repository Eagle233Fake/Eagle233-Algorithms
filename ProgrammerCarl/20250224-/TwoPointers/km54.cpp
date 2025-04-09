#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    int fast = -1;
    int slow = s.size() - 1;
    for (char c : s) {
        if (isdigit(c)) {
            fast += 5;
        }
        fast++;
    }
    s.resize(fast + 1);
    for (; slow >= 0; slow--) {
        if (isdigit(s[slow])) {
            s[fast--] = 'r';
            s[fast--] = 'e';
            s[fast--] = 'b';
            s[fast--] = 'm';
            s[fast--] = 'u';
            s[fast--] = 'n';
        } else {
            s[fast--] = s[slow];
        }
    }
    cout << s << endl;
}