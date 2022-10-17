#include <bits/stdc++.h>
using namespace std;

int first[26], second[26];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    cin >> input;
    
    for (char e: input) {
        first[e - 'a']++;
    }
    
    cin >> input;
    
    for (char e: input) {
        second[e - 'a']++;
    }
    
    int count = 0;
    
    for (int i = 0; i < 26; i++) {
        count += max(first[i], second[i]) - min(first[i], second[i]);
    }
    
    cout << count;
}