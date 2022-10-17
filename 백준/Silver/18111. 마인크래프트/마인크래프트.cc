#include <bits/stdc++.h>
using namespace std;
int board[500][500];
int N, M, B;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> B;
    int mx = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            mx = max(board[i][j], mx);
        }
    }
    int t = 0x7fffffff, ans = 0;
    for (int i = mx; i >= 0; i--) {
        int tmp = 0, tree = B;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (i > board[x][y]) {
                    tmp += i - board[x][y];
                    tree -= i - board[x][y];
                }
                else {
                    tmp += (board[x][y] - i) * 2;
                    tree += board[x][y] - i;
                }
            }
        }
        if (tree < 0) continue;
        if (tmp < t) {
            t = tmp;
            ans = i;
        }
    }
    
    cout << t << ' ' << ans;
}