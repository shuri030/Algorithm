#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n;
int board[110][110];
int visit[110][110];
int check[110][110];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int xx, yy;
int ans = 1000;

void seperate(int i, int j, int s) 
{

	visit[i][j] = 1;
	board[i][j] = s;

	for(int k = 0; k < 4; k++) {
		int x = i + dx[k];
		int y = j + dy[k];
		if(x >= 0 && x < n && y >= 0 && y < n) {
			if(board[x][y] == 1 && visit[x][y] == 0) {
				seperate(x, y, s);
			}
		}
	}
}

void connect(int i, int j, int land) 
{
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int k = 0; k < 4; k++) {
			xx = x + dx[k];
			yy = y + dy[k];
			if(xx >= 0 && xx < n && yy >= 0 && yy < n) {
				if(board[xx][yy] != land && board[xx][yy] != 0) {
					if(visit[x][y] < ans) {
						ans = visit[x][y];
					}
				}
				else if(board[xx][yy] == 0 && visit[xx][yy] == 0) {
					visit[xx][yy] = visit[x][y] + 1;
					q.push(make_pair(xx, yy));
				}
				
			}
		}

	}
}

int main()
{
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	int s = 1;
	//육지 분리
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] == 1 && visit[i][j] == 0) {
				seperate(i, j, s);
				s = s + 1;
			}
		}
	}
	/*//출력해보기
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", board[i][j]);
		}
		cout << endl;
	}
	cout << endl;*/
	memset(visit, 0, sizeof(visit));
	//바다 중 옆에 육지 있으면 다른 육지로의 최단거리
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] == 0) {
				for(int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if(x >= 0 && x < n && y >= 0 && y < n) {
						if(board[x][y] != 0 && check[i][j] == 0) {
							check[i][j] = 1;
							visit[i][j] = 1;
							connect(i, j, board[x][y]);
						}
					}
					
				}
			}
			memset(visit, 0, sizeof(visit));
		}
	}
	

	printf("%d\n", ans);

	return 0; 
}