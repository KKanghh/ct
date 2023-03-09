// #define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
// #include<cstdio>
using namespace std;
bool film[13][20];
int d, w, k;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	// freopen("sample_input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << '#' << test_case << ' ';
		cin >> d >> w >> k;
		bool ff = false;

		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> film[i][j];
			}
		}

		for (int i = 0; i <= d; i++) {
			vector<bool> C(d, true);
			fill(C.begin(), C.begin() + i, false);
			bool cp[13][20] = {};
			do {
				for (int x = 0; x < d; x++) {
					for (int y = 0; y < w; y++) {
						cp[x][y] = film[x][y];
					}
				}

				int poss = 1;
				for (int j = 0; j < i; j++) poss *= 2;
				for (int j = 0; j < poss; j++) {
					int temp = j;
					for (int a = 0; a < d; a++) {
						if (!C[a]) {
							if (temp % 2 == 0) {
								fill(cp[a], cp[a] + w, false);
							}
							else {
								fill(cp[a], cp[a] + w, true);
							}
							temp /= 2;
						}
					}
					
					int y = 0;
					for (; y < w; y++) {
						int cnt = 1;
						int x = 1;
						for (; x < d; x++) {
							if (cp[x][y] == cp[x - 1][y]) cnt++;
							else cnt = 1;
							if (cnt >= k) break;
						}
						if (x == d) break;
					}
					if (y == w) {
						cout << i << '\n';
						ff = true;
						break;
					}
				}
				if (ff) break;
			} while (next_permutation(C.begin(), C.end()));
			
			if (ff) break;
		}


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}