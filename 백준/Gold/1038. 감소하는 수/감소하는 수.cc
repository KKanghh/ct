#include<bits/stdc++.h>
using namespace std;
vector<long long> D;
bool selected[10];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < 11; i++) {
		fill(selected, selected + 10, 1);
		fill(selected, selected + i, 0);
		do {
			long long k = 0;
			for (int j = 9; j >= 0; j--) {
				if (selected[j] == false) {
					k *= 10;
					k += j;
				}
			}
			D.push_back(k);
		} while (next_permutation(selected, selected + 10));
	}
	sort(D.begin(), D.end());

	int n;
	cin >> n;
	if (n >= D.size()) cout << -1;
	else cout << D[n];
}