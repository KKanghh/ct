#include<bits/stdc++.h>
using namespace std;
deque<int> D[101];
int a[100];
bool multi[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> a[i];
		D[a[i]].push_back(i);
	}
	int cnt = 0;
	int cur = 0;
	while (n > 0) {
		if (!multi[a[cur]]) {
			n--;
			multi[a[cur]] = true;
		}
		D[a[cur]].pop_front();
		cur++;
	}

	while (cur < k) {
		if (!multi[a[cur]]) {
			cnt++;
			int mx = 0, h;
			for (int i = 1; i <= k; i++) {
				if (multi[i]) {
					if (D[i].empty()) {
						h = i;
						break;
					}
					if (D[i][0] > mx) {
						mx = D[i][0];
						h = i;
					}
				}
			}
			multi[h] = false;
			multi[a[cur]] = true;
		}
		D[a[cur]].pop_front();
		cur++;
	};

	cout << cnt;
}