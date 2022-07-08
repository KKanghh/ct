#include <bits/stdc++.h>
using namespace std;
int arr[20];
bool isused[20];
int N, S, cnt, res;
void func(int n) {
	if (res == S && n > 0) {
		cnt++;
	}
	for (int i = n; i < N; i++) {
		isused[i] = true;
		res += arr[i];
		func(i + 1);
		res -= arr[i];
		isused[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	func(0);
	cout << cnt;
}