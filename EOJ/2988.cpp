#include <bits/stdc++.h>
using namespace std;

void solve(void) {
    string s;
    cin >> s;
    vector<string> ss;
    for (int i = 0; i * 6 < s.size(); i++) {
        ss.push_back(s.substr(i * 6, 6));
    }

    vector<int> pwd(6, 0);
    for (auto iter : ss) {
        for (int i = 0; i < 6; i++) {
            if (i < iter.size()) {
                pwd[i] += iter[i];
            }
        }
    }

    for (auto i : pwd) {
        cout << i % 10;
    }

    cout << endl;
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
    }
}