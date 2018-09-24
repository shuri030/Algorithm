#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <queue>
using namespace std;

int board[105][105];
int visit[105][105];
int rx[4] = {1, -1, 0, 0};
int ry[4]= {0, 0, 1, -1};
int N, M;

int move(int x, int y)
{
	int xx, yy;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	while(!q.empty()) {
		xx = q.front().first;
		yy = q.front().second;
		q.pop();

		for(int k = 0; k < 4; k++) {
			if((xx + rx[k] >= 1) && (xx + rx[k] <= N) && (yy + ry[k] >= 1) && (yy + ry[k] <= M)) {
				if((visit[xx + rx[k]][yy + ry[k]] > visit[xx][yy] + 1) && (board[xx + rx[k]][yy + ry[k]] == 1)){
					visit[xx + rx[k]][yy + ry[k]] = visit[xx][yy] + 1;
					q.push(make_pair(xx + rx[k], yy + ry[k]));
				}
			}
		}
	}

	return visit[N][M];
}

int main()
{
	scanf("%d %d", &N, &M);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%1d", &board[i][j]); 
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			visit[i][j] = INT_MAX / 2;
		}
	}

	visit[1][1] = 1;
	printf("%d\n", move(1, 1));

}