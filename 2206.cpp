#include <stdio.h>
#include <iostream>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

int N, M;
int board[1002][1002];
int visit[1002][1002][2];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y)
{
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            visit[i][j][0] = visit[i][j][1] = INT_MAX / 2;
        }
    }

    int ans;
    int xx, yy;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visit[x][y][0] = 1;
    
    while(!q.empty()) {
        xx = q.front().first; yy = q.front().second;
       // printf("%d %d\n", xx, yy);
        q.pop();
        for(int k = 0; k < 4; k++) {
            if((xx + dx[k] >= 1) && (xx + dx[k] <= N) && (yy + dy[k] >= 1) && (yy + dy[k] <= M)) {
                //인접이 0일때
                if(board[xx + dx[k]][yy + dy[k]] == 0) {
                    if(visit[xx + dx[k]][yy + dy[k]][0] > visit[xx][yy][0] + 1) {
                        visit[xx + dx[k]][yy + dy[k]][0] = visit[xx][yy][0] + 1;
                        q.push(make_pair(xx + dx[k], yy + dy[k]));
                        
                    }
                    else if(visit[xx + dx[k]][yy + dy[k]][1] > visit[xx][yy][1] + 1) {
                        if(visit[xx][yy][0] > visit[xx][yy][1]) {
                            visit[xx + dx[k]][yy + dy[k]][1] = visit[xx][yy][1] + 1;
                            q.push(make_pair(xx + dx[k], yy + dy[k]));
                        }
                    }
                    
                }
                
                //인접이 1일때
                else if(board[xx + dx[k]][yy + dy[k]] == 1) {
                    if(visit[xx + dx[k]][yy + dy[k]][0] > visit[xx][yy][0] + 1) {                        visit[xx + dx[k]][yy + dy[k]][1] = visit[xx][yy][0] + 1;
                        q.push(make_pair(xx + dx[k], yy + dy[k]));
                    }
                }

            }
        }
    }

    ans = min(visit[N][M][0], visit[N][M][1]);
    return ans;
    
}
int main()
{
    int ans;
    
    scanf("%d %d", &N, &M);
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%1d", &board[i][j]);
        }
    }
    
    ans = bfs(1, 1);
    
    if(ans == (INT_MAX / 2)) {
        ans = -1;
    }
    
    printf("%d", ans);
    return 0;
}