#include <bits/stdc++.h>
using namespace std;

vector<int> getNext(const string& p) {
    int m = p.size();
    vector<int> next(m + 1, -1);
    int i = 0, j = -1;
    while (i < m) {
        if (j == -1 || p[i] == p[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    return next;
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int n = s2.size();
    int m = s1.size();
    if (m == 0 || n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> next = getNext(s1);
    int j = 0, i = 0;
    int overlap = 0;

    while (i < n) {
        if (j == m) {
            j = next[j];
        }
        if (j == -1 || s2[i] == s1[j]) {
            j++;
            i++;
            if (i == n) {
                overlap = j;
            }
        } else {
            j = next[j];
        }
    }

    if (overlap > 0) {
        cout << s1.substr(0, overlap) << " " << overlap << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}