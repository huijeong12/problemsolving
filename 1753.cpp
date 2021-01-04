#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int V, E, K;
int dist[20'001];
vector<vector<pair<int, int> > > graph;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E;
	cin >> K;

	graph.resize(V + 1);
	fill(dist, dist + V + 1, -1);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back(make_pair(v, w));
	}

	priority_queue<pair<int, int> > pq;

	pq.push( {0, K} );

	while(!pq.empty()) {
		int curVtx = pq.top().second;
		int curDist = -pq.top().first;
		pq.pop();

		if (dist[curVtx] != -1)
			continue;

		dist[curVtx] = curDist;

		for (int i = 0; i < graph[curVtx].size(); i++) {
			int next = graph[curVtx][i].first;
			int nextDist = -graph[curVtx][i].second - curDist;

			if (dist[next] != -1)
				continue;

			pq.push({ nextDist, next });
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == -1)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}

	return 0;
}