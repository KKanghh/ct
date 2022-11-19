#include <bits/stdc++.h>
using namespace std;
map<string, int> city;
vector <int> togo;

double No[100][100], Yes[100][100];
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r;
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		if (city.count(name)) {
			i--;
			n--;
			continue;
		}
		city[name] = i;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		togo.push_back(city[name]);
	}

	for (int i = 0; i < n; i++) {
		fill(No[i], No[i] + n, INF);
		fill(Yes[i], Yes[i] + n, INF);
		No[i][i] = 0;
		Yes[i][i] = 0;
	}

	int k;
	cin >> k;
	while (k--) {
		string type, src, dest;
		double price, naeilprice;
		cin >> type >> src >> dest >> price;
		if (type == "ITX-Saemaeul" || type == "ITX-Cheongchun" || type == "Mugunghwa") naeilprice = 0;
		else if (type == "V-Train" || type == "S-Train") naeilprice = price / 2;
		else naeilprice = price;
		if (price < No[city[src]][city[dest]]) {
			No[city[src]][city[dest]] = price;
			No[city[dest]][city[src]] = price;
		}
		if (naeilprice < Yes[city[src]][city[dest]]) {
			Yes[city[src]][city[dest]] = naeilprice;
			Yes[city[dest]][city[src]] = naeilprice;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (No[i][j] > No[i][k] + No[k][j]) No[i][j] = No[i][k] + No[k][j];
				if (Yes[i][j] > Yes[i][k] + Yes[k][j]) Yes[i][j] = Yes[i][k] + Yes[k][j];
			}
		}
	}
	
	int t = 0;
	double nocost = 0, yescost = r;
	for (int i = 1; i < m; i++) {
		nocost += No[togo[t]][togo[i]];
		yescost += Yes[togo[t]][togo[i]];
		t = i;
	}

	if (nocost <= yescost) cout << "No";
	else cout << "Yes";
}