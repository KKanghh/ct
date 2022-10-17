#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    vector<string> word_list;

    while (num--) {
        string temp;
        cin >> temp;
        word_list.push_back(temp);
    }

    sort(word_list.begin(), word_list.end(), cmp);

    for (int i = 0; i < word_list.size() - 1; i++) {
        if (word_list[i] == word_list[i + 1]) continue;
        cout << word_list[i] << ' ';
    }
    cout << word_list[word_list.size() - 1];
}