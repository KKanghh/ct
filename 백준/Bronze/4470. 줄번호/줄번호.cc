#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n;
    cin >> n;
    getline(cin, s);
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        cout << i << ". " << s << '\n';
    }
}