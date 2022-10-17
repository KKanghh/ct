#include <bits/stdc++.h>
using namespace std;
bool p = true;
int num[25];
int iter = 0;
int main() {
	string s;
	cin >> s;
	int n = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			n *= 10;
			n += s[i] - '0';
		}
		else {
			if (p) {
				num[iter] += n;
			}
			else {
				iter++;
				num[iter] = n;
			}
			n = 0;
			p = s[i] == '+';
		}
	}
	if (p) {
		num[iter] += n;
	}
	else {
		iter++;
		num[iter] = n;
	}
	int ans = num[0];
	for (int i = 1; i <= iter; i++) {
		ans -= num[i];
	}
	cout << ans;
}