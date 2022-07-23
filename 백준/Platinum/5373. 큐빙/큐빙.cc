#include <bits/stdc++.h>
using namespace std;
char u[3][3], f[3][3], l[3][3], r[3][3], b[3][3], d[3][3];

void reset() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			u[i][j] = 'w';
			f[i][j] = 'r';
			l[i][j] = 'g';
			r[i][j] = 'b';
			b[i][j] = 'o';
			d[i][j] = 'y';
		}
	}
}

void turn(string s) {
	char tmp[3][3];
	if (s[0] == 'U') {
		if (s[1] == '-') {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[2 - j][i] = u[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					u[i][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				char v = b[0][i];
				b[0][i] = r[0][i];
				r[0][i] = f[0][i];
				f[0][i] = l[0][i];
				l[0][i] = v;
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[j][2 - i] = u[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					u[i][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				char v = b[0][i];
				b[0][i] = l[0][i];
				l[0][i] = f[0][i];
				f[0][i] = r[0][i];
				r[0][i] = v;
			}
		}
	}
	else if (s[0] == 'F') {
		if (s[1] == '-') {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[2 - j][i] = f[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					f[i][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				char v = u[2][i];
				u[2][i] = r[i][0];
				r[i][0] = d[2][i];
				d[2][i] = l[2 - i][2];
				l[2 - i][2] = v;
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[j][2 - i] = f[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					f[i][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				char v = u[2][i];
				u[2][i] = l[2 - i][2];
				l[2 - i][2] = d[2][i];
				d[2][i] = r[i][0];
				r[i][0] = v;
			}
		}
	}
	else if (s[0] == 'L') {
		if (s[1] == '-') {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[2 - j][i] = l[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					l[i][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				char v = u[i][0];
				u[i][0] = f[i][0];
				f[i][0] = d[2 - i][2];
				d[2 - i][2] = b[2 - i][2];
				b[2 - i][2] = v;
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[j][2 - i] = l[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					l[i][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				char v = u[i][0];
				u[i][0] = b[2 - i][2];
				b[2 - i][2] = d[2 - i][2];
				d[2 - i][2] = f[i][0];
				f[i][0] = v;
			}
		}
	}
	else if (s[0] == 'B') {
		if (s[1] == '-') {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[2 - j][i] = b[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					b[i][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				char v = u[0][2 - i];
				u[0][2 - i] = l[i][0];
				l[i][0] = d[0][2 - i];
				d[0][2 - i] = r[2 - i][2];
				r[2 - i][2] = v;
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[j][2 - i] = b[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					b[i][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				char v = u[0][2 - i];
				u[0][2 - i] = r[2 - i][2];
				r[2 - i][2] = d[0][2 - i];
				d[0][2 - i] = l[i][0];
				l[i][0] = v;
			}
		}
	}
	else if (s[0] == 'R') {
		if (s[1] == '-') {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[2 - j][i] = r[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					r[i][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				char v = u[2 - i][2];
				u[2 - i][2] = b[i][0];
				b[i][0] = d[i][0];
				d[i][0] = f[2 - i][2];
				f[2 - i][2] = v;
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[j][2 - i] = r[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					r[i][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				char v = u[2 - i][2];
				u[2 - i][2] = f[2 - i][2];
				f[2 - i][2] = d[i][0];
				d[i][0] = b[i][0];
				b[i][0] = v;
			}
		}
	}
	else {
		if (s[1] == '-') {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[2 - j][i] = d[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					d[i][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				char v = b[2][i];
				b[2][i] = l[2][i];
				l[2][i] = f[2][i];
				f[2][i] = r[2][i];
				r[2][i] = v;
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tmp[j][2 - i] = d[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					d[i][j] = tmp[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				char v = b[2][i];
				b[2][i] = r[2][i];
				r[2][i] = f[2][i];
				f[2][i] = l[2][i];
				l[2][i] = v;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		reset();
		int num;
		cin >> num;
		while (num--) {
			string cmd;
			cin >> cmd;
			turn(cmd);
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << u[i][j];
			}
			cout << '\n';
		}
	}
}