#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    
    for (int i = num; i > 1; i--) {
        for (int j = num - i; j > 0; j--) cout << ' ';
        for (int j = 0; j < i * 2 - 1; j++) cout << '*';
        cout << '\n';
    }
    for (int i = 0; i < num - 1; i++) cout << ' ';
    cout << "*\n";
    for (int i = 2; i <= num; i++) {
        for (int j = num - i; j > 0; j--) cout << ' ';
        for (int j = 0; j < i * 2 - 1; j++) cout << '*';
        cout << '\n';
    }
}