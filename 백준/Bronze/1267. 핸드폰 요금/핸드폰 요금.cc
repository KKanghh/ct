#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int month;
    cin >> month;
    int Y = 0, M = 0, hour;
    for (int i = 0; i < month; i++) {
        cin >> hour;
        Y += (hour / 30 + 1) * 10;
        M += (hour / 60 + 1) * 15;
    }
    
    if (M > Y) cout << "Y " << Y;
    else if (M == Y) cout <<"Y M " << Y;
    else cout << "M " << M;
}