#include <bits/stdc++.h>
using namespace std;
int student[100001];
int success[100001];
queue<int> Q;

void BFS(int i) {
	vector<int> L;
	success[i] = 1;
	Q.push(i);
	while (!Q.empty()) {
		int a = Q.front();
		L.push_back(a);
		Q.pop();
		int team = student[a];
		if (student[team] == team) {
			for (int e : L) {
				success[e] = -1;
			}
			success[team] = 1;
			return;
		}
		if (team == i) {
			return;
		}

		if (success[team] == 0) {
			Q.push(team);
			success[team] = 1;
		}

	}

	for (int e : L) {
		success[e] = 0;
	}
	success[i] = -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int num;
		cin >> num;

		for (int i = 1; i <= num; i++) {
			cin >> student[i];
		}

		for (int i = 1; i <= num; i++) {
			if (!success[i]) {
				BFS(i);
			}

		}
		int cnt = 0;
		for (int i = 1; i <= num; i++) {
			if (success[i] == -1) cnt++;
		}
		cout << cnt << '\n';
		fill(success + 1, success + 1 + num, 0);
	}

}