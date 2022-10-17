#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    int small, middle, big;
    
    cin >> a >> b >> c;
    
    if (a < b) {
        if (b < c) {
            small = a;
            middle = b;
            big = c;
        }
        else if (a > c) {
            small = c;
            middle = a;
            big = b;
        }
        else {
            small = a;
            middle = c;
            big = b;
        }
    }
    else {
        if (a < c) {
            small = b;
            middle = a;
            big = c;
        }
        else if (c < b) {
            small = c;
            middle = b;
            big = a;
        }
        else {
            small = b;
            middle = c;
            big = a;
        }
    }
    
    cout << small << ' ' << middle << ' ' << big;
}