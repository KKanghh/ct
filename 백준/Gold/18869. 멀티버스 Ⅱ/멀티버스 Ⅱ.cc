#include <bits/stdc++.h>
using namespace std;
int galaxy[100][10000];
bool selected[100];
int n, m;

bool cmp(int* a, int* b) {
	for (int i = 0; i < m; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fill(selected + 2, selected + 100, true);

	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector<int> V;
		for (int j = 0; j < m; j++) {
			cin >> galaxy[i][j];
			V.push_back(galaxy[i][j]);
		}

		sort(V.begin(), V.end());
		for (int j = 0; j < m; j++) {
			galaxy[i][j] = lower_bound(V.begin(), V.end(), galaxy[i][j]) - V.begin();
		}

	}
	int cnt = 0;
	do {
		int a = -1, b = -1;

		for (int i = 0; i < n; i++) {
			if (selected[i] == false) {
				if (a == -1) a = i;
				else {
					b = i;
					break;
				}
			}
		}
		if (cmp(galaxy[a], galaxy[b])) cnt++;
	} while (next_permutation(selected, selected + n));

	cout << cnt;
}