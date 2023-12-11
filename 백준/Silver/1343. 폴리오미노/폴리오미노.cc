#include <bits/stdc++.h>
using namespace std;
vector<int> V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'X') cnt++;
        else {
            if (cnt % 2) {
                cout << -1;
                return 0;
            }
            V.push_back(cnt);
            cnt = 0;
        }
    }


    if (cnt % 2) {
        cout << -1;
        return 0;
    }
    V.push_back(cnt);
    

    for (int i = 0; i < V.size(); i++) {
        for (int j = 0; j < V[i] / 4; j++) cout << "AAAA";
        V[i] = V[i] % 4;
        for (int j = 0; j < V[i] / 2; j++) cout << "BB";
        if (i < V.size() - 1) cout << '.';
    }
}