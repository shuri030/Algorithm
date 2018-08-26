#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int N, M;
int board[102][102];
int visit[102][102];
vector<pair<int, int> > v[101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


bool isin(int x, int y)
{
    if(x >= 1 && y >= 1 && x <= N && y <= N)
        return true;
    return false;
}
void check(int x, int y) {

    int xx, yy;

    for(int k = 0; k < 4; k++) {
        xx = x + dx[k]; yy = y + dy[k];
        if(isin(xx, yy) && board[xx][yy] > 0 && visit[xx][yy] == 0) {
            visit[xx][yy] = 1;
            check(xx, yy);
        }
    }


}
int main()
{
    int m = 0, cnt = 0, ans = 1;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &board[i][j]);
            v[board[i][j]].push_back({i, j}); //높이 별 인덱스
            if(m < board[i][j]) m = board[i][j]; //최대 높이
        }
    }

    for(int i = 1; i <= m - 1; i++) {

        for(int j = 0; j < v[i].size(); j++) {
            board[v[i][j].first][v[i][j].second] = 0; //잠김
        }

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(board[i][j] > 0 && visit[i][j] == 0) {
                    visit[i][j] = 1;
                    check(i, j);
                    cnt++;
                }
            }
        }

        if(ans <  cnt) {
            ans = cnt;
        }
        cnt = 0;
        memset(visit, 0, sizeof(visit));
    }

    printf("%d", ans);

    return 0;
}
