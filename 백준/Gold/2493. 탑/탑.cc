#include <bits/stdc++.h>
using namespace std;

struct apart {
    int floor;
    int num;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    stack<apart> S;

    S.push({ 100000001, 0 });
    for (int i = 1; i <= num; i++) {
        apart temp;
        cin >> temp.floor;
        temp.num = i;

        while (S.top().floor < temp.floor) S.pop();
        cout << S.top().num << ' ';
        S.push(temp);
    }
}
