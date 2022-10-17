#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<pair<int, int>> d;

	int num, L;
	cin >> num >> L;

	for (int i = 1; i <= num; i++) {
		int add;
		cin >> add;
		if (d.empty()) d.push_back({ add, i });
		else if (add < d.front().X) d.push_front({ add, i });
		else if (add < d.back().X) {
			while (add < d.back().X) d.pop_back();
			d.push_back({ add, i });
		}
		else d.push_back({ add, i });


		while (d.front().Y < i - L + 1) d.pop_front();
		cout << d.front().X << ' ';
	}


}