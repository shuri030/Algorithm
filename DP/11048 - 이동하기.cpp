#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int board[1002][1002];
int dp[1002][1002];
/*
점화식
dp[i][j] = 이 위치에서 가질 수 있는 사탕의 최대 개수
*/


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	dp[1][1] = board[1][1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) continue;
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + board[i][j];
		}
	}

	printf("%d", dp[n][m]);

	return 0;
}
