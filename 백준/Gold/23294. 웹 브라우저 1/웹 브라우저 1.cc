#include <bits/stdc++.h>
using namespace std;
int CAP[2001], cache;
deque<int> pre, nxt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, Q, C;
	cin >> N >> Q >> C;

	for (int i = 1; i <= N; i++) {
		cin >> CAP[i];
	}

	int cur = -1;
	while (Q--) {
		char command;
		cin >> command;
		if (command == 'B') {
			if (pre.size() > 0) {
				nxt.push_front(cur);
				cur = pre.back();
				pre.pop_back();
			}
		}
		else if (command == 'F') {
			if (nxt.size() > 0) {
				pre.push_back(cur);
				cur = nxt.front();
				nxt.pop_front();
			}
		}
		else if (command == 'A') {
			int page;
			cin >> page;
			deque<int> empty;
			for (int i = 0; i < nxt.size(); i++) {
				cache -= CAP[nxt[i]];
			}
			nxt = empty;
			if (cur != -1) pre.push_back(cur);
			cur = page;
			cache += CAP[cur];

			while (cache > C) {
				int k = pre.front();
				pre.pop_front();
				cache -= CAP[k];
			}
		}
		else {
			if (pre.empty()) continue;
			deque<int> temp;
			temp.push_front(pre.back());
			pre.pop_back();
			while (!pre.empty()) {
				if (pre.back() != temp.front()) {
					temp.push_front(pre.back());
				}
				else {
					cache -= CAP[pre.back()];
				}
				pre.pop_back();
			}
			pre = temp;
		}
	}

	cout << cur << '\n';
	for (int i = pre.size() - 1; i >= 0; i--) cout << pre[i] << ' ';
	if (pre.empty()) cout << -1;
	cout << '\n';
	for (int i = 0; i < nxt.size(); i++) cout << nxt[i] << ' ';
	if (nxt.empty()) cout << -1;
}