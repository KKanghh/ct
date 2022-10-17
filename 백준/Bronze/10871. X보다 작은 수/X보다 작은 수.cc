#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int N, X, tmp;
	cin >> N >> X;
	//int* array = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp < X) cout << tmp << " ";
	}
	return 0;
}