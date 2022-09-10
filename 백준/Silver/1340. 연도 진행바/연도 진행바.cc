#include <bits/stdc++.h>
using namespace std;

int day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isyun(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	double p, hp;
	string m, t, dwc;
	int y, h = 0, mn, fullday, d = 0, minute = 0, l = 0;
	cin >> m >> dwc >> y >> t;

	if (m == "January") mn = 1;
	else if (m == "February") mn = 2;
	else if (m == "March") mn = 3;
	else if (m == "April") mn = 4;
	else if (m == "May") mn = 5;
	else if (m == "June") mn = 6;
	else if (m == "July") mn = 7;
	else if (m == "August") mn = 8;
	else if (m == "September") mn = 9;
	else if (m == "October") mn = 10;
	else if (m == "November") mn = 11;
	else mn = 12;

	for (int i = 0; i < mn; i++) {
		l += day[i];
		if (i == 2 && isyun(y)) l++;
	}
	
	if (isyun(y)) {
		fullday = 366;
	}
	else fullday = 365;

	for (int i = 0; i < dwc.length() - 1; i++) {
		d = d * 10 + (dwc[i] - '0');
		
	}

	l += d - 1;
	p = l;
	p /= fullday;

	for (int i = 0; i < 2; i++) {
		h = h * 10 + (t[i] - '0');
	}

	for (int i = 3; i < 5; i++) {
		minute = minute * 10 + (t[i] - '0');
	}

	hp = h * 60 + minute;
	hp /= 1440;
	hp /= fullday;
	printf("%.12f", (p + hp) * 100);// << (p + hp) * 100;
}