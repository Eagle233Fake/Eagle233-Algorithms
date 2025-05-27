#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
const int MAXM = 20001;

int cnt, money[MAXN];
bool vis[MAXN];
struct Edge {
    int v, next;
    int len;
} E[MAXM];

int p[MAXN], eid = 1;

void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}

int n, m;
int indegree[MAXN];

void topo() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            vis[i] = true;
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cnt++;
        for (int i = p[now]; i; i = E[i].next) {
            int v = E[i].v;
            if (--indegree[v] == 0) {
                q.push(v);
                vis[v] = true;
                money[v] = money[now] + 1;
            }
        }
    }
}

int main() {
    memset(indegree, 0, sizeof(indegree));
    memset(money, 0, sizeof(money));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        insert(v, u);
        indegree[u]++;
    }

    topo();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "Unhappy!" << endl;
            return 0;
        }
        ans += money[i];
    }

    cout << ans + n * 100 << endl;
    return 0;
}
