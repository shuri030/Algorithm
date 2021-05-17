#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M, k;
int board[22][22];

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

struct Shark {
    int x;
    int y;
    int c_dir;
    vector<int> dir[5];
    bool isalive = true;
};

Shark shark[401];
pair<int, int> trace[22][22];
int shark_cnt;

bool isin(int x, int y)
{
    if(x < 0 || y < 0 || x >= N || y >= N) {
        return false;
    }
    return true;
}
void move()
{
    bool isalive;
    int x = 0, y = 0, cd = 0, xx = 0, yy = 0;
    int tmp[22][22] = {0, };
    int flag = 0;

    for(int i = M; i > 0; i--) {
        flag = 0;
        isalive = shark[i].isalive;

        if(isalive) { // 살아 있는 상어만
            x = shark[i].x; y = shark[i].y; cd = shark[i].c_dir;
            // 이동 방향 결정

            // 1. 아무 냄새 없는 칸( 빈 칸 )
            for(int kk = 0; kk < 4; kk++) {
                xx = x + dx[shark[i].dir[cd][kk]]; yy = y + dy[shark[i].dir[cd][kk]];
                if(isin(xx, yy) && board[xx][yy] == 0 && trace[xx][yy].first == 0) {
                    // 이동
                    if(tmp[xx][yy] != 0) { // 다른 상어가 이동하려고 했으면,,
                        shark[tmp[xx][yy]].isalive = false; // 없애고
                        shark_cnt--;
                    }

                    shark[i].c_dir = shark[i].dir[cd][kk]; // 가져갈 방향
                    tmp[xx][yy] = i;
                    flag = 1;
                    break;
                }
            }

            // 2. 자신의 냄새가 있는 칸, 위에서 안움직였을때만
            if(flag == 0) {
                for(int kk = 0; kk < 4; kk++) {
                    xx = x + dx[shark[i].dir[cd][kk]]; yy = y + dy[shark[i].dir[cd][kk]];
                    if(isin(xx, yy) && board[xx][yy] == 0 && trace[xx][yy].first == i) {
                        // 이동
                        if(tmp[xx][yy] != 0) { // 다른 상어가 이동하려고 했으면,,
                            shark[tmp[xx][yy]].isalive = false;
                            shark_cnt--;
                        }

                        shark[i].c_dir = shark[i].dir[cd][kk]; // 가져갈 방향
                        tmp[xx][yy] = i;
                        break;
                    }
                }
            }
        }
    }

    // 냄새 초 빼기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(trace[i][j].first != 0) { // 냄새 남은 곳
                if(trace[i][j].second == 1) { // 냄새 없어질 곳
                    trace[i][j].first = 0; trace[i][j].second = 0;
                }
                else {
                    trace[i][j].second--;
                }
            }
        }
    }

    // 움직일 상어 움직이기
    int num;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(tmp[i][j] != 0) { // 갱신된 곳
                num = tmp[i][j]; x = shark[num].x; y = shark[num].y; // 기존 위치
                board[x][y] = 0; board[i][j] = num;
                trace[i][j].first = num; trace[i][j].second = k;
                shark[num].x = i; shark[num].y = j;
            }
        }
    }

    // 나간 상어 처리
    for(int i = M; i > 0; i--) {
        isalive = shark[i].isalive;
        if(!isalive) {
            x = shark[i].x; y = shark[i].y;
            board[x][y] = 0;
        }
    }
}
int main()
{
    scanf("%d %d %d", &N, &M, &k);

    // 지금 바다 상태
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
            if(board[i][j] != 0) {
                shark[board[i][j]].x = i;
                shark[board[i][j]].y = j;

                trace[i][j].first = board[i][j];
                trace[i][j].second = k;
            }
        }
    }

    int d_tmp[M + 1];
    int dd = 1;
    //  현재 상어 방향
    for(int i = 0; i < M; i++) {
        scanf("%d", &d_tmp[i]);
    }

    for(int i = 0; i < M; i++) {
        shark[i + 1].c_dir = d_tmp[i];
    }

    // 우선순위
    for(int i = 0; i < M; i++) {
        dd = 1;
        for(int j = 0; j < 4; j++) {
            for(int l = 0; l < 4; l++) {
                scanf("%d", &d_tmp[l]);
            }

            for(int l = 0; l < 4; l++) {
                shark[i + 1].dir[dd].push_back(d_tmp[l]);
            }
            dd++;
        }
    }

    shark_cnt = M;
    int sec = 1;

    while(shark_cnt > 0) {
        if(sec > 1000) {
            printf("-1\n");
            break;
        }
        // 이동
        move();

        if(shark_cnt == 1) {
            printf("%d\n", sec);
            break;
        }
        sec++;
    }

    return 0;
}
