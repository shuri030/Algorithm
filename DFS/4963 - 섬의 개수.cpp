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

int board[52][52];
int visit[52][52];
int w, h;
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1, };

void walk(int x, int y)
{
	for (int k = 0; k < 8; k++) {
		if (visit[x + dx[k]][y + dy[k]] == 0 && board[x + dx[k]][y + dy[k]] == 1) {
			visit[x + dx[k]][y + dy[k]] = 1;
			walk(x + dx[k], y + dy[k]);
		}
	}
}

int main()
{
	int ans = 0;
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) { break;  }

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &board[i][j]);
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == 1 && visit[i][j] == 0) {
					visit[i][j] = 1;
					walk(i, j);
					ans++;
				}
			}
		}

		printf("%d\n", ans);
		memset(visit, 0, sizeof(visit));
		memset(board, 0, sizeof(board));
		ans = 0;
	}


	return 0;
}
