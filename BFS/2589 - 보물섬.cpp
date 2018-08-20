#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int visit[52][52];
char board[52][52];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isin(int x, int y)
{
    if(x >= 1 && y >= 1 && x <= N && y <= M)
        return true;
    else
        return false;
}
int bfs(int x, int y)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visit[x][y] = 0;

    int xx, yy, t = 0;

    while(!q.empty()) {
        x = q.front().first; y = q.front().second;
        q.pop();
        if(t < visit[x][y]) { t = visit[x][y]; }

        for(int k = 0; k < 4; k++) {
            xx = x + dx[k]; yy = y + dy[k];
            if((isin(xx, yy)) && (board[xx][yy] == 'L') && (visit[xx][yy] == 0)) {
                visit[xx][yy] = visit[x][y] + 1;
                q.push(make_pair(xx, yy));
            }

        }
    }

    memset(visit, 0, sizeof(visit));

    return t;
}
int main()
{
    queue<pair<int, int> > l;

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf(" %1c", &board[i][j]);
          //  visit[i][j] = INT_MAX / 2;
            if(board[i][j] == 'L') {
                l.push(make_pair(i, j));
            }
        }
    }

    int x, y, t, ans = 0;
    while(!l.empty()) {
        x = l.front().first; y = l.front().second;
        l.pop();

        t = bfs(x, y);
        if(ans < t) {
            ans = t;
        }

    }

    printf("%d\n", ans);


    return 0;
}
