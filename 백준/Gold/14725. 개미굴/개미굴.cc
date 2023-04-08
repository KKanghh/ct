#include <bits/stdc++.h>
using namespace std;
vector<int> child[15001];
string name[15001];
int p[15001];
int cnt = 1;

bool cmp(int a, int b) {
	return name[a] < name[b];
}

void dfs(int a, int depth) {
	sort(child[a].begin(), child[a].end(), cmp);

	for (int e : child[a]) {
		for (int i = 0; i < depth; i++) cout << "--";
		cout << name[e] << '\n';
		dfs(e, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int k;
		cin >> k;
		int cur = 0;
		for (int depth = 0; depth < k; depth++) {
			string s;
			cin >> s;

			int temp = cur;
			for (int e : child[temp]) {
				if (name[e] == s) {
					cur = e;
					break;
				}
			}

			if (temp == cur) {
				name[cnt] = s;
				child[cur].push_back(cnt);
				cur = cnt;
				cnt++;
			}

		}
	}

	dfs(0, 0);

}