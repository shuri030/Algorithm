#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
int board[301][301];
int cal[301][301];
int visit[301][301];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int> > ice_land;

bool isin(int x, int y)
{
    if(x >= 1 && y >= 1 && x <= N && y <= M)
        return true;
    else
        return false;
}
void cnt_water()
{
    int x, y, xx, yy;

    while(!ice_land.empty()) {
        x = ice_land.front().first; y = ice_land.front().second;
        ice_land.pop();

        for(int k = 0; k < 4; k++) {
            xx = x + dx[k]; yy = y + dy[k];
            if(isin(xx, yy) && board[xx][yy] == 0) {
                if(cal[x][y] > 0) {
                    cal[x][y]--;

                }
            }
        }
    }

    //다 녹은것 바다로 만들기
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(cal[i][j] <= 0) {
                board[i][j] = 0;
            }
            else {
                board[i][j] = cal[i][j];
            }

        }
    }

}

void dfs(int i, int j)
{
    visit[i][j] = 1;

    for(int k = 0; k < 4; k++) {
        if(isin(i + dx[k], j + dy[k])) {
            if(board[i + dx[k]][j + dy[k]] != 0 && visit[i + dx[k]][j + dy[k]] == 0) {
                dfs(i + dx[k], j + dy[k]);
            }
        }
    }

}

int main()
{

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    int year = 0;

    while(1) {
        //복제
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                cal[i][j] = board[i][j];
                if(board[i][j] != 0) {
                    ice_land.push((make_pair(i, j)));
                }
            }
        }

        cnt_water();
        year++;

        //빙산 갯수
        int land = 0, flag = 0;

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                if(board[i][j] != 0 && visit[i][j] == 0) {
                    dfs(i, j);
                    flag = 1;
                    land++;
                }
            }
        }

        if(land >= 2) {
            printf("%d\n", year);
            break;
        }
        if(flag == 0) {
            printf("%d\n", flag);
            break;
        }

        memset(visit, 0, sizeof(visit));
    }


    return 0;
}
