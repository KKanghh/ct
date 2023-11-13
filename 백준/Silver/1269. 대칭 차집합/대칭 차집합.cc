#include <bits/stdc++.h>
using namespace std;
unordered_set<int> A, B;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        int n;
        cin >> n;
        A.insert(n);
    }
    for (int j = 0; j < b; j++) {
        int n;
        cin >> n;
        B.insert(n);
    }
    A.merge(B);
    int c = B.size();

    cout << a + b - 2 * c;
}