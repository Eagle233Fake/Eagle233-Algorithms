#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_N 2333430
#define MAX_C 26

struct Trie {
    int *ch[MAX_N];
    int tot;
    int cnt[MAX_N];

    Trie() {
        tot = 0;
        memset(ch, 0, sizeof(ch));
        memset(cnt, 0, sizeof(cnt));
    }

    void insert(const char *str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p] == NULL) {
                ch[p] = new int[MAX_C];
                memset(ch[p], -1, sizeof(int) * MAX_C);
            }
            if (ch[p][str[i] - 'a'] == -1) {
                ch[p][str[i] - 'a'] = ++tot;
            }
            p = ch[p][str[i] - 'a'];
        }
        cnt[p]++;
    }

    bool find(const char *str) {
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (cnt[p] != 0) return true;
            if (ch[p] == NULL) return false;
            if (ch[p][str[i] - 'a'] == -1) return false;
            p = ch[p][str[i] - 'a'];
        }
        return false;
    }
};

char s[MAX_N][15];
Trie trie;

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    bool ans = false;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        getchar();
        trie.insert(s[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (trie.find(s[i])) {
            ans = true;
            break;
        }
    }
    if (ans) {
        puts("Bug!");
    } else {
        puts("Good Luck!");
    }
    return 0;
}
