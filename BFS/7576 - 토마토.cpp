#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

int N,M;
int cnt = 0;
//1 = 익은 토마토 0 = 익지않은 토마토 -1= 토마토가 없다
// 0을 세서 익을때마다 마이너스해준당 cnt가 0이면 일수출력 아니면 -1출력
int board[1005][1005];
int visit[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > to;
int ans = 0;

void cal()
{
    int x, y, xx, yy;
    while(!to.empty()) {
        x = to.front().first;
        y = to.front().second;
        to.pop();
        if(visit[x][y] > ans) {
            ans = visit[x][y];
        }

        for(int k = 0; k < 4; k++) {
            xx = x + dx[k];
            yy = y + dy[k];
            if((xx >= 1) && (yy >= 1) && (xx <= N) && (yy <= M) && (board[xx][yy] == 0)) {
                if(visit[xx][yy] > visit[x][y] + 1) {
                    cnt--;
                    board[xx][yy] = 1;
                    visit[xx][yy] = visit[x][y] + 1;
                    to.push(make_pair(xx, yy));
                }
            }
        }

    }


}

int main()
{

    scanf("%d %d", &M, &N);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            visit[i][j] = INT_MAX / 2;
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%d", &board[i][j]);
            if(board[i][j] == 0) {
                cnt++;
            }
            else if(board[i][j] == 1) {
                to.push(make_pair(i, j));
                visit[i][j] = 0;
            }
        }
    }
    cal();

    if(cnt == 0) {
        printf("%d", ans);
    }
    else {
        printf("-1");
    }


    return 0;
}
