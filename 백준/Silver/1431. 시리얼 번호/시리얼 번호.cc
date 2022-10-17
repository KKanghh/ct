#include <bits/stdc++.h>
using namespace std;
vector<string> V;

bool cmp(string& a, string& b) {
	if (a.length() == b.length()) {
		int na = 0, nb = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] <= '9' && a[i] >= '0') na += a[i] - '0';
			if (b[i] <= '9' && b[i] >= '0') nb += b[i] - '0';
		}
		if (na == nb) return a < b;
		return na < nb;
	}
	return a.length() < b.length();
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		V.push_back(tmp);
	}

	sort(V.begin(), V.end(), cmp);
	for (string e : V) cout << e << '\n';
}