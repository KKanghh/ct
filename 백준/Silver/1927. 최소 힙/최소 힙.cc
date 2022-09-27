#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x) {
	heap[++sz] = x;
	int tmp = sz;
	while (heap[tmp] < heap[tmp / 2]) {
		swap(heap[tmp], heap[tmp / 2]);
		tmp /= 2;
	}
}

int top() {
	return heap[1];
}

void pop() {
	if (sz == 0) return;
	swap(heap[1], heap[sz]);
	heap[sz--] = 0;
	int tmp = 1;
	while (true) {
		if (tmp * 2 > 100005) break;
		else if (heap[tmp * 2] == 0 && heap[tmp * 2 + 1] == 0) break;
		else if (heap[tmp * 2 + 1] == 0) {
			if (heap[tmp * 2] < heap[tmp]) {
				swap(heap[tmp], heap[tmp * 2]);
				tmp = tmp * 2;
			}
			else break;
		}
		else {
			if (heap[tmp * 2] > heap[tmp] && heap[tmp * 2 + 1] > heap[tmp]) break;
			else {
				if (heap[tmp * 2] < heap[tmp * 2 + 1]) {
					swap(heap[tmp], heap[tmp * 2]);
					tmp = tmp * 2;
				}
				else {
					swap(heap[tmp], heap[tmp * 2 + 1]);
					tmp = tmp * 2 + 1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int op;
		cin >> op;
		if (op == 0) {
			cout << top() << '\n';
			pop();
		}
		else {
			push(op);
		}
	}
}