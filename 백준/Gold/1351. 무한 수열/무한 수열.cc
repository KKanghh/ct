#include <bits/stdc++.h>
using namespace std;
long long n, p, q;
map<long long, long long> m;

long long func(long long a) {
	if (m.count(a)) return m[a];
	else {
		return m[a] = func(a / p) + func(a / q);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	m[0] = 1;
	m[1] = 2;
	
	cin >> n >> p >> q;

	cout << func(n);

}