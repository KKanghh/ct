#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> area;
    string time;
    cin >> time;

    string hour_str = time.substr(0, 2);
    string minute_str = time.substr(3, 2);
    int hour = 0, minute = 0, time_sum = 0;
    for (int i = 0; i < 2; i++) {
        hour = hour * 10 + hour_str[i] - '0';
        minute = minute * 10 + minute_str[i] - '0';
    }
    for (int i = 0; i < 6; i++) {
        int temp;
        cin >> temp;
        time_sum += temp;
        area.push_back(temp);
    }

    int L;
    cin >> L;
    while (L--) {
        float second;
        string input;
        
        cin >> second >> input;
        if (time_sum == 0) break;

        if (input == "^") {
            time_sum -= area[hour / 2];
            area[hour / 2] = 0;
        }
        else if (input == "10MIN") {
            hour += (minute + 10) / 60;
            hour %= 12;
            minute = (minute + 10) % 60;
        }
        else if (input == "30MIN") {
            hour += (minute + 30) / 60;
            hour %= 12;
            minute = (minute + 30) % 60;
        }
        else if (input == "50MIN") {
            hour += (minute + 50) / 60;
            hour %= 12;
            minute = (minute + 50) % 60;
        }
        else if (input == "2HOUR") {
            hour = (hour + 2) % 12;
        }
        else if (input == "4HOUR") {
            hour = (hour + 4) % 12;
        }
        else if (input == "9HOUR") {
            hour = (hour + 9) % 12;
        }
    }
    if (time_sum > 100) time_sum = 100;
    cout << time_sum;

}