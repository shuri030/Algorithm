#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm> 
#include <limits.h>

using namespace std;

int n, m, k;

int board[55][55];
int visit[55][55];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y) {

	visit[x][y] = 1;
	

	for(int d = 0; d < 4; d++) {
		if(x + dx[d] >= 0 && y + dy[d] >= 0 && x + dx[d] < n && y + dy[d] < m) {
			if(visit[x + dx[d]][y + dy[d]] == 0 && board[x + dx[d]][y + dy[d]] == 1) {
				DFS(x + dx[d], y + dy[d]);
			}
		}
	}

}

int main() 
{
	int T;
	int x, y;

	scanf("%d", &T);

	for(int i = 0; i < T; i++) {

		scanf("%d %d %d", &m, &n, &k);

		//배추 밭
		for(int j = 0; j < k; j++) {
			scanf("%d %d", &x, &y);
			board[y][x] = 1;
		}

		int cnt = 0;

		for(int j = 0; j < n; j++) {
			for(int d = 0; d < m; d++) {
				if(visit[j][d] == 0 && board[j][d] == 1) {
					DFS(j, d);
					cnt++;
				}
			}
		}
	
		cout << cnt << endl;

		memset(visit, 0, sizeof(visit));
		memset(board, 0, sizeof(board));
	}

}
