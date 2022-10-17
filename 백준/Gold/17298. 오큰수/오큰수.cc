#include <bits/stdc++.h>
using namespace std;

struct apart {
    int floor;
    int num;
};

int cnt[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    stack<apart> S;

    for (int i = 1; i <= num; i++) {
        apart temp;
        cin >> temp.floor;
        temp.num = i;

        while (!S.empty() && S.top().floor < temp.floor) {
            cnt[S.top().num] = temp.floor;
            S.pop();
        }

        S.push(temp);
    }

    while (!S.empty()) {
        cnt[S.top().num] = -1;
        S.pop();
    }

    for (int i = 1; i <= num; i++) cout << cnt[i] << ' ';
}
