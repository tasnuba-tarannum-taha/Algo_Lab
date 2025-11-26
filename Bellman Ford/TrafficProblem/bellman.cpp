#include <bits/stdc++.h>
using namespace std;

int cube(int x) {
    return x * x * x;
}

struct Road {
    int from, to;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testSet = 1;
    int n;

    while (cin >> n) {
        vector<int> busyness(n + 1);
        for (int i = 1; i <= n; i++) cin >> busyness[i];

        int m;
        cin >> m;
        vector<Road> roads(m);
        for (int i = 0; i < m; i++) cin >> roads[i].from >> roads[i].to;

        int q;
        cin >> q;
        vector<int> queries(q);
        for (int i = 0; i < q; i++) cin >> queries[i];

        vector<long long> dist(n + 1, LLONG_MAX);
        dist[1] = 0;

        for (int iter = 1; iter < n; iter++) {
            for (auto &r : roads) {
                int u = r.from, v = r.to;
                long long cost = cube(busyness[v] - busyness[u]);
                if (dist[u] != LLONG_MAX && dist[u] + cost < dist[v])
                    dist[v] = dist[u] + cost;
            }
        }

        cout << "Set #" << testSet++ << "\n";
        for (int target : queries) {
            if (target < 1 || target > n || dist[target] == LLONG_MAX || dist[target] < 3)
                cout << "?\n";
            else
                cout << dist[target] << "\n";
        }
    }
}

