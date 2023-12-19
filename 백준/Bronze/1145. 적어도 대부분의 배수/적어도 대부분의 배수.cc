#include <bits/stdc++.h>
using namespace std;
int A[5];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) cin >> A[i];

    int num = 1;
    while (true) {
        int cnt = 0;

        for (int i = 0; i < 5; i++) {
            cnt += (num % A[i] == 0);
        }

        if (cnt >= 3) break;
        num++;
    }

    cout << num;
}