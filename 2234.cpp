#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int board[53][53][4]; //0:남 1:동 2:북 3:서 - 0:벽x 1:벽o
int visit[53][53]; //방 크기를 알 수 있고 번호를 알 수 있는 배열
int room_size[2500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

void set_wall(int x, int y, int N)
{
	int d = 3;

	while(d >= 0) {
		board[x][y][d] = N % 2;
		N /= 2;
		d--;
	}

}
bool isin(int x, int y) 
{
	if(x >= 1 && x <= m && y >= 1 && y <= n) { return true; }
	else { return false; }
}
int move(int x, int y, int rc)
{
	int xx, yy, cnt = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	while(!q.empty()) {
		xx = q.front().first; yy = q.front().second;
		q.pop();

		for(int k = 0; k < 4; k++) {
			if(board[xx][yy][k] == 0) {
				if((visit[xx + dx[k]][yy + dy[k]] == 0) && (isin(xx + dx[k], yy + dy[k]))) {
					cnt++;
					visit[xx + dx[k]][yy + dy[k]] = rc;
					q.push(make_pair(xx + dx[k], yy + dy[k]));
				}
			}
		}
	}

	return cnt;
}
int get_max_room(int x, int y)
{
	int xx, yy, ans = 0, sum = 0;
	for(int k = 0; k < 4; k++) {
		xx = x + dx[k]; yy = y + dy[k];
		if((isin(xx, yy)) && (visit[x][y] != visit[xx][yy])) {
			sum = room_size[visit[x][y]] + room_size[visit[xx][yy]];
			if(ans < sum) { ans = sum; }
		}
	}
	return ans;
}
int main()
{	
	int num, room_cnt = 1;
	int ans1 = 0, ans2 = 0, ans3 = 0;

	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &num);
			set_wall(i, j, num);
		}
	}
	
	//ans1, ans2 구하기
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(visit[i][j] == 0) {
				visit[i][j] = room_cnt;
				room_size[room_cnt] = move(i, j, room_cnt);
				if(ans2 < room_size[room_cnt]) { ans2 = room_size[room_cnt]; }
				room_cnt++;
			}
		}
	}
	ans1 = room_cnt - 1;

	//ans3 구하기
	int tmp;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			tmp = get_max_room(i, j);
			if(ans3 < tmp) {
				ans3 = tmp;
			}
		}
	}

	printf("%d\n%d\n%d\n", ans1, ans2, ans3);
    return 0;
}