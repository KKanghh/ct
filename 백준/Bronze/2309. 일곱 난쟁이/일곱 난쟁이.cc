#include <bits/stdc++.h>
using namespace std;

int main() {
    int height[9], sum = 0, one, two, find = false;
    for (int i = 0; i < 9; i++) {
        cin >> height[i];
        sum += height[i];
    }
    sort(height, height + 9);
    
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - height[i] - height[j] == 100) {
                one = i;
                two = j;
                find = true;
                break;
            }
        }
        if (find) break;
    }
    
    for (int i = 0; i < 9; i++) {
        if (i == one || i == two) continue;
        cout << height[i] << '\n';
    }
}