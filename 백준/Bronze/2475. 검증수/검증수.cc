#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	for (int i = 0; i < 5; i++) {
		int temp;
		cin >> temp;
		n += pow(temp, 2);
	}

	cout << n % 10;
	
}