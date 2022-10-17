#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int j = 0;
        for (; j < i; j++) cout << ' ';
        for (; j < num; j++) cout << '*';
        cout << '\n';
    }
}