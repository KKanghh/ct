#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int stair[301], ans[2][301];
int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}

	ans[0][1] = stair[1];
	ans[1][2] = stair[2];
	ans[0][2] = stair[1] + stair[2];
	for (int i = 3; i <= N; i++) {
		ans[0][i] = ans[1][i - 1] + stair[i];
		ans[1][i] = max(ans[0][i - 2], ans[1][i - 2]) + stair[i];
	}

	/*for (int i = 0; i <= N; i++) cout << ans[0][i] << ' ';
	cout << '\n';
	for (int i = 0; i <= N; i++) cout << ans[1][i] << ' ';
	cout << '\n';*/
	cout << max(ans[0][N], ans[1][N]);
}