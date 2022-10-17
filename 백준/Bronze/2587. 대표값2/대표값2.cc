#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int list[5], sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> list[i];
        sum += list[i];
    }
    sort(list, list + 5);
    cout << sum / 5 << '\n' << list[2];
}