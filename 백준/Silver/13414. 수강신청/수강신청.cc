#include <bits/stdc++.h>
using namespace std;
map<string, int> d;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, l;
	cin >> k >> l;

	for (int i = 0; i < l; i++) {
		string h;
		cin >> h;
		d[h] = i;
	}
	vector<pair<string, int>> V(d.begin(), d.end());
	sort(V.begin(), V.end(), cmp);
	for (int i = 0; i < k && i < V.size(); i++) cout << V[i].first << '\n';
}