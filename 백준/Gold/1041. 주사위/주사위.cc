#include <bits/stdc++.h>
using namespace std;
long long dice[6];
long long d[12][2] = { {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 5}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5} };
long long t[8][3] = { {0, 1, 2}, {0, 1, 3}, {0, 3, 4}, {0, 2, 4}, {1, 2, 5}, {3, 4, 5}, {1, 3, 5}, {2, 4, 5} };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;

	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
	}

	if (n == 1) {
		long long a = 0, mx = 0;
		for (int i = 0; i < 6; i++) {
			mx = max(mx, dice[i]);
			a += dice[i];
		}
		cout << a - mx;
		return 0;
	}

	long long sum = 0;
	long long mn = 51;

	for (int i = 0; i < 6; i++) mn = min(mn, dice[i]);
	sum += n > 2 ? (5 * (n - 2) * (n - 2) + 4 * (n - 2)) * mn : 0;
	
	mn = 101;
	for (int i = 0; i < 12; i++) mn = min(mn, dice[d[i][0]] + dice[d[i][1]]);
	sum += (8 * n - 12) * mn;

	mn = 151;
	for (int i = 0; i < 8; i++) mn = min(mn, dice[t[i][0]] + dice[t[i][1]] + dice[t[i][2]]);
	sum += 4 * mn;


	cout << sum;
}