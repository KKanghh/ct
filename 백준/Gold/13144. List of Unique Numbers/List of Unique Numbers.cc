#include <bits/stdc++.h>
using namespace std;
int a[100005];
vector<bool> V(100001, false);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int en = 0;
	long long cnt = 0;
	for (int st = 0; st < n; st++) {
		while (en < n && !V[a[en]]) {
			V[a[en]] = true;
			en++;
		}
		cnt += en - st;
		V[a[st]] = false;
	}
	cout << cnt;
}