#include<bits/stdc++.h>

using namespace std;

vector<int> graph[1000];
int dist[1000];

void shortestPath(int start) {
	memset(dist, -1, sizeof(dist));
	queue<int> nodes;
	nodes.push(start);
	dist[start] = 0;

	while (!nodes.empty()) {
		int cur = nodes.front();
		nodes.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (dist[next] == -1) {
				nodes.push(next);
				dist[next] = dist[cur] + 1;
			}
		}
	}
}

int main() {
	int N;
	int maxNode;
	int maxPath = 0;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	shortestPath(1);
	for (int i = 1; i <= N; i++) {
		if (dist[i] > maxPath) {
			maxPath = dist[i];
			maxNode = i;
		}
	}
	shortestPath(maxNode);
	for (int i = 1; i <= N; i++) {
		if (dist[i] > maxPath) {
			maxPath = dist[i];
		}
	}

	cout << maxPath << endl;

	return 0;
}
