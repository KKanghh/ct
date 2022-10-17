#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<long long> V;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		V.push_back(num);
	}

	sort(V.begin(), V.end());
	int cnt = 0;
	int mx_cnt = 0;
	long long mx_num;
	for (int i = 0; i < V.size(); i++) {
		if (i == 0 || V[i] == V[i - 1]) cnt++;
		else cnt = 1;
		if (cnt > mx_cnt) {
			mx_cnt = cnt;
			mx_num = V[i];
		}
	}

	cout << mx_num;
}