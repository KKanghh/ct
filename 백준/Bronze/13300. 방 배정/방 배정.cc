#include <bits/stdc++.h>
using namespace std;

int student[2][6];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num, room_size;
    cin >> num >> room_size;
    int grade, sex, room_num = 0;
    
    for (int i = 0; i < num; i++) {
        cin >> sex >> grade;
        student[sex][grade - 1]++;
    }
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            if (!student[i][j]) continue;
            room_num += (student[i][j] - 1) / room_size + 1;
        }
    }
    
    cout << room_num;
}