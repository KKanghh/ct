#include <bits/stdc++.h>
using namespace std;
vector<string> V;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	cin >> input;
	while (input != "") {
		V.push_back(input);
		input.erase(0, 1);
	}

	sort(V.begin(), V.end());
	for (string e : V) cout << e << '\n';
}