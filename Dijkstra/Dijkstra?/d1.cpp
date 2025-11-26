#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<pair<int,int>>> adj(nodes + 1);
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dist(nodes + 1, INF);
    vector<int> parent(nodes + 1, -1);
    dist[1] = 0;

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();
        if (d != dist[cur]) continue;

        for (auto [nbr, wt] : adj[cur]) {
            if (dist[cur] + wt < dist[nbr]) {
                dist[nbr] = dist[cur] + wt;
                parent[nbr] = cur;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    if (dist[nodes] == INF) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> path;
    for (int v = nodes; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    for (int v : path) cout << v << " ";
    cout << "\n";

    return 0;
}
