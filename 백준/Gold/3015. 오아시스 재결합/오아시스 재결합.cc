#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    stack<pair<int, int>> S;
    long long ans = 0;

    for (int i = 1; i <= num; i++) {
        int temp, cnt = 1;
        cin >> temp;
        while (!S.empty() && S.top().X <= temp) {
            ans += S.top().Y;
            if (S.top().X == temp) cnt += S.top().Y;
            S.pop();
        }
        if (!S.empty()) {
            ans += 1;
        }
            
        S.push({ temp, cnt });
    }

    cout << ans;
}
