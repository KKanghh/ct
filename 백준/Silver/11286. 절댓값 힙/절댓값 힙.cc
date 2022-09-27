#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a > b;
		return abs(a) > abs(b);
	}
};


priority_queue<int, vector<int>, cmp> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int op;
		cin >> op;
		if (op == 0) {
			if (Q.empty()) cout << 0 <<'\n';
			else {
				cout << Q.top() << '\n';
				Q.pop();
			}
		}
		else {
			Q.push(op);
		}
	}
}