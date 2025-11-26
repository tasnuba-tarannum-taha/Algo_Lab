#include <bits/stdc++.h>
using namespace std;

int kr[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int kc[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int solve(int sr, int sc, int tr, int tc) {
    int d[8][8];
    memset(d, -1, sizeof(d));

    queue<pair<int,int>> q;
    d[sr][sc] = 0;
    q.push({sr, sc});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int r = cur.first, c = cur.second;
        if (r == tr && c == tc) return d[r][c];

        for (int k = 0; k < 8; k++) {
            int nr = r + kr[k];
            int nc = c + kc[k];

            if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && d[nr][nc] == -1) {
                d[nr][nc] = d[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return -1;
}

int main() {
    string x, y;
    while (cin >> x >> y) {
        int sr = x[1] - '1';
        int sc = x[0] - 'a';
        int tr = y[1] - '1';
        int tc = y[0] - 'a';

        int ans = solve(sr, sc, tr, tc);

        cout << "To get from " << x << " to " << y
             << " takes " << ans << " knight moves.\n";
    }
}

