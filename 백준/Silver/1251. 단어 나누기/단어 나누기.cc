#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;
	int k = input.length();
	vector<string> V;
	for (int i = 1; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			string tmp;
			for (int cur = i - 1; cur >= 0; cur--) {
				tmp.push_back(input[cur]);
			}
			for (int cur = j - 1; cur >= i; cur--) {
				tmp.push_back(input[cur]);
			}
			for (int cur = k - 1; cur >= j; cur--) {
				tmp.push_back(input[cur]);
			}
			V.push_back(tmp);
		}
	}

	sort(V.begin(), V.end());
	cout << V[0];
}