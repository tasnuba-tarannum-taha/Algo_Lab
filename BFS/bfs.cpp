#include <bits/stdc++.h>
using namespace std;

int distv[10];
int par[10];
string state[10];

void bfs(vector<int> g[], int s, int n)
{
    for (int i = 0; i < n; i++) {
        state[i] = "w";
        distv[i] = INT_MAX;
        par[i] = -1;
    }

    queue<int> q;
    q.push(s);
    state[s] = "g";
    distv[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int x : g[u]) {
            if (state[x] == "w") {
                state[x] = "g";
                distv[x] = distv[u] + 1;
                par[x] = u;
                q.push(x);
            }
        }

        state[u] = "b";
    }
}

void showPath(int s, int d)
{
    if (d == -1) return;
    showPath(s, par[d]);
    cout << d << " ";
}

int main()
{
    vector<int> g[10];

    g[0].push_back(1);
    g[1].push_back(0);
    g[1].push_back(2);
    g[2].push_back(1);
    g[2].push_back(3);
    g[3].push_back(2);
    g[2].push_back(4);
    g[4].push_back(2);

    bfs(g, 0, 5);

    cout << distv[3] << "\n";
    showPath(0, 3);

    return 0;
}
