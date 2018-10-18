#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
int board[10][10];
int ans = 98765432;
vector<pair<int, int> > cctv;
int cctv_cnt;
int ans_flag = 0;

void observe(int(*t)[10], int x, int y, int dx, int dy)
{
	int nx = x + dx;
	int ny = y + dy;

	while (1) {

		if (nx < 1 || ny < 1 || nx > N || ny > M || t[nx][ny] == 6) {
			break;
		}
		if (t[nx][ny] == 0) { // 비어있으면 보인다고 표시
			t[nx][ny] = -1;
		}

		nx += dx; ny += dy;
	}

}
void find_min(int (*area)[10], int c)
{
	if (c >= cctv_cnt) {

		//사각지대
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (area[i][j] == 0) {
					cnt++;
				}
			}
		}

		if (cnt == 0) {
			ans_flag = 1;
			ans = 0;
		}
		if (ans > cnt) {
			ans = cnt;
		}
		return;

	}

	int x = cctv[c].first;
	int y = cctv[c].second;
	int cctv_num = board[x][y];
	int tmp[10][10] = { 0, };

	//copy
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tmp[i][j] = area[i][j];
		}
	}

	if (cctv_num == 1) {

		int dx[4] = { -1, 1, 0, 0 };
		int dy[4] = { 0, 0, -1, 1 };

		for (int k = 0; k < 4; k++) {
			observe(tmp, x, y, dx[k], dy[k]);

			//넘겨 다음 씨씨티비
			find_min(tmp, c + 1);
			if (ans_flag == 1) { return;  }

			//리턴했을때 tmp넘긴거 다시 area로
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					tmp[i][j] = area[i][j];
				}
			}
		}

	}
	else if (cctv_num == 2) {

		int dx[4] = { -1, 1, 0, 0 };
		int dy[4] = { 0, 0, -1, 1 };

		//가로
		for (int k = 0; k <= 1; k++) {
			observe(tmp, x, y, dx[k], dy[k]);
		}

		//넘겨 다음 씨씨티비
		find_min(tmp, c + 1);
		if (ans_flag == 1) { return; }

		//리턴했을때 tmp넘긴거 다시 area로
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				tmp[i][j] = area[i][j];
			}
		}

		//세로
		for (int k = 2; k <= 3; k++) {
			observe(tmp, x, y, dx[k], dy[k]);
		}
		//넘겨 다음 씨씨티비
		find_min(tmp, c + 1);
		if (ans_flag == 1) { return; }

	}
	else if (cctv_num == 3) {
		int dx[4] = { -1, 0, 1, 0 };
		int dy[4] = { 0, 1, 0, -1 };

		for (int k = 0; k < 4; k++) {
			if (k == 3) {
				//0, 3
				observe(tmp, x, y, dx[k], dy[k]);
				observe(tmp, x, y, dx[0], dy[0]);
			}
			else {
				// 자기 + 1
				observe(tmp, x, y, dx[k], dy[k]);
				observe(tmp, x, y, dx[k + 1], dy[k + 1]);
			}
			//넘겨 다음 씨씨티비
			find_min(tmp, c + 1);
			if (ans_flag == 1) { return; }

			//리턴했을때 tmp넘긴거 다시 area로
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					tmp[i][j] = area[i][j];
				}
			}
		}

	}
	else if (cctv_num == 4) {
		int dx[13] = { -1, 0, 1, 0, 1, 0 , 1, 0, -1, 0, -1, 0};
		int dy[13] = { 0, 1, 0, 1, 0, -1, 0, -1, 0, -1, 0, 1};

		int k = 0;
		while (k < 12) {

			for (int i = k; i <= k + 2; i++) {
				observe(tmp, x, y, dx[i], dy[i]);
			}

			//넘겨 다음 씨씨티비
			find_min(tmp, c + 1);
			if (ans_flag == 1) { return; }

			//리턴했을때 tmp넘긴거 다시 area로
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					tmp[i][j] = area[i][j];
				}
			}

			k += 3;
		}

	}
	else if (cctv_num == 5) {
		int dx[4] = { -1, 0, 1, 0 };
		int dy[4] = { 0, 1, 0, -1 };

		for (int k = 0; k < 4; k++) {
			//회전하구 tmp에 표현
			observe(tmp, x, y, dx[k], dy[k]);

		}

		//넘겨 다음 씨씨티비
		find_min(tmp, c + 1);
		if (ans_flag == 1) { return; }
	}


	return;
}

int main()
{
	scanf("%d %d", &N, &M);

	//input
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] >= 1 && board[i][j] <= 5) {
				cctv.push_back({ i, j });
				cctv_cnt++;
			}
		}
	}

	int tmp[10][10] = { 0, };

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tmp[i][j] = board[i][j];
		}
	}


	find_min(tmp, 0);

	printf("%d", ans);

	return 0;

}
