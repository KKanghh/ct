#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;
	while (num--) {
		deque<int> D;
		string func, arr;
		int size;
		cin >> func;
		cin >> size;
		cin >> arr;

		bool front = true, error = false;
		int i = 1;

		while (size--) {
			int input_num = 0;
			while (arr[i] != ',' && arr[i] != ']') {
				input_num *= 10;
				input_num += arr[i] - '0';
				i++;
			}
			if (i < arr.length() - 1) i++;
			D.push_back(input_num);
		}

		for (int j = 0; j < func.length(); j++) {
			if (func[j] == 'R') front = !front;
			else {
				if (D.empty()) {
					error = true;
					break;
				}
				else if (front) {
					D.pop_front();
				}
				else {
					D.pop_back();
				}
			}
		}

		if (error) {
			cout << "error" << '\n';
		}
		else {
			cout << '[';
			if (front) {
				while (!D.empty()) {
					cout << D.front();
					D.pop_front();
					if (!D.empty()) cout << ',';
				}
			}
			else {
				while (!D.empty()) {
					cout << D.back();
					D.pop_back();
					if (!D.empty()) cout << ',';
				}
			}
			cout << "]\n";
		}
	}
}