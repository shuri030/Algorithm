#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <queue>
#include <algorithm>
using namespace std;

int K, W, H;
int board[202][202];
int check[202][202][32]; //마지막 인덱스 : 찬스를 k번 사용했을때 최소 이동
int nx[8] = {-1, -2, -2, -1, 1, 2, 1, 2};
int ny[8] = {-2, -1, 1, 2, 2, 1, -2, -1};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

typedef struct monkey {
    int x;
    int y;
    int c;

    monkey(int xx, int yy, int cc) {
        x = xx;
        y = yy;
        c = cc;
    }
}m;

void input()
{
    scanf("%d", &K);
    scanf("%d %d", &W, &H);

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            for(int k = 0; k <= 30; k++) {
                check[i][j][k] = INT_MAX / 2; //초기화
            }
        }
    }
}
bool isin(int x, int y)
{
    if(x < 1 || y < 1 || x > H || y > W)
        return false;
    return true;
}
void BFS(int x, int y)
{
    int c;
    queue<m> q;
    q.push({x, y, 0});
    check[x][y][0] = 0;

    int xx, yy;

    while(!q.empty()) {
        x = q.front().x; y = q.front().y; c = q.front().c;
        q.pop();

        //일반 이동
        for(int k = 0; k < 4; k++) {
            xx = x + dx[k]; yy = y + dy[k];
            if(isin(xx, yy) && board[xx][yy] == 0) {
                if(check[xx][yy][c] > check[x][y][c] + 1) { //찬스를 쓰지 않으니
                    check[xx][yy][c] = check[x][y][c] + 1;
                    q.push({xx, yy, c});
                }
            }
        }


        //나이트 이동
        if(c < K) { //전체 찬스 사용횟수보다 작을때만
            for(int k = 0; k < 8; k++) {
                xx = x + nx[k]; yy = y + ny[k];
                if(isin(xx, yy) && board[xx][yy] == 0) {
                    if((check[xx][yy][c + 1] > check[x][y][c] + 1) && (c < K)) {
                        check[xx][yy][c + 1] = check[x][y][c] + 1; //찬스써야하니 +1
                        q.push({xx, yy, c + 1});

                    }
                }
            }
        }
    }



}
int main()
{
    input();

    BFS(1, 1);

    int ans = INT_MAX / 2;

    for(int k = 0; k <= K; k++) { //가장 작은 답 찾기
        ans = min(ans, check[H][W][k]);
    }

    if(ans == INT_MAX / 2)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}
