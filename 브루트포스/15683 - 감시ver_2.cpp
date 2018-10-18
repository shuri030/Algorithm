#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

int board[10][10];
int visit[10][10];
int see[10][10];
int ans;
int N, M;
int cnt = 0;
int mina = INT_MAX / 2;


void see_up(int x, int y)
{

	if((board[x - 1][y] >= 0) && (board[x - 1][y] != 6)) {
		if((x - 1 >= 1) && (y >= 1) && (x - 1 <= N) && (y <= M)) {
			if(board[x - 1][y] == 0) {
				see[x - 1][y] += 1;
			}
			see_up(x - 1, y);
		}
	}
}
void see_down(int x, int y)
{
	if((board[x + 1][y] >= 0) && (board[x + 1][y] != 6)) {
		if((x + 1 >= 1) && (y >= 1) && (x + 1 <= N) && (y <= M)) {
			if(board[x + 1][y] == 0) {
				see[x + 1][y] += 1;
			}
			see_down(x + 1, y);
		}
	}
}
void see_right(int x, int y)
{

	if((board[x][y + 1] >= 0) && (board[x][y + 1] != 6)) {
		if((x >= 1) && (y + 1 >= 1) && (x <= N) && (y + 1 <= M)) {
			if(board[x][y + 1] == 0) {
				see[x][y + 1] += 1;
			}
			see_right(x, y + 1);
		}
	}
}
void see_left(int x, int y)
{
	if((board[x][y - 1] >= 0) && (board[x][y - 1] != 6)) {
		if((x >= 1) && (y - 1 >= 1) && (x <= N) && (y - 1 <= M)) {
			if(board[x][y - 1] == 0) {
				see[x][y - 1] += 1;
			}
			see_left(x, y - 1);
		}
	}
}
void return_up(int x, int y) {

	if(see[x - 1][y] >= 1) {
		if((x - 1 >= 1) && (y >= 1) && (x - 1 <= N) && (y <= M)) {
			if(board[x - 1][y] == 0) {
				see[x - 1][y] -= 1;
			}
			return_up(x - 1, y);
		}
	}
}
void return_down(int x, int y) {

	if(see[x + 1][y] >= 1) {
		if((x + 1 >= 1) && (y >= 1) && (x + 1 <= N) && (y <= M)) {
			if(board[x + 1][y] == 0) {
				see[x + 1][y] -= 1;
			}
			return_down(x + 1, y);
		}
	}
}
void return_right(int x, int y) {

	if(see[x][y + 1] >= 1) {
		if((x >= 1) && (y + 1>= 1) && (x <= N) && (y + 1 <= M)) {
			if(board[x][y + 1] == 0) {
				see[x][y + 1] -= 1;
			}
			return_right(x, y + 1);
		}
	}
}
void return_left(int x, int y) {

	if(see[x][y - 1] >= 1) {
		if((x >= 1) && (y - 1>= 1) && (x <= N) && (y - 1 <= M)) {
			if(board[x][y - 1] == 0) {
				see[x][y - 1] -= 1;
			}
			return_left(x, y - 1);
		}
	}
}
int count(int c)
{
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(see[i][j] == 0) {
				c++;
			}
		}
	}

	return c;
}

void cal(int nu)
{
	if(nu > cnt) {
		ans = count(0);
	/*	printf("ans = %d\n", ans);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				printf("%3d", see[i][j]);
			}
			cout << endl;
		}
		cout << endl;*/


		if(mina > ans) {
			mina = ans;
		}
		return;
	}


	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if((board[i][j] != 6) && (board[i][j] != 0)) {
				if((board[i][j] == 1) && (visit[i][j] == 0)) {
					visit[i][j] = 1;
					see_up(i, j);
					cal(nu + 1);
					return_up(i, j);

					see_down(i, j);
					cal(nu + 1);
					return_down(i, j);

					see_right(i, j);
					cal(nu + 1);
					return_right(i, j);

					see_left(i, j);
					cal(nu + 1);
					return_left(i, j);

					visit[i][j] = 0;
					return;
				}
				else if((board[i][j] == 2) && (visit[i][j] == 0)) {
					visit[i][j] = 1;
					see_right(i, j);
					see_left(i, j);

					cal(nu + 1);
					return_right(i, j);
					return_left(i, j);


					see_up(i, j);
					see_down(i, j);
					cal(nu + 1);
					return_up(i, j);
					return_down(i, j);

					visit[i][j] = 0;
					return;
				}
				else if((board[i][j] == 3) && (visit[i][j] == 0)) {
					visit[i][j] = 1;
					see_up(i, j);
					see_left(i, j);
					cal(nu + 1);
					return_left(i, j);

					see_right(i, j);
					cal(nu + 1);
					return_up(i, j);

					see_down(i, j);
					cal(nu + 1);
					return_right(i, j);

					see_left(i, j);
					cal(nu + 1);

					return_down(i, j);
					return_left(i, j);

					visit[i][j] = 0;
					return;
				}
				else if((board[i][j] == 4) && (visit[i][j] == 0)) {
					visit[i][j] = 1;
					see_up(i, j);
					see_left(i, j);
					see_right(i, j);
					cal(nu + 1);

					return_left(i, j);
					see_down(i, j);
					cal(nu + 1);

					return_up(i, j);
					see_left(i, j);
					cal(nu + 1);

					return_right(i, j);
					see_up(i, j);
					cal(nu + 1);

					return_up(i, j);
					return_down(i, j);
					return_left(i, j);

					visit[i][j] = 0;
					return;
				}
				else if((board[i][j] == 5) && (visit[i][j] == 0)) {
					visit[i][j] = 1;
					see_up(i, j);
					see_right(i, j);
					see_left(i, j);
					see_down(i, j);

					cal(nu + 1);

					return_up(i, j);
					return_down(i, j);
					return_left(i, j);
					return_right(i, j);

					visit[i][j] = 0;
					return;
				}


			}
		}
	}
	return;
}
int main()
{
	scanf("%d %d", &N, &M);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%d", &board[i][j]);
			if((board[i][j] != 6) && (board[i][j] != 0)) {
				see[i][j] = 1;
				cnt++;
			}
			else if(board[i][j] == 6) {
				see[i][j] = -1;
			}
		}
	}

	cal(1);
	printf("%d", mina);



	return 0;
}
