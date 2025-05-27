#include <bits/stdc++.h>

using namespace std;

void kmp(vector<int> &next, string &p) {
    int i = 0, j = 1;
    while (j < p.size()) {
        if (p[i] == p[j]) {
            next[j] = i + 1;
            i++;
            j++;
        } else {
            if (i == 0) {
                j++;
            } else {
                i = next[i - 1];
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    string s, p;
    cin >> n >> p >> m >> s;

    vector<int> next(p.size(), 0);
    kmp(next, p);

    vector<int> v;
    int i = 0, j = 0;
    while (j < s.size()) {
        if (p[i] == s[j]) {
            i++;
            j++;
        } else {
            if (i == 0) {
                j++;
            } else {
                i = next[i - 1];
            }
        }
        if (i == p.size()) {
            v.push_back(j - i);
            i = next[i - 1];
        }
    }

    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << ' ';
    }
    cout << v[v.size() - 1] << endl;

    return 0;
}
