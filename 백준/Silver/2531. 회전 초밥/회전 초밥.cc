#include <bits/stdc++.h>
using namespace std;
int sushi[30000];
map<int, int> eat;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, d, k, c, mx = 0;
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) cin >> sushi[i];
	
	int en = 0;
	for (int st = 0; st < n; st++) {
		while (en < st + k) {
			int cur = en - (en >= n) * n;
			if (eat.count(sushi[cur])) eat[sushi[cur]]++;
			else eat.insert({ sushi[cur], 1 });
			en++;
		}

		mx = max(mx, (int)eat.size() + (1 - (int)eat.count(c)));
		eat[sushi[st]]--;
		if (eat[sushi[st]] == 0) {
			eat.erase(sushi[st]);
		}
	}

	cout << mx;
}