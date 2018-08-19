#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

int board[101][101];
int visit[101][101];
int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isin(int x, int y)
{
	if(x < 1 || y < 1 || x > N || y > N) 
		return false;
	return true;
}
void DFS(int x, int y, int n) 
{
	int xx, yy;

	for(int k = 0; k < 4; k++) {
		xx = x + dx[k]; yy = y + dy[k];
		if(isin(xx, yy) && board[xx][yy] == 1 && visit[xx][yy] == 0) {
			visit[xx][yy] = 1;
			board[xx][yy] = n;
			DFS(xx, yy, n);
		}
	}
}
int main()
{
	scanf("%d", &N);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	//육지를 나누자
	int n = 0, t = 1;

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(board[i][j] == 1 && visit[i][j] == 0) {
				++n;
				visit[i][j] = 1;
				board[i][j] = n; 
				DFS(i, j, n);
			}
			
		}
	}

	queue<pair<int, int> > sea;

	int xx, yy, ans = INT_MAX;

	while(t <= n) {
		//visit배열 초기화
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				visit[i][j] = INT_MAX / 2;
			}
		}

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(board[i][j] == t) {
					//t번 육지 바로 옆 바다들을 체크하고 큐에 넣음
					for(int k = 0; k < 4; k++) {
						xx = i + dx[k]; yy = j + dy[k];
						if(isin(xx, yy) && board[xx][yy] == 0 && visit[xx][yy] == (INT_MAX / 2)) { 
							visit[xx][yy] = 1;
							sea.push(make_pair(xx, yy));
						}
					}	
				}
			}
		}

		int nextX, nextY, flag = 0;
		while(!sea.empty()) {
			nextX = sea.front().first; nextY = sea.front().second; sea.pop();

			for(int k = 0; k < 4; k++) {
				xx = nextX + dx[k]; yy = nextY + dy[k];

				if(isin(xx, yy) && board[xx][yy] == 0 && visit[xx][yy] > visit[nextX][nextY] + 1) { 
					visit[xx][yy] = visit[nextX][nextY] + 1;
					sea.push(make_pair(xx, yy));
				}

				else if(isin(xx, yy) && board[xx][yy] != t && board[xx][yy] != 0) { //다른 육지이면
					ans = min(ans, visit[nextX][nextY]); //다리 길이 저장하고 
					flag = 1;
					break;
				}
			}
			if(flag == 1) { break; }
		}

		t++;
		while(!sea.empty()) { sea.pop(); } //큐 비워
	}
	
	printf("%d\n", ans);
	return 0;
}