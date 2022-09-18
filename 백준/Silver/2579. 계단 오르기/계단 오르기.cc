#include <bits/stdc++.h>
using namespace std;

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
    ans[1][1] = stair[1];
	for (int i = 2; i <= N; i++) {
		ans[0][i] = ans[1][i - 1] + stair[i];
		ans[1][i] = max(ans[0][i - 2], ans[1][i - 2]) + stair[i];
	}

	cout << max(ans[0][N], ans[1][N]);
}