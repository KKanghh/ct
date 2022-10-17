#include <bits/stdc++.h>
using namespace std;

int result[9], big;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    while (num > 0) {
        if (num % 10 == 9) result[6]++;
        else result[num % 10]++;
        num /= 10;
    }
    result[6] = result[6] / 2 + result[6] % 2;
    for (int i : result) {
        if (i > big) big = i;
    }

    cout << big;
}