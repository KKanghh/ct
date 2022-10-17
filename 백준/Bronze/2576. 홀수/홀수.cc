#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int sum = 0;
    int temp, smallest = 100;
    
    for (int i = 0; i < 7; i++) {
        cin >> temp;
        if (temp % 2) {
            sum += temp;
            if (temp < smallest) smallest = temp;
        }
    }
    if (smallest == 100) cout << -1;
    else cout << sum << '\n' << smallest;
}