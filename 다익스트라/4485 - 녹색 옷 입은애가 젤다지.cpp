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

int N;
typedef pair<int, pair<int, int> >  P;
int board[127][127];
int ans[127][127];
int visit[127][127];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct sorting {
	int operator() (P a, P b) {
		return a.second.second > b.second.second;
	}

};

int dijkstra(int tx, int ty)
{
	priority_queue<P, vector<P>, sorting> pq;
	int xx;
	int yy;
	ans[0][0] = board[0][0];
	pq.push({ tx, {ty, board[tx][ty] } });

	while (!pq.empty()) {
		int x = pq.top().first;
		int y = pq.top().second.first;
		int cost = pq.top().second.second;
		pq.pop();
		//printf("%d %d %d\n", x, y, cost);
		if (x == N - 1 && y == N - 1) { break; }
		if (visit[x][y] == 1) { continue; }
		visit[x][y] = 1;

		for (int k = 0; k < 4; k++) {
			xx = x + dx[k]; yy = y + dy[k];
			if (xx >= 0 && yy >= 0 && xx < N && yy < N) {
				if ((ans[xx][yy] > ans[x][y] + board[xx][yy]) && visit[xx][yy] == 0) {

					ans[xx][yy] = ans[x][y] + board[xx][yy];
					pq.push({ xx, { yy, ans[xx][yy]} });
				}
			}
		}

	}

	return ans[N - 1][N - 1];
}
void init()
{
	for (int i = 0; i < 127; i++) {
		for (int j = 0; j < 127; j++) {
			ans[i][j] = INT_MAX / 2;
			visit[i][j] = 0;
			board[i][j] = 0;
		}
	}

}

int main()
{
	int num = 1;

	while (1) {
		scanf("%d", &N);
		if (N == 0) {
			break;
		}

		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &board[i][j]);
			}
		}


		printf("Problem %d: %d\n", num, dijkstra(0, 0));

		num++;
	}
	return 0;
}
