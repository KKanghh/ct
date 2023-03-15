#include <bits/stdc++.h>
using namespace std;
bool robot_on_belt[201];
int A[201];
deque<int> robot;
int cnt;
int cur = 1;
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= 2 * n; i++) cin >> A[i];

	while (cnt < k) {
		ans++;
		cur--;	
		if (cur == 0) cur = 2 * n;
		if (robot.size() > 0 && robot[0] == (cur + n - 2) % (2 * n) + 1) {
			robot_on_belt[robot[0]] = false;
			robot.pop_front();
		}
		for (int i = 0; i < robot.size(); i++) {
			if (robot_on_belt[robot[i] % (2 * n) + 1] || A[robot[i] % (2 * n) + 1] == 0) continue;
			robot_on_belt[robot[i]] = false;
			robot[i] = robot[i] % (2 * n) + 1;
			robot_on_belt[robot[i]] = true;
			A[robot[i]]--;
			if (A[robot[i]] == 0) cnt++;
		}
		if (robot.size() > 0 && robot[0] == (cur + n - 2) % (2 * n) + 1) {
			robot_on_belt[robot[0]] = false;
			robot.pop_front();
		}
		if (A[cur] > 0) {
			A[cur]--;
			if (A[cur] == 0) cnt++;
			robot.push_back(cur);
			robot_on_belt[cur] = true;
		}
	}

	cout << ans;
}