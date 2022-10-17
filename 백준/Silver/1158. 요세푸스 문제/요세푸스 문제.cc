#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	list<int> L;
	

	int length, diff;

	cin >> length >> diff;
	for (int i = 1; i <= length; i++) {
		L.push_back(i);
	}
	cout << '<';
	list<int>::iterator t = L.begin();
	while (length--) {
		for (int i = 0; i < diff - 1; i++) {
			t++;
			if (t == L.end()) t = L.begin();
		}	
		cout << *t;
		if (length != 0) cout << ", ";
		t = L.erase(t);
		if (t == L.end()) t = L.begin();
	}

	cout << '>';
}