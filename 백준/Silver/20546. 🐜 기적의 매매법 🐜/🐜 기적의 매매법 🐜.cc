#include <bits/stdc++.h>
using namespace std;
int price[14];
int an, bn;
int in, de;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a = n, b = n;

	for (int i = 0; i < 14; i++) cin >> price[i];

	for (int i = 0; i < 14; i++) {
		an += a / price[i];
		a %= price[i];
	}
	a += an * price[13];

	
	for (int i = 1; i < 14; i++) {
		if (price[i] > price[i - 1]) {
			in++;
			de = 0;
		}
		else if (price[i] < price[i - 1]) {
			de++;
			in = 0;
		}
		else {
			in = 0;
			de = 0;
		}

		if (in >= 3) {
			b += price[i] * bn;
			bn = 0;
		}
		if (de >= 3) {
			bn += b / price[i];
			b %= price[i];
		}
	}

	b += price[13] * bn;

	if (a > b) cout << "BNP";
	else if (a < b) cout << "TIMING";
	else cout << "SAMESAME";

}