#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int w[MAXN], nextArr[MAXN];
char s[MAXN], pattern[MAXN];
int total = 0;

void computeLPS(const char *pat, int m, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(const char *text, const char *pat) {
    int n = strlen(text);
    int m = strlen(pat);
    computeLPS(pat, m, nextArr);
    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            total++;
            j = nextArr[j - 1];
        } else if (i < n && pat[j] != text[i]) {
            if (j != 0) {
                j = nextArr[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    int n, a, b, l, r;
    cin >> n >> a >> b >> l >> r;
    cin >> pattern;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            w[i] = b;
        } else {
            w[i] = (w[i - 1] + a) % n;
        }
        if (w[i] >= l && w[i] <= r) {
            s[i] = (w[i] % 2 == 0) ? 'A' : 'T';
        } else {
            s[i] = (w[i] % 2 == 0) ? 'G' : 'C';
        }
    }
    kmpSearch(s, pattern);
    cout << total;
    return 0;
}
