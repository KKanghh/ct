#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    long long r = 1, M = 1234567891, res = 0;
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        long long k = S[i] - 'a' + 1;
        res += (k * r) % M;
        res %= M;
        r = r * 31 % M;
    }

    cout << res;
}