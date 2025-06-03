#include <bits/stdc++.h>

using namespace std;

void solve(void) {
    string s, s0;
    cin >> s >> s0;

    string ss = "";
    for (int i = 0; i < s.size(); i++) {
        if (i <= s.size() - s0.size()) {
            if (s.substr(i, s0.size()) == s0) {
                i += s0.size() - 1;
                continue;
            }
        }
        ss += s[i];
    }

    cout << ss << endl;
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
    }
}