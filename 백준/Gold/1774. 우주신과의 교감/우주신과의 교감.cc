#include <bits/stdc++.h>
using namespace std;
vector<tuple<double, int, int>> edge;
pair<int, int> v[1001];
int p[1001];
int cnt;

int find(int n) {
	if (p[n] <= 0) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a); b = find(b);
	if (p[a] == p[b]) p[a]--;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
}

double dist(int i, int j) {
	double x = v[i].first - v[j].first;
	x *= x;
	double y = v[i].second - v[j].second;
	y *= y;
	return sqrt(x + y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		v[i] = { x, y };
		for (int j = 1; j < i; j++) {
			edge.push_back({ dist(i, j), i, j });
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b)) {
			merge(a, b);
			cnt++;
		}
		
	}

	sort(edge.begin(), edge.end());

	int cur = 0;
	double cost = 0;

	while (cnt < n - 1) {
		double a;
		int b, c;
		tie(a, b, c) = edge[cur++];
		if (find(b) == find(c)) continue;
		merge(b, c);
		cost += a;
		cnt++;
	}
	
	printf("%.2f", cost);
	
}