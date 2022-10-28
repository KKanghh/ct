#include <bits/stdc++.h>
using namespace std;
int l[100001], r[100001], p[100001];
bool vis[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k, a, b;
		cin >> k >> a >> b;
		if (a > 0) {
			l[k] = a;
			p[a] = k;
		}
		if (b > 0) {
			r[k] = b;
			p[b] = k;
		}
	}
	int fin = 1;
	while (r[fin] > 0) fin = r[fin];

	int cur = 1, cnt = 0;
	vis[cur] = true;
	n--;

	while (true) {
		if (l[cur] > 0 && !vis[l[cur]]) {
			cur = l[cur];
			n--;
			vis[cur] = true;
			cnt++;
			continue;
		}
		else if (r[cur] > 0 && !vis[r[cur]]) {
			cur = r[cur];
			n--;
			vis[cur] = true;
			cnt++;
			continue;
		}
		else if (cur == fin) {
			break;
		}
		else {
			cur = p[cur];
			cnt++;
		}

	}

	cout << cnt;
}