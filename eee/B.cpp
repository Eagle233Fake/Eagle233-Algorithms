#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1000];
bool vst[1000];

void dfs(int node) {
	vst[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int nextNode = graph[node][i];

		if (!vst[nextNode]) {
			dfs(nextNode);
		}
	}
}

int main() {
	int n, m;
	memset(vst, false, sizeof(vst));
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int components = 0;
	for (int i = 1; i <= n; i++) {
		if (!vst[i]) {
			components++;
			dfs(i);
		}
	}
	cout << components - 1;

	return 0;
}
