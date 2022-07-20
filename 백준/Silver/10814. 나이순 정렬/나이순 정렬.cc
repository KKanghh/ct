#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, string>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, age;
    string name;
    cin >> N;
    for (int time = 0; time < N; time++) {
        cin >> age >> name;
        v.push_back({ age, time, name });
    }

    sort(v.begin(), v.end());

    for (auto e : v) {
        int tmp;
        tie(age, tmp, name) = e;
        cout << age << ' ' << name << '\n';
    }
}