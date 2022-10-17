#include <bits/stdc++.h>
using namespace std;
int cnt[10001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> V;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    
    for (int i = 0; i < 10001; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << i << '\n';
        }
    }
}