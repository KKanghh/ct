#include <bits/stdc++.h>
using namespace std;

char freq[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    int temp;
    
    int count = 0;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        freq[temp] = 1;
    }

    int goal;
    cin >> goal;

    for (int i = 1; i <= (goal - 1) / 2; i++) {
        if (goal - i > 1000000) continue;
        if (freq[i] && freq[goal - i]) count++;
        
    }

    cout << count;
}