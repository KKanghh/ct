#include <bits/stdc++.h>
using namespace std;
set<string> S;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;
	int n = input.length();
	for (int i = 0; i < n; i++) {
		string k;
		for (int j = i; j < n; j++) {
			k.push_back(input[j]);
			S.insert(k);
		}
	}

	cout << S.size();
}