#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
typedef long long ll;

const int maxn = 5e4 + 6;
const int maxm = 5e4 + 6;

struct edge {
    int to, len; 
};

vector<edge> e[maxn]; 

struct node {
    i64 dis;
    int num;
    bool operator>(const node &a) const {
        return dis > a.dis;
    }
};

i64 minDis[maxn];
bool vis[maxn];
priority_queue<node, vector<node>, greater<node>> pq;

void dijkstra(int n, int s) {
    for (int i = 1; i <= n; i++) {
        minDis[i] = 1e10;
    }
    minDis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().num;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (edge eg : e[u]) {
            int v = eg.to;
            int w = eg.len;
            if (minDis[v] > minDis[u] + w) {
                minDis[v] = minDis[u] + w;
                pq.push({minDis[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    s = 1;
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dijkstra(n, s);
    i64 ans = 0;
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
        if (minDis[i] == 1e10) {
            ok = 0;
            break;
        }
        ans += a[i] * minDis[i];
    }
    if (ok)
        cout << ans << '\n';
    else
        cout << "No Answer\n";

    return 0;
}
