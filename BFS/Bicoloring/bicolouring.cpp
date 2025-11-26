#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        int m;
        cin >> m;

        vector<vector<int>> adj(n);
        vector<int> mark(n, -1);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        queue<int> q;
        bool ok = true;

        mark[0] = 0;
        q.push(0);

        while (!q.empty() && ok) {
            int cur = q.front();
            q.pop();

            for (int nxt : adj[cur]) {
                if (mark[nxt] == -1) {
                    mark[nxt] = 1 - mark[cur];
                    q.push(nxt);
                } else if (mark[nxt] == mark[cur]) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "BICOLORABLE." : "NOT BICOLORABLE.") << "\n";
    }
    return 0;
}

