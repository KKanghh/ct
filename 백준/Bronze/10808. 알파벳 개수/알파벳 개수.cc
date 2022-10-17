#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    int result[26];
    
    fill(result, result + 26, 0);
    cin >> input;
    
    for (int i = 0; i < input.size(); i++) {
        result[input[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) cout << result[i] << ' ';
    
    
}