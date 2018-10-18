#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int N, M;
int board[53][53];
vector<pair<int, int> > chick_home; //치킨집 좌표
vector<pair<int, int> > home; //집 좌표
int chick_dis[101]; //각 집의 치킨거리
int check[15];
int ch_cnt, h_cnt;
int ans = INT_MAX / 2;

void init()
{
	for (int i = 0; i < h_cnt; i++) {
		chick_dis[i] = INT_MAX / 2;
	}

}
void calc(int c_num, int cnt)
{
	if (cnt >= M) {
		//계산
		vector<pair<int, int> > ch;
		int cx, cy, hx, hy, dis;

		//선택된 치킨집 벡터에넣는다
		for (int i = 0; i < ch_cnt; i++) {
			if (check[i] == 1) {
				ch.push_back({chick_home[i].first, chick_home[i].second});
			}
		}

		init(); //최소 구하기 위해 초기화

		for (int i = 0; i < ch.size(); i++) {
			cx = ch[i].first; cy = ch[i].second;

			for (int j = 0; j < h_cnt; j++) { //각 집의 치킨거리 구하기
				hx = home[j].first; hy = home[j].second;
				dis = abs(cx - hx) + abs(cy - hy);
				if (chick_dis[j] > dis) { //갱신
					chick_dis[j] = dis;
				}
			}

		}

		int sum = 0;
		for (int i = 0; i < h_cnt; i++) { //도시의 치킨거리(최소) 다 더하기
			sum += chick_dis[i];
		}

		if (ans > sum) { //정답 갱신
			ans = sum;
		}

		return;
	}

	for (int i = c_num; i < ch_cnt; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			calc(i, cnt + 1);
			check[i] = 0;
		}
	}

}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &board[i][j]);

			if (board[i][j] == 1) { //집
				home.push_back({ i, j });
				h_cnt++;
			}
			else if (board[i][j] == 2) { //치킨집
				chick_home.push_back({ i, j });
				ch_cnt++;
			}
		}
	}

	calc(0, 0);

	printf("%d", ans);
	return 0;

}
