#include <bits/stdc++.h>
using namespace std;

const int N = 600001;
int unused = 1;
char dat[N];
int pre[N], nxt[N];

void insert_node(int addr, char input) {
    dat[unused] = input;

    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    nxt[addr] = unused;
    if (nxt[unused] != -1) pre[nxt[unused]] = unused;
    unused++;
}

void erase_node(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fill(dat, dat + N, -1);
    fill(pre, pre + N, -1);
    fill(nxt, nxt + N, -1);

    string input_first;
    cin >> input_first;
    int cursor = 0;

    for (char e : input_first) {
        insert_node(cursor, e);
        cursor = nxt[cursor];
    }
    
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        char input;
        cin >> input;

        if (input == 'L') {
            if (pre[cursor] != -1) cursor = pre[cursor];
        }
        else if (input == 'D') {
            if (nxt[cursor] != -1) cursor = nxt[cursor];
        }
        else if (input == 'B') {
            if (cursor == 0) continue;
            erase_node(cursor);
            cursor = pre[cursor];
        }
        else {
            char temp;
            cin >> temp;
            insert_node(cursor, temp);
            cursor = nxt[cursor];
        }
    }

    for (int i = nxt[0]; i > -1; i = nxt[i]) cout << dat[i];
    
}