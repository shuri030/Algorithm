#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int N, M;
int board[102][102];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cheeze;

bool isin(int x, int y)
{
    if(x >= 1 && y >= 1 && x <= N && y <= M)
        return true;
    return false;
}

void find_air(int xx, int yy)
{
    int x = xx, y = yy;

    for(int k = 0; k < 4; k++) {
        if(isin(x + dx[k], y + dy[k]) && board[x + dx[k]][y + dy[k]] == 0) {
            board[x + dx[k]][y + dy[k]] = 2;
            find_air(x + dx[k], y + dy[k]);
        }
    }
}
int melting()
{
    int cnt = 0;
    queue<pair<int, int> > q;
    queue<pair<int, int> > m;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(board[i][j] == 1) {
                for(int k = 0; k < 4; k++) {
                    if(isin(i + dx[k], j + dy[k]) && board[i + dx[k]][j + dy[k]] == 2) {
                        cnt++; //공기 닿은 면 개수
                    }
                }
                if(cnt >= 2) {
                    q.push(make_pair(i, j)); //녹일 애들 넣기
                }
                cnt = 0;
            }
        }
    }

    while(!q.empty()) {
        int xx, yy;
        xx = q.front().first; yy = q.front().second;
        q.pop();
        m.push(make_pair(xx, yy));
        board[xx][yy] = 2;
        cheeze--;
    }


    while(!m.empty()) {
        int xx, yy;
        xx = m.front().first; yy = m.front().second;
        m.pop();

        find_air(xx, yy);
    }


    return cheeze;

}
int main()
{
    int n = 1, ans = 1;
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%d", &board[i][j]);
            if(board[i][j] == 1) {
                cheeze++;
            }
        }
    }

    //공기 처리하기
    find_air(1, 1);

    while(1) {
        n = melting();
        if(n == 0) {
            printf("%d", ans);
            break;
        }
        ans++;
    }

    return 0;
}

//예외 테케
/*
8 10
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 1 1 0 0 0 1 1 0
0 0 1 0 1 1 1 0 1 0
0 0 1 0 0 1 0 0 1 0
0 0 1 0 1 1 1 0 1 0
0 0 1 1 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0 0
*/
