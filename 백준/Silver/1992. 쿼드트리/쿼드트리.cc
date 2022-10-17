#include <bits/stdc++.h>
using namespace std;
int board[64][64];

bool check(int a, int b, int n) {
	for (int i = a; i < a + n; i++) {
		for (int j = b; j < b + n; j++) {
			if (board[a][b] != board[i][j]) return false;
		}
	}
	return true;
}

void quadtree(int a, int b, int n) {
	if (check(a, b, n)) {
		cout << board[a][b];
		return;
	}
	int half = n / 2;
	cout << '(';
	for (int i = a; i < a + n; i += half) {
		for (int j = b; j < b + n; j += half) {
			quadtree(i, j, half);
		}
	}
	cout << ')';

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char input;
			cin >> input;
			board[i][j] = input - '0';
		}
	}
	quadtree(0, 0, N);
	
}