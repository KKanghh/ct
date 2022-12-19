#include <bits/stdc++.h>
using namespace std;
bool isL = true;
queue<int> v;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	if (s[0] >= 'A' && s[0] <= 'Z') {
		v.push(0);
		isL = false;
	}

	for (int i = 0; i < s.length(); i++) {
		int t = i;
		while (t < s.length() && (s[t] >= 'a' && s[t] <= 'z') == isL) t++;
		v.push(t - i);
		isL = !isL;
		i = t - 1;
	}

	int cnt = 0;
	cnt += v.front();
	v.pop();
	while (!v.empty()) {
		if (v.front() == 1) {
			v.pop();
			if (v.empty()) {
				cnt += 2;
			}
			else {
				cnt += 2 + v.front();
				v.pop();
			}
		}
		else {
			cnt += v.front() + 1;
			v.pop();
		}
	}

	cout << cnt;
}