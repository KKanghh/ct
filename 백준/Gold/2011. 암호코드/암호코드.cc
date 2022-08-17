#include <bits/stdc++.h>
using namespace std;
long long D[5001];
string a;
vector<int> V;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a;
	int len = a.length();
	if (a[0] == '0') {
		cout << 0;
		return 0;
	}
	D[0] = 1;
	D[1] = 1;
	for (int i = 2; i <= len; i++) D[i] = (D[i - 2] + D[i - 1]) % 1000000;

	V.push_back(1);
	int pos = 0;
	for (int i = 1; i < len; i++) {
		if (a[i] == '0') {
			if (a[i - 1] == '0' || a[i - 1] - '0' > 2) {
				cout << 0;
				return 0;
			}
			V[pos]--;
			V.push_back(1);
		}
		else if (a[i - 1] - '0' == 1) {
			V[pos]++;
		}
		else if (a[i - 1] - '0' == 2 && a[i] - '0' <= 6) {
			V[pos]++;
		}
		else {
			V.push_back(1);
			pos++;
		}
	}

	int cnt = 1;

	for (int e : V) {
		cnt = (cnt * D[e]) % 1000000;
	}

	cout << cnt;
}