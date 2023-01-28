#include <bits/stdc++.h>
using namespace std;
unordered_map <string, int> answer;
string test[2500];
bool cases[2500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(cases, cases + 2500, 1);
	cases[0] = false;
	cases[1] = false;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string an;
		cin >> an;
		answer[an] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> test[i];
	}
	int right = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (answer[test[i]] < answer[test[j]]) right++;
		}
	}

	cout << right << '/' << n * (n - 1) / 2;
}