#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

pair<int, int> find(int n, int l) {
	if (n == 2) {
		if (l == 1) return { 1, 1 };
		else if (l == 2) return { 1, 2 };
		else if (l == 3) return { 2, 2 };
		else return { 2, 1 };
	}
	int flag = pow(n, 2) / 4;
	int half = n / 2;
	pair<int, int> goal;
	if (l <= flag) {
		goal = find(n / 2, l);
		return { goal.Y, goal.X };
	}
	else if (l <= 2 * flag) {
		goal = find(n / 2, l - flag);
		goal.Y += half;
	}
	else if (l <= 3 * flag) {
		goal = find(n / 2, l - 2 * flag);
		goal.X += half;
		goal.Y += half;
	}
	else {
		goal = find(n / 2, l - 3 * flag);
		return { 2 * half - goal.Y + 1, half - goal.X + 1 };
	}
	return goal;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, L;
	cin >> N >> L;
	pair<int, int> ans = find(N, L);
	cout << ans.X << ' ' << ans.Y;
}