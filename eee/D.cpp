#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2505;
struct Edge { int u, v, w; };
vector<Edge> G;
int f[MAXN], degree[MAXN], n, m, s, u, v, sum;
int ff[MAXN];

void init(int n) {
    for (int i = 1; i <= n; ++i) f[i] = i;
}

int findf(int i) {
    return f[i] == i ? f[i] : f[i] = findf(f[i]);
}

void merge(int i, int j) {
    f[findf(i)] = findf(j);
}

bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> s;
    init(n);
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        degree[u]++, degree[v]++;
        sum += abs(u - v);
        merge(u, v);
    }
    degree[s]++;
    for (int i = 1; i <= n; ++i) ff[i] = f[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) f[j] = ff[j];
        degree[i]++;
        int ans = sum, pre = 0;
        vector<int> V;
        for (int j = 1; j <= n; ++j) {
            if (degree[j]) V.push_back(j);
        }
        for (int j = 1; j <= n; ++j) {
            if (degree[j] & 1) {
                if (!pre) pre = j;
                else {
                    ans += (j - pre);
                    for (int k = pre + 1; k <= j; ++k) merge(k, k - 1);
                    pre = 0;
                }
            }
        }
        G.clear();
        for (int j = 0; j + 1 < V.size(); ++j) {
            if (findf(V[j]) != findf(V[j + 1])) {
                G.push_back({V[j], V[j + 1], V[j + 1] - V[j]});
            }
        }
        sort(G.begin(), G.end(), cmp);
        for (const auto &e : G) {
            if (findf(e.u) != findf(e.v)) {
                merge(e.u, e.v); ans += 2 * e.w;
            }
        }
        degree[i]--;
        cout << ans << " ";
    }
    return 0;
}
