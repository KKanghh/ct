#include <bits/stdc++.h>
using namespace std;
int A[50], B[50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}

	int mx = 0, mxprice = 0;
	for (int i = 0; i <= 1e6; i++) {
		int price = 0;
		for (int j = 0; j < n; j++) {
			if (A[j] >= i && i > B[j]) price += i - B[j];
		}
		
		if (price > mxprice) {
			mx = i;
			mxprice = price;
		}
	}

	cout << mx;
}