#include <bits/stdc++.h>
using namespace std;

string A, B, S;
int D[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            if (A[i] == B[j]) D[i + 1][j + 1] = D[i][j] + 1;
            else D[i + 1][j + 1] = max(D[i][j + 1], D[i + 1][j]);
        }
    }

    int x = A.size();
    int y = B.size();

    while (x > 0 || y > 0) {
        if (D[x][y] == 0) break;

        if (x > 0 && D[x][y] == D[x - 1][y]) x--;
        else if (y > 0 && D[x][y] == D[x][y - 1]) y--;
        else {
            S.push_back(A[x - 1]);
            x--;
            y--;
        }
    }

    cout << D[A.size()][B.size()] << '\n';

    for (int i = S.size() - 1; i >= 0; i--) cout << S[i];
}