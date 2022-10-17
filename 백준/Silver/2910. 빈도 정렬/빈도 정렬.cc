#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int, int>> V;
vector<int> K;
int N, C;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.X == b.X) {
		for (int e : K) {
			if (e == a.Y) return true;
			else if (e == b.Y) return false;
		}
	}
	return a.X > b.X;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int tmp;
		bool find = false;
		cin >> tmp;
		for (int j = 0; j < V.size(); j++) {
			if (tmp == V[j].Y) {
				V[j].X++;
				find = true;
				break;
			}
		}
		if (!find) V.push_back({ 1, tmp });
		K.push_back(tmp);
	}



	sort(V.begin(), V.end(), cmp);

	for (auto e : V) {
		for (int i = 0; i < e.X; i++) cout << e.Y << ' ';
	}
}