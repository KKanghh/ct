#include <bits/stdc++.h>
using namespace std;
int n, w, l, weight, sec;
queue<int> truck;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w >> l;
	queue<int> bridge;
	for (int i = 0; i < w; i++) bridge.push(0);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		truck.push(tmp);
	}

	while (!truck.empty()) {
		weight -= bridge.front();
		bridge.pop();
		if (weight + truck.front() <= l) {
			weight += truck.front();
			bridge.push(truck.front());
			truck.pop();
		}
		else {
			bridge.push(0);
		}
		sec++;
	}

	cout << sec + w;
}