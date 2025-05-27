#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int h;
};

void dijkstra(int s, int v, const vector<vector<Edge>>& g, vector<int>& mh) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    mh[s] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int curr_h = pq.top().first;
        pq.pop();
        
        if (curr_h > mh[u]) continue;
        
        for (const auto& e : g[u]) {
            int next_v = e.to;
            int next_h = e.h;
            
            if (mh[next_v] > max(mh[u], next_h)) {
                mh[next_v] = max(mh[u], next_h);
                pq.push({mh[next_v], next_v});
            }
        }
    }
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    
    vector<vector<Edge>> g(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int s, e, h;
        cin >> s >> e >> h;
        g[s].push_back({e, h});
    }
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        vector<int> mh(n + 1, INF);
        
        dijkstra(a, n, g, mh);
        
        int res = mh[b];
        if (res == INF) cout << "-1" << endl;
        else cout << res << endl;
    }
    
    return 0;
}
