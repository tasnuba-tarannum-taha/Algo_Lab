#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

struct Edge {
    int u, v, w;
};

bool hasNegativeCycle(int n, const vector<Edge>& edges) {
    vector<ll> distance(n, INF);
    distance[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool updated = false;
        for (auto &e : edges) {
            if (distance[e.u] != INF && distance[e.u] + e.w < distance[e.v]) {
                distance[e.v] = distance[e.u] + e.w;
                updated = true;
            }
        }
        if (!updated) break;
    }

    for (auto &e : edges) {
        if (distance[e.u] != INF && distance[e.u] + e.w < distance[e.v])
            return true;
    }
    return false;
}

void processTestCase() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    if (hasNegativeCycle(n, edges))
        cout << "possible\n";
    else
        cout << "not possible\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) processTestCase();
}

