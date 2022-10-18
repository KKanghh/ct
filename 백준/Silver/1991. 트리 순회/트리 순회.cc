#include <bits/stdc++.h>
using namespace std;
int l[26];
int r[26];

void preorder(int n) {
	char a = 'A' + n;
	cout << a;
	if (l[n]) preorder(l[n]);
	if (r[n]) preorder(r[n]);
}

void inorder(int n) {
	char a = 'A' + n;
	if (l[n]) inorder(l[n]);
	cout << a;
	if (r[n]) inorder(r[n]);
}

void postorder(int n) {
	char a = 'A' + n;
	if (l[n]) postorder(l[n]);
	if (r[n]) postorder(r[n]);
	cout << a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.') l[a - 'A'] = b - 'A';
		if (c != '.') r[a - 'A'] = c - 'A';
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
}