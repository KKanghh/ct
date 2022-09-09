#include <bits/stdc++.h>
using namespace std;
bool board[6][6];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, f;
	cin >> f;
	s = f;
	board[f[0] - 'A'][f[1] - '1'] = true;
	for (int i = 0; i < 35; i++) {
		string tmp;
		cin >> tmp;

		if ((abs(tmp[0] - s[0]) == 1 && abs(tmp[1] - s[1]) == 2) || (abs(tmp[0] - s[0]) == 2 && abs(tmp[1] - s[1]) == 1)) s = tmp;
		else {
			cout << "Invalid";
			return 0;
		}
		board[s[0] - 'A'][s[1] - '1'] = true;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (!board[i][j]) {
				cout << "Invalid";
				return 0;
			}
		}
	}

	if ((abs(f[0] - s[0]) == 1 && abs(f[1] - s[1]) == 2) || (abs(f[0] - s[0]) == 2 && abs(f[1] - s[1]) == 1)) {
		cout << "Valid";
	}
	else cout << "Invalid";
}