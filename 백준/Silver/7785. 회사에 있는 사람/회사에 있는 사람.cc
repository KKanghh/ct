#include <bits/stdc++.h>
using namespace std;

unordered_set<string> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string name, go;
		cin >> name >> go;
		if (go == "leave") {
			S.erase(name);
		}
		else {
			S.insert(name);
		}
	}
	vector<string> V(S.begin(), S.end());
	sort(V.begin(), V.end(), greater <string>());
	for (string e : V) cout << e << '\n';

}