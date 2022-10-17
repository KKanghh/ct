#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int alphabet[26] = {};
        string a, b;
        cin >> a >> b;
        
        for (char e: a) alphabet[e - 'a']++;
        for (char e: b) alphabet[e - 'a']--;
        int count = 0;
        for (int e: alphabet) {
            if (e == 0) count++;
        }
        
        if (count == 26) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}