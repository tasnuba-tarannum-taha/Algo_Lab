#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;

    while (true) {
        vector<vector<int>> adj(21);
        int cnt;

        if (!(cin >> cnt)) return 0;

        for (int i = 1; i <= 19; i++) {
            if (i != 1) cin >> cnt;
            for (int k = 0; k < cnt; k++) {
                int u;
                cin >> u;
                adj[i].push_back(u);
                adj[u].push_back(i);
            }
        }

        int Q;
        cin >> Q;

        cout << "Test Set #" << tc++ << "\n";

        while (Q--) {
            int s, t;
            cin >> s >> t;

            vector<int> d(21, -1);
            queue<int> q;

            d[s] = 0;
            q.push(s);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int nxt : adj[u]) {
                    if (d[nxt] == -1) {
                        d[nxt] = d[u] + 1;
                        q.push(nxt);
                    }
                }
            }

            cout << setw(2) << s
                 << " to "
                 << setw(2) << t
                 << ": "
                 << d[t] << "\n";
        }

        cout << "\n";
    }
}

