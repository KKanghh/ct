#include <bits/stdc++.h>
using namespace std;
int note[8];
int asc[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
int desc[8] = { 8, 7, 6, 5, 4, 3, 2, 1 };

int main() {
	for (int i = 0; i < 8; i++) {
		cin >> note[i];
	}


	if (equal(note, note + 8, asc, asc + 8)) cout << "ascending";
	else if (equal(note, note + 8, desc, desc + 8)) cout << "descending";
	else cout << "mixed";
}