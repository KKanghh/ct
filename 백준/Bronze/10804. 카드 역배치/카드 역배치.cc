#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    int card[21] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    for (int i = 0; i < 10; i++) {
        cin >> a >> b;
        for (int j = 0; j < (b - a + 1) / 2; j++) {
            swap(card[a + j], card[b - j]);
        }
    }
    
    for (int i = 1; i < 21; i++) {
        cout << card[i] << ' ';
    }
}