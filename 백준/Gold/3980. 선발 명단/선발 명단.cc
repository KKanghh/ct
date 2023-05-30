#include <bits/stdc++.h>

using namespace std;

const int MAX = 12;
int status[MAX][MAX], ans = 0;
bool visited[MAX];

void func(int cnt, int sum)
{
	if (cnt == MAX)
		ans = max(ans, sum);
	
	for (int i = 1; i < MAX; i++)
	{
		if (!visited[i] && status[cnt][i])
		{
			visited[i] = true;
			sum += status[cnt][i];
			func(cnt + 1, sum);
			sum -= status[cnt][i];
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		for (int i = 1; i <= 11; i++)
			for (int j = 1; j <= 11; j++)
				cin >> status[i][j];

		func(1, 0);
		cout << ans << '\n';
		ans = 0;
	}

	return 0;
}