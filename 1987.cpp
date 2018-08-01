#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[25][25];
int visit[100];
int ans = -1;
int R, C;

void move(int x, int y, int len)
{

	for(int k = 0; k < 4; k++) {
		if(x + dx[k] >= 0 && x + dx[k] < R && y + dy[k] >= 0 && y + dy[k] < C) {
			if(visit[board[x + dx[k]][y + dy[k]]] == 0) {
				visit[board[x + dx[k]][y + dy[k]]] = 1;
				move(x + dx[k], y + dy[k], len + 1);
				visit[board[x + dx[k]][y + dy[k]]] = 0;
			}
		}
	}


	if(len > ans) {
		ans = len;
	}
	return;
}

int main(void)
{
	scanf("%d %d",&R, &C);

	for(int i = 0; i < R; i++) {
		char temp[25];
		scanf("%s", temp);
		for(int j = 0; j < C; j++) {
			board[i][j] = temp[j];
		}
	}

	visit[board[0][0]] = 1;
	move(0, 0, 1);

	printf("%d", ans);

	return 0;
}
