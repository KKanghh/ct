#include <bits/stdc++.h>
using namespace std;
stack<string> operand, operato;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		string t = "";
		if (s[i] >= 'A' && s[i] <= 'Z') {
			t += s[i];
			operand.push(t);
		}
		else {
			if (s[i] == '+' || s[i] == '-') {
				while (!operato.empty() && operato.top() != "(") {
					string a = "";
					a = operato.top() + a;
					operato.pop();
					a = operand.top() + a;
					operand.pop();
					a = operand.top() + a;
					operand.pop();
					operand.push(a);
				}
				t += s[i];
				operato.push(t);
			}
			else if (s[i] == '*' || s[i] == '/') {
				while (!operato.empty() && operato.top() != "(" && operato.top() != "+" && operato.top() != "-") {
					string a = "";
					a = operato.top() + a;
					operato.pop();
					a = operand.top() + a;
					operand.pop();
					a = operand.top() + a;
					operand.pop();
					operand.push(a);
				}
				t += s[i];
				operato.push(t);
			}
			else if (s[i] == '(') {
				operato.push("(");
			}
			else {
				while (operato.top() != "(") {
					string a = "";
					a = operato.top() + a;
					operato.pop();
					a = operand.top() + a;
					operand.pop();
					a = operand.top() + a;
					operand.pop();
					operand.push(a);
				}
				operato.pop();
			}

		}
	}
	while (!operato.empty()) {
		string a = "";
		a = operato.top() + a;
		operato.pop();
		a = operand.top() + a;
		operand.pop();
		a = operand.top() + a;
		operand.pop();
		operand.push(a);
	}
	cout << operand.top();
}