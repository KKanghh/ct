#include <bits/stdc++.h>
using namespace std;
int cnt[4];
deque<char> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s, p, ans = 0;
	cin >> s >> p;

	string S;
	cin >> S;
	int cur = 0;
	while (dq.size() < p) {
		dq.push_back(S[cur]);
		if (S[cur] == 'A') cnt[0]++;
		else if (S[cur] == 'C') cnt[1]++;
		else if (S[cur] == 'G') cnt[2]++;
		else cnt[3]++;
		cur++;
	}

	int a, c, g, t;

	cin >> a >> c >> g >> t;
	if (cnt[0] >= a && cnt[1] >= c && cnt[2] >= g && cnt[3] >= t) ans++;

	while (cur < s) {
		if (dq.front() == 'A') cnt[0]--;
		else if (dq.front() == 'C') cnt[1]--;
		else if (dq.front() == 'G') cnt[2]--;
		else cnt[3]--;
		dq.pop_front();

		dq.push_back(S[cur]);
		if (S[cur] == 'A') cnt[0]++;
		else if (S[cur] == 'C') cnt[1]++;
		else if (S[cur] == 'G') cnt[2]++;
		else cnt[3]++;
		cur++;
		if (cnt[0] >= a && cnt[1] >= c && cnt[2] >= g && cnt[3] >= t) ans++;
	}

	cout << ans;
}