#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int size, diff;
    cin >> size >> diff;
    list<int> L;
    
    for (int i = 1; i <= size; i++) {
        L.push_back(i);
    }
    list<int>::iterator it = L.begin();
    cout << '<';
    while (true) {
        for (int i = 0; i < diff - 1; i++) {
            it++;
            if (it == L.end()) it = L.begin();
        }
        cout << *it;
        it = L.erase(it);
        if (it == L.end()) it = L.begin();
        if (L.empty()) break;
        cout << ", ";
    }
    
    cout << '>';
}