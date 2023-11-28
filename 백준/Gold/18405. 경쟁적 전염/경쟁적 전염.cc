#include <bits/stdc++.h>
using namespace std;
int board[201][201];
int dist[201][201];
vector<pair<int, int>> pos[1001];
queue<pair<int, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        fill(dist[i] + 1, dist[i] + n + 1, -1);
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];

            if (board[i][j] > 0) {
                pos[board[i][j]].push_back( {i, j} );
                dist[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        for (auto e: pos[i]) Q.push({e.first, e.second});
    }
    int s, x, y;

    cin >> s >> x >> y;


    while(!Q.empty()) {
        int a, b;
        tie(a, b) = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = a + dx[dir];
            int ny = b + dy[dir];

            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (board[nx][ny] > 0) continue;

            board[nx][ny] = board[a][b];
            dist[nx][ny] = dist[a][b] + 1;
            Q.push({nx, ny});
        }
    }

    if (dist[x][y] > s) cout << 0;
    else cout << board[x][y];
}