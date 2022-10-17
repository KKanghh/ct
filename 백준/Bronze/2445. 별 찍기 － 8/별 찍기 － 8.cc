#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    
    for (int i = 1; i < num; i++) {
        for (int j = 0; j < i; j++) cout << '*';
        for (int j = 0; j < 2 * num - 2 * i; j++) cout << ' ';
        for (int j = 0; j < i; j++) cout << '*';
        cout << '\n';
    }
    for (int i = 0; i < 2 * num; i++) cout << '*';
    cout << '\n';
    for (int i = num - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) cout << '*';
        for (int j = 0; j < 2 * num - 2 * i; j++) cout << ' ';
        for (int j = 0; j < i; j++) cout << '*';
        cout << '\n';
    }
}