#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    long long res = N - M;
    if (res < 0) res = -res;
    cout << res;
}