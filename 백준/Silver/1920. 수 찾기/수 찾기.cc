#include <bits/stdc++.h>
using namespace std;

int num[100000];
int N, M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num, num + N);
    cin >> M;
    
    while (M--) {
        int temp;
        cin >> temp;
        int low = 0;
        int high = N - 1;
        bool find = false;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (num[mid] < temp) low = mid + 1;
            else if (num[mid] > temp) high = mid - 1;
            else {
                find = true;
                break;
            }
        }
        
        if (find) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    
}