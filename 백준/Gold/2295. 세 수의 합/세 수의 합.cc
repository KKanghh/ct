#include <bits/stdc++.h>
using namespace std;
int arr[1000], n;
vector<int> two;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) two.push_back(arr[i] + arr[j]);
	}
	sort(two.begin(), two.end());
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (binary_search(two.begin(), two.end(), arr[j] - arr[i])) mx = max(mx, arr[j]);
		}
	}
	cout << mx;
}