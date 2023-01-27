#include <bits/stdc++.h>
using namespace std;

vector<long long> A, B;

long long md(long long num) {
	if (num % 2) return 3 * num + 1;
	return num / 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		long long a, b;
		
		cin >> a >> b;

		if (a == 0 && b == 0) break;

		long long aa = a, bb = b;

		while (true) {
			A.push_back(a);
			if (a == 1) break;
			a = md(a);
		}

		while (true) {
			B.push_back(b);
			if (b == 1) break;
			b = md(b);
		}

		int lenA = A.size();
		int lenB = B.size();
		int minLen = min(lenA, lenB);
		int i, p;
		for (i = 0; i < minLen; i++) {
			if (A[lenA - i - 1] != B[lenB - i - 1]) break;
			p = A[lenA - i - 1];
		}

		cout << aa << " needs " << lenA - i << " steps, " << bb << " needs " << lenB - i << " steps, they meet at " << p << '\n';
		A.clear();
		B.clear();
	}
}