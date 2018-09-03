#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int hx, hy, tx, ty;
int s_dir, s_len;
int board[103][103];
int visit[103][103];
int N;
int dx[4] = {0, 1, 0, -1}; //오른쪽으로 돌수록 우, 하, 좌, 상
int dy[4] = {1, 0, -1, 0};
queue<pair<int, char> > l;
int t = 1;

int set_dir(int c)
{
	if (s_dir == 0) { //우
		if (c == 'L') {
			return 3;
		}
		else if (c == 'D') {
			return 1;
		}
	}
	else if (s_dir == 1) { //하
		if (c == 'L') {
			return 0;
		}
		else if (c == 'D') {
			return 2;
		}
	}
	else if (s_dir == 2) { //좌
		if (c == 'L') {
			return 1;
		}
		else if (c == 'D') {
			return 3;
		}
	}
	else if (s_dir == 3) {
		if (c == 'L') {
			return 2;
		}
		else if (c == 'D') {
			return 0;
		}
	}
}
int is_next(int x, int y) //이동 하려는 곳이
{
	if (x < 1 || y < 1 || x > N || y > N || board[x][y] == 2) //벽에 부딪히거나 뱀이면
		return 0;

	if (board[x][y] == 1) { //사과면
		return 1;
	}
	else { //빈칸이면
		return 2;
	}

}
int move()
{
	int next_x = hx + dx[s_dir];
	int next_y = hy + dy[s_dir];

	int check = is_next(next_x, next_y);
	visit[hx][hy] = s_dir;

	//벽에 부딪히거나 뱀의 몸이면
	if (check == 0) {
		return -1; //종료
	}
	else if (check == 1) { //사과면
		s_len++;
		board[next_x][next_y] = 2;

		hx = next_x;
		hy = next_y;
	}
	else if (check == 2) {
		s_len++;
		board[next_x][next_y] = 2;

		hx = next_x;
		hy = next_y;

		s_len--;
		board[tx][ty] = 0;
		int p_dir = visit[tx][ty];
		tx = tx + dx[p_dir];
		ty = ty + dy[p_dir];

	}

	return 1;
}
int main()
{
	int K, L, x, y;
	char c;
	int cur_sec = 0;

	scanf("%d", &N);
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d %d", &x, &y);
		board[x][y] = 1; //사과
	}

	board[1][1] = 2; //뱀
	visit[1][1] = 0;
	hx = tx = 1;
	hy = ty = 1;
	s_dir = 0;
	s_len = 1;

	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &x, &c);
		l.push({ x, c });
	}

	int i = 0;

	while (1) {
		if (!l.empty()) {
			x = l.front().first;
			c = l.front().second;
		}

		int m = move();
		if (m == -1) {
			printf("%d", t);
			return 0;
		}

		if (t == x) {
			s_dir = set_dir(c); //방향 설정
			l.pop();
		}
		t++;
	}

	return 0;
}
