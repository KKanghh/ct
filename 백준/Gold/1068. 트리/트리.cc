#include <bits/stdc++.h>
using namespace std;
vector<int> child[50];
int parent[50];
bool vis[50];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r = 0, cnt = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> parent[i];
		if (parent[i] == -1) {
			r = i;
			continue;
		}
		child[parent[i]].push_back(i);
	}

	vis[r] = true;
	Q.push(r);
	
	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		if (child[k].size() == 0) cnt++;
		for (int e : child[k]) {
			if (vis[e]) continue;
			vis[e] = true;
			Q.push(e);
		}
	}

	int del;
	cin >> del;

	fill(vis, vis + n, false);

	Q.push(del);
	vis[del] = true;

	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		if (child[k].size() == 0) cnt--;
		for (int e : child[k]) {
			vis[e] = true;
			Q.push(e);
		}
	}

	if (parent[del] >= 0 && child[parent[del]].size() == 1) cnt++;


	cout << cnt;

}