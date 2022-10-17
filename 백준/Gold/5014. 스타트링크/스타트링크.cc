#include <bits/stdc++.h>
using namespace std;

int building[1000001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int F, S, G, U, D;

	cin >> F >> S >> G >> U >> D;
	building[S] = 1;
	Q.push(S);

	while (!Q.empty()) {
		auto t = Q.front();
		Q.pop();
		for (auto e : { t + U, t - D }) {
			if (e < 1 || e > F) continue;
			if (building[e]) continue;
			building[e] = building[t] + 1;
			Q.push(e);
		}
	}

	if (building[G]) cout << building[G] - 1;
	else cout << "use the stairs";

}