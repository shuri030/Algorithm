#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

int N, M;
int board[10][10];
int flag = 0;
vector<pair<int, int> > b; //빈 숫자만 넣기
int len;

bool check(int x, int y) //숫자가 들어가도 되는 지 판별함수
{
	for (int j = 1; j < 10; j++) {
		if (j == y) continue;
		if (board[x][j] == board[x][y])
			return false;
	}

	for (int i = 1; i < 10; i++) {
		if (i == x) continue;
		if (board[i][y] == board[x][y])
			return false;
	}
	int st_x, st_y;

	if (x >= 1 && x <= 3) { st_x = 1; }
	else if (x >= 4 && x <= 6) { st_x = 4; }
	else if (x >= 7 && x <= 9) { st_x = 7; }

	if (y >= 1 && y <= 3) { st_y = 1; }
	else if (y >= 4 && y <= 6) { st_y = 4; }
	else if (y >= 7 && y <= 9) { st_y = 7; }

	for (int i = st_x; i <= st_x + 2; i++) {
		for (int j = st_y; j <= st_y + 2; j++) {
			if (x == i && y == j) continue;
			if (board[x][y] == board[i][j])
				return false;
		}
	}

	return true;
}
void sdoku(int n)
{
	if (n >= len) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}

		flag = 1;
		return;
	}

	int x = b[n].first;
	int y = b[n].second;

	for (int i = 1; i <= 9; i++) {

		board[x][y] = i;

		if (check(x, y)) {

			sdoku(n + 1);
			if (flag == 1) {
				break;

			}
		}
		board[x][y] = 0;
	}


	if (flag == 1) {
		return;
	}
}

int main()
{

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {

			scanf("%d", &board[i][j]);

			if (board[i][j] == 0) {
				b.push_back({ i, j });
			}
		}
	}

	len = (int)b.size();

	sdoku(0);

	return 0;

}
