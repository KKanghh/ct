#include <bits/stdc++.h>
using namespace std;
int num[10];
char oper[9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int mx = INT_MIN;

	string input;
	cin >> input;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) num[i / 2] = input[i] - '0';
		else oper[i / 2] = input[i];
	}

	int num_len = n / 2 + 1, oper_len = n / 2;
	int c = 1;

	for (int i = 0; i < num_len - 1; i++) {
		c *= 2;
	}

	for (int i = 0; i < c; i++) {
		int t = i;
		vector<bool> V;
		for (int j = 0; j < num_len - 1; j++) {
			V.push_back(t % 2);
			t /= 2;
		}

		int len = V.size();
		vector<int> cal_num;
		vector<char> cal_oper;
		int cur = 0;
		for (; cur < len; cur++) {
			if (V[cur]) {
				int a = num[cur];
				int b = num[cur + 1];
				if (oper[cur] == '+') cal_num.push_back(a + b);
				if (oper[cur] == '-') cal_num.push_back(a - b);
				if (oper[cur] == '*') cal_num.push_back(a * b);
				if (cur + 1 < oper_len) cal_oper.push_back(oper[cur + 1]);
				cur++;
			}
			else {
				cal_num.push_back(num[cur]);
				cal_oper.push_back(oper[cur]);
			}
		}

		if (cur == len) {
			cal_num.push_back(num[num_len - 1]);
		}

		int res = cal_num[0];
		len = cal_num.size();
		for (int j = 1; j < len; j++) {
			if (cal_oper[j - 1] == '+') res += cal_num[j];
			if (cal_oper[j - 1] == '-') res -= cal_num[j];
			if (cal_oper[j - 1] == '*') res *= cal_num[j];
		}

		mx = max(mx, res);
	}

	cout << mx;
}