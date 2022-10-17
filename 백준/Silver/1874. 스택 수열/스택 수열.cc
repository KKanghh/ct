#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, cnt = 1;
    stack<int> S;
    string ans = "";

    cin >> num;

    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        while (cnt <= temp) {
            S.push(cnt++);
            ans += "+\n";
        }
        if (S.top() != temp) {
            cout << "NO";
            return 0;
        }
        S.pop();
        ans += "-\n";
    }

    cout << ans;
}
