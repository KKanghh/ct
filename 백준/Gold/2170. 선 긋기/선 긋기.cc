#include <bits/stdc++.h>
using namespace std;
pair<int, int> D[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> D[i].first >> D[i].second;
	}
	
	sort(D, D + n);
	pair<int, int> draw = { D[0].first, D[0].second };

	for (int i = 1; i < n; i++) {
		if (D[i].first < draw.second) draw.second = max(D[i].second, draw.second);
		else {
			cnt += draw.second - draw.first;
			draw = D[i];
		}
	}
	cnt += draw.second - draw.first;

	cout << cnt;
}