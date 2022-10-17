#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    cin >> input;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int temp = input[i] - '0';
        sum += temp * temp * temp * temp * temp;
    }
    
    cout << sum;
}