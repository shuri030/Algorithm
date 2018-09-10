#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;
int N, M;
int board[52][52];
int ans = 1;

int main()
{
	int mn;
	scanf("%d %d", &N, &M);
	mn = min(N, M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &board[i][j]);
		}
	}

	int flag = 0;
	for (int k = 1; k < mn; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (i + k <= N && j + k <= M) {
					int cmp = board[i][j];
					if (board[i][j + k] == cmp && board[i + k][j] == cmp && board[i + k][j + k] == cmp) {
						ans = (k + 1) * (k + 1);
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1) { flag = 0; break; }
		}
	}

	printf("%d", ans);
	return 0;
}
