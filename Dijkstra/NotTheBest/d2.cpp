#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    int weight;
};

long long secondShortestPath(int n, int r) {
    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < r; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<long long> shortest(n + 1, INF);
    vector<long long> second(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<>> pq;

    shortest[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [dist_u, u] = pq.top();
        pq.pop();

        if (dist_u > second[u]) continue;

        for (auto &edge : graph[u]) {
            int v = edge.to;
            long long cand = dist_u + edge.weight;

            if (cand < shortest[v]) {
                second[v] = shortest[v];
                shortest[v] = cand;
                pq.push({shortest[v], v});
                if (second[v] != INF) pq.push({second[v], v});
            } else if (cand > shortest[v] && cand < second[v]) {
                second[v] = cand;
                pq.push({second[v], v});
            }
        }
    }

    return second[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int caseNo = 1; caseNo <= t; ++caseNo) {
        int n, r;
        cin >> n >> r;
        long long ans = secondShortestPath(n, r);
        if (ans != INF) {
            cout << "Case " << caseNo << ": " << ans << "\n";
        }
    }
    return 0;
}

