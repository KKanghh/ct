#include <bits/stdc++.h>
using namespace std;
vector<int> V;
bool find(vector<int> V, int n) {
	for (int i = 0; i < V.size(); i++) {
		if (V[i] == n) return true;
	}
	return false;

}
void func(int n, int m) {
	if (V.size() == m) {
		for (auto e : V) cout << e << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (find(V,i)) continue;
		V.push_back(i);
		func(n, m);
		V.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	func(N, M);
	
}