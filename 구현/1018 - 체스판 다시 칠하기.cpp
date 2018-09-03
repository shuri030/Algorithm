#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
char board[51][51];
int ans = 12345678;
char white_ans[8] = { 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' };
char black_ans[8] = { 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' };

int white_cnt(int x, int y)
{
	int k = 0, cnt = 0;

	for (int i = x; i <= x + 7; i += 2) {
		for (int j = y; j <= y + 7; j++) {
			if (board[i][j] != white_ans[k]) {
				cnt++;
			}
			k++;
		}
		k = 0;
	}

	for (int i = x + 1; i <= x + 7; i += 2) {
		for (int j = y; j <= y + 7; j++) {
			if (board[i][j] != black_ans[k]) {
				cnt++;
			}
			k++;
		}
		k = 0;
	}
	return cnt;
}
int black_cnt(int x, int y)
{
	int k = 0, cnt = 0;

	for (int i = x; i <= x + 7; i+=2) {
		for (int j = y; j <= y + 7; j++) {
			if (board[i][j] != black_ans[k]) {
				cnt++;
			}
			k++;
		}
		k = 0;
	}


	for (int i = x + 1; i <= x + 7; i += 2) {
		for (int j = y; j <= y + 7; j++) {
			if (board[i][j] != white_ans[k]) {
				cnt++;
			}
			k++;
		}
		k = 0;
	}

	return cnt;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int b = black_cnt(i, j);
			int w = white_cnt(i, j);

			ans = min(ans, min(b, w));
		}
	}

	printf("%d", ans);
	return 0;
}
