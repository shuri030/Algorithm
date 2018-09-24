#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int R, C;
char board[253][253];
int visit[253][253];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int sheep, wolf;

void bfs(int x, int y)
{
	int s = 0, w = 0, xx, yy;

	if(board[x][y] == 'k') {
		s++;
	}
	else if(board[x][y] == 'v') {
		w++;
	}
	
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	while(!q.empty()) {
		xx = q.front().first; yy = q.front().second;
		q.pop();

		for(int k = 0; k < 4; k++) {
			if((xx + dx[k] >= 1) && (xx + dx[k] <= R) && (yy + dy[k] >= 1) && (yy + dy[k] <= C)) {
				if(visit[xx + dx[k]][yy + dy[k]] == 0 && board[xx + dx[k]][yy + dy[k]] != '#') {
					if(board[xx + dx[k]][yy + dy[k]] == 'k') {
						s++;
					}
					else if(board[xx + dx[k]][yy + dy[k]] == 'v') {
						w++;
					}
					visit[xx + dx[k]][yy + dy[k]] = 1;
					q.push(make_pair(xx + dx[k], yy + dy[k]));
				}
			}
		}
	}
	if(s > w) {
		sheep += s;
	}
	else if(s <= w) {
		wolf += w;
	}
}

int main()
{
	scanf("%d %d", &R, &C);
	
	for(int i = 1; i <= R; i++) {
		for(int j = 1; j <= C; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}
	for(int i = 1; i <= R; i++) {
		for(int j = 1; j <= C; j++) {
			if((board[i][j] != '#') && (visit[i][j] == 0)) {
				visit[i][j] = 1;
				bfs(i, j);
			}
		}
	}

	printf("%d %d\n", sheep, wolf);
    return 0;
}