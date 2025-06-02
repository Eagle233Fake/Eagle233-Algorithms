#include <bits/stdc++.h>

using namespace std;

unordered_map<int, bool> umap;

void solve(void) {
    int a, b;
    cin >> a >> b;

    int count = 0;
    for (int i = a; i <= b; i++) {
        if (umap[i]) {
            count++;
        }
    }

    cout << count << endl;
}

bool isAo(int i) {
    string s;
    s = to_string(i);
    int a = 0;
    while (a < s.size() - 1 && s[a] > s[a + 1]) {
        a++;
    }
    if (a == 0 || a == s.size() - 1) {
        return false;
    }

    while (a < s.size() - 1 && s[a] < s[a + 1]) {
        a++;
    }

    if (a + 1 == s.size()) {
        return true;
    }
    return false;
}

int main(void) {
    for (int i = 100; i <= 1000000; i++) {
        umap[i] = isAo(i);
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
    }

    return 0;
}