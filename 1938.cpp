#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N;
char board[55][55];
bool visit[52][52][2];
int ans = 1000000;
int ex, ey;
char e_dir;

struct Log {
	int lx, ly;
	int cnt;
	char past; //방금 회전했니
	char dir; //통나무 방향(가로, 세로)

}b_log;

queue<Log> q;

bool isin(int n)
{
	if((n >= 1) && (n <= N)) 
		return true;
	else
		return false;

}
int main()
{
	int l_flag = 0, e_flag = 0;

	scanf("%d", &N);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}

	//위치 정하기
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(board[i][j] == 'B') {
				if(l_flag == 0) { l_flag = i; }
				else if(l_flag != 0) {
					if(l_flag == i) { b_log.dir = 'w'; }
					else { b_log.dir = 'h'; }
					b_log.lx = i; b_log.ly = j; l_flag = 0; 
				}
			}
			else if(board[i][j] == 'E') {
				if(e_flag == 0) { e_flag = i; }
				else if(e_flag != 0) {
					if(e_flag == i) { e_dir = 'w'; }
					else { e_dir = 'h'; }
					ex = i; ey = j; e_flag = 0; 
				}
			}
		}
	}

	b_log.cnt = 0;
	b_log.past = 0;
	if(b_log.dir == 'h') { visit[b_log.lx][b_log.ly][0] = 1; }
	else { visit[b_log.lx][b_log.ly][1] = 1; }
	q.push(b_log);

	int x, y;

	while(!q.empty()) {

		Log log = q.front();
		x = log.lx;
		y = log.ly;
		q.pop();
		//printf("%d: %d %d %c\n", log.cnt, x, y, log.dir);
		//정답이니?
		if((x == ex) && (y == ey) && (log.dir == e_dir)) {
			ans = min(ans, log.cnt);
		}
		Log tmp = log;
		if(log.dir == 'h') {
			//상으로 갈수있는지 확인, 있으면 바꾼거 push
			if((isin(x - 2)) && (visit[x - 1][y][0] == 0) && (board[x - 2][y] != '1')) {
				tmp.lx -= 1;
				tmp.past = '0';
				tmp.cnt++;
				visit[tmp.lx][tmp.ly][0] = 1;
				q.push(tmp);
				tmp = log;
			}
			//하
			if((isin(x + 2)) && (visit[x + 1][y][0] == 0) && (board[x + 2][y] != '1')) {
				tmp.lx += 1;
				tmp.past = '0';
				tmp.cnt++;
				visit[tmp.lx][tmp.ly][0] = 1;
				q.push(tmp);
				tmp = log;
			}
			//좌
			if((isin(x - 1)) && (isin(x + 1)) && (isin(y - 1)) && (visit[x][y - 1][0] == 0)) {
				if((board[x - 1][y - 1] != '1') && (board[x][y - 1] != '1') && (board[x + 1][y - 1] != '1')) {
					tmp.ly -= 1;
					tmp.past = '0';
					tmp.cnt++;
					visit[tmp.lx][tmp.ly][0] = 1;
					q.push(tmp);
					tmp = log;
				}
			}
			//우
			if((isin(x - 1)) && (isin(x + 1)) && (isin(y + 1)) && (visit[x][y + 1][0] == 0)) {
				if((board[x - 1][y + 1] != '1') && (board[x][y + 1] != '1') && (board[x + 1][y + 1] != '1')) {
					tmp.past = '0';
					tmp.cnt++;
					tmp.ly += 1;
					visit[tmp.lx][tmp.ly][0] = 1;
					q.push(tmp);
					tmp = log;
				}
			}
			//회전
			if((isin(x - 1)) && (isin(x + 1)) && (isin(y + 1)) && (isin(y - 1)) && (log.past == '0')) {
				if((board[x - 1][y - 1] != '1') && (board[x][y - 1] != '1') && (board[x + 1][y - 1] != '1')) {
					if((board[x - 1][y + 1] != '1') && (board[x][y + 1] != '1') && (board[x + 1][y + 1] != '1')) {
						tmp.past = '1';
						tmp.cnt++;
						tmp.dir = 'w';
						visit[tmp.lx][tmp.ly][1] = 1;
						q.push(tmp);
					}
				}
			}
		} //h 끝
		else if(log.dir == 'w') {
			//상
			if((isin(y - 1)) && (isin(y + 1)) && (isin(x - 1)) && (visit[x - 1][y][1] == 0)) {
				if((board[x - 1][y - 1] != '1') && (board[x - 1][y] != '1') && (board[x - 1][y + 1] != '1')) {
					tmp.lx -= 1;
					tmp.past = '0';
					tmp.cnt++;
					visit[tmp.lx][tmp.ly][1] = 1;
					q.push(tmp);
					tmp = log;
				}
			}
			//하
			if((isin(y - 1)) && (isin(y + 1)) && (isin(x + 1)) && (visit[x + 1][y][1] == 0)) {
				if((board[x + 1][y - 1] != '1') && (board[x + 1][y] != '1') && (board[x + 1][y + 1] != '1')) {
					tmp.past = '0';
					tmp.cnt++;
					tmp.lx += 1;
					visit[tmp.lx][tmp.ly][1] = 1;
					q.push(tmp);
					tmp = log;
				}
			}
			//좌
			if((isin(y - 2)) && (visit[x][y - 1][1] == 0) && (board[x][y - 2] != '1')) {
				tmp.ly -= 1;
				tmp.past = '0';
				tmp.cnt++;
				visit[tmp.lx][tmp.ly][1] = 1;
				q.push(tmp);
				tmp = log;
			}
			//우
			if((isin(y + 2)) && (visit[x][y + 1][1] == 0) && (board[x][y + 2] != '1')) {
				tmp.ly += 1;
				tmp.past = '0';
				tmp.cnt++;
				visit[tmp.lx][tmp.ly][1] = 1;
				q.push(tmp);
				tmp = log;
			}
			//회전
			if((isin(y - 1)) && (isin(y + 1)) && (isin(x + 1)) && (isin(x - 1)) && (log.past == '0')) {
				if((board[x - 1][y - 1] != '1') && (board[x - 1][y] != '1') && (board[x - 1][y + 1] != '1')) {
					if((board[x + 1][y - 1] != '1') && (board[x + 1][y] != '1') && (board[x + 1][y + 1] != '1')) {
						tmp.past = '1';
						tmp.cnt++;
						tmp.dir = 'h';
						visit[tmp.lx][tmp.ly][0] = 1;
						q.push(tmp);
					}
				}
			}
		}
	}
	if(ans == 1000000) {
		printf("0\n");
	}
	else {
		printf("%d\n", ans);
	}
	
}
