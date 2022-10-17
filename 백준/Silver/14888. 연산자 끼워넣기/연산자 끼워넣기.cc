#include <bits/stdc++.h>
using namespace std;
vector<int> num;
int oper[4];
vector<int> operlist;
int mn = 1000000000, mx = -1000000000;

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
		for (int j = 0; j < oper[i]; j++) operlist.push_back(i);
	}

	do {
		int ans = num[0];
		for (int i = 1; i < n; i++) {
			if (operlist[i - 1] == 0) ans += num[i];
			else if (operlist[i - 1] == 1) ans -= num[i];
			else if (operlist[i - 1] == 2) ans *= num[i];
			else if (operlist[i - 1] == 3) ans /= num[i];
		}
		mn = min(ans, mn);
		mx = max(ans, mx);
	} while (next_permutation(operlist.begin(), operlist.end()));

	cout << mx << '\n' << mn;

}