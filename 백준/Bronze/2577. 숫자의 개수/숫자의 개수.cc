#include <bits/stdc++.h>
using namespace std;

int result[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, num;
    cin >> a >> b >> c;
    num = a * b * c;
    string str = to_string(num);
    for (auto s : str) {
        result[s - '0']++;
    }

    for (int i : result) cout << i << '\n';
}