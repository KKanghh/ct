#include <bits/stdc++.h>
using namespace std;

int nums[201];
int main() {
    int num, temp;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        cin >> temp;
        nums[temp + 100]++;
    }
    
    int goal;
    cin >> goal;
    
    cout << nums[goal + 100];
}