#include <bits/stdc++.h>

using namespace std;
vector<int> A, B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, t = 1;

	int num = 0, i = 1;

	while (num <= 1000000000) {
		num += i++;
		if (sqrt(num + 1) == (int)sqrt(num + 1)) A.push_back(num + 1);
	}

	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		cout <<"Case " << t++ << ": " << lower_bound(A.begin(), A.end(), b) - upper_bound(A.begin(), A.end(), a) << '\n';
	}

}