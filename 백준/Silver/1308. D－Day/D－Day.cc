	#include <bits/stdc++.h>
	using namespace std;
	int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool isyun(int year) {
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}
	int main() {
		ios::sync_with_stdio(0);
		cin.tie(0);

		int ty, tm, td, dy, dm, dd;
		cin >> ty >> tm >> td >> dy >> dm >> dd;

		if (dy - ty > 1000 || (dy - ty == 1000 && dm - tm >= 0 && dd - td >= 0)) {
			cout << "gg";
			return 0;
		}

		if (dy == ty) {
			if (dm == tm) {
				cout << "D-" << dd - td;
			}
			else {
				int cnt = 0;
				cnt += day[tm - 1] - td;
				for (int i = tm; i < dm - 1; i++) {
					cnt += day[i];
				}
				cnt += dd;
				if (isyun(dy) && tm <= 2 && dm > 2) cnt += 1;
				cout << "D-" << cnt;
			}
		}
		else {
			int cnt = 0;
			cnt += day[tm - 1] - td;
			for (int i = tm; i < 12; i++) {
				cnt += day[i];
			}
			if (isyun(ty) && tm <= 2) cnt += 1;
			for (int yr = ty + 1; yr < dy; yr++) {
				if (isyun(yr)) cnt += 366;
				else cnt += 365;
			}
			for (int i = 0; i < dm - 1; i++) {
				cnt += day[i];
			}
			cnt += dd;
			if (isyun(dy) && dm > 2) cnt += 1;
			cout << "D-" << cnt;
		}
	}