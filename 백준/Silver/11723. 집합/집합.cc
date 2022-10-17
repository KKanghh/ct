#include <bits/stdc++.h>
using namespace std;
bool S[21];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M;
	cin >> M;
	while (M--) {
		string oper;
		int num;
		cin >> oper;
		if (oper == "add") {
			cin >> num;
			S[num] = true;
		}
		else if (oper == "remove") {
			cin >> num;
			S[num] = false;
		}
		else if (oper == "check") {
			cin >> num;
			cout << S[num] << '\n';
		}
		else if (oper == "toggle") {
			cin >> num;
			S[num] = !S[num];
		}
		else if (oper == "all") {
			fill(S, S + 21, true);
		}
		else {
			fill(S, S + 21, false);
		}
	}
}