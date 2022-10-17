#include <bits/stdc++.h>
using namespace std;

int main() {
    int input, sum;
    ios::sync_with_stdio(0);
    cin.tie(0);
    string result = "DCBAE";
    
    for (int i = 0; i < 3; i++) {
        sum = 0;
        for (int j = 0; j < 4; j++) {
            cin >> input;
            sum += input;
        }
        cout << result[sum] << '\n';
    }
}