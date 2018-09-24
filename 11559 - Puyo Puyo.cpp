#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

char board[13][7];
int visit[13][7];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bomb(int x, int y)
{
	queue<pair<int, int> > q; //뿌요 탐색 큐
	queue<pair<int, int> > popp; //터질 뿌요 담는 큐
	int xx, yy;
	q.push(make_pair(x, y));
	popp.push(make_pair(x, y));

	while(!q.empty()) {
		xx = q.front().first; yy = q.front().second;
		q.pop();

		for(int k = 0; k < 4; k++) {
			if((xx + dx[k] >= 1) && (xx + dx[k] <= 12) && (yy + dy[k] >= 1) && (yy + dy[k] <= 6)) {
				if((board[xx + dx[k]][yy + dy[k]] == board[xx][yy]) && (visit[xx + dx[k]][yy + dy[k]] == 0)) {
					visit[xx + dx[k]][yy + dy[k]] = 1;
					q.push(make_pair(xx + dx[k], yy + dy[k]));
					popp.push(make_pair(xx + dx[k], yy + dy[k]));
				}
			}
		}
	}

	//4 이상이면 터진다
	if(popp.size() >= 4) {
		while(!popp.empty()) {
			xx = popp.front().first; yy = popp.front().second;
			popp.pop();
			board[xx][yy] = '.';
		}
		return 1;
	}
	else {
		while(!popp.empty()) { popp.pop(); }
		return 0;
	}

}
void move_down(int x, int y)
{
	int xx = x;
	while(1) {
		if(x < 1) { break; }
		if(board[x][y] == '.') {
			xx = x - 1;
			while(board[xx][y] == '.') {
				xx--;
				if(xx < 1) { break; }
			}
			if(xx >= 1) {
				board[x][y] = board[xx][y];
				board[xx][y] = '.';
			}
		}
		x--;
	}
}

int main()
{	
	int flag = 0, n = 0;

	for(int i = 1; i <= 12; i++) {
		for(int j = 1; j <= 6; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}

	while(1) {
		//터지는 뿌요 확인
		for(int i = 12; i >= 1; i--) {
			for(int j = 1; j <= 6; j++) {
				if((board[i][j] != '.') && (visit[i][j] == 0)) {
					visit[i][j] = 1;
					flag += bomb(i, j);
				}
			}
		}

		if(flag == 0) {
			break;
		}

		//중력
		for(int j = 1; j <= 6; j++) {
			move_down(12, j);
		}
		memset(visit, 0, sizeof(visit));
		
		flag = 0;
		n++;
	}
	
	printf("%d", n);
	
    return 0;
}