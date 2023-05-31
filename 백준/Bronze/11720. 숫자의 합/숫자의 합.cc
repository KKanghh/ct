#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int sum = 0;

	for (int i = 0; i < s.size(); i++) sum += s[i] - '0';
	cout << sum;
}