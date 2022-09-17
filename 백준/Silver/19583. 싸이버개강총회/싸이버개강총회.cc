#include <bits/stdc++.h>
using namespace std;

vector<int> split(string s) {
	istringstream iss(s);
	string buffer;

	vector<int> result;
	if (s.length() == 0) return result;
	while (getline(iss, buffer, ':')) {
		int tmp = 0;
		for (int i = 0; i < buffer.length(); i++) {
			tmp = tmp * 10 + buffer[i] - '0';
		}
		result.push_back(tmp);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<string> attend, com;
	int h = 0;
	int m = 0;

	int sh = 0, sm = 0, eh = 0, em = 0, qh = 0, qm = 0;
	string k;
	cin >> k;
	vector<int> t = split(k);
	sh = t[0];
	sm = t[1];
	cin >> k;
	t = split(k);
	eh = t[0];
	em = t[1];
	cin >> k;
	t = split(k);
	qh = t[0];
	qm = t[1];
	
	while(cin >> k && k.length() > 0) {
		t = split(k);
		int th = t[0];
		int tm = t[1];
		string name;
		cin >> name;
		if (th < sh || (th == sh && tm <= sm)) {
			attend.insert(name);
		}
		if (((th == eh && tm >= em) || th > eh) && (th < qh || (th == qh && tm <= qm)) && attend.count(name)) {
			com.insert(name);
		}
		
	}
	cout << com.size();

}