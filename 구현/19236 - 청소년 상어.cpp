#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int board[6][6];
int dx[10] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[10] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

struct fish_info {
    int fx;
    int fy;
    int fdir;
    bool fstatus = true;
};

int ans_sum;

fish_info fish[18];

void copy1(int origin[6][6], int temp[6][6])
{
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            temp[i][j] = origin[i][j];
        }
    }
}
void copy2(fish_info origin[18], fish_info temp[18])
{
    for(int i = 1; i <= 16; i++) {
        temp[i].fx = origin[i].fx;
        temp[i].fy = origin[i].fy;
        temp[i].fdir = origin[i].fdir;
        temp[i].fstatus = origin[i].fstatus;
    }
}
bool isin(int x, int y)
{
    if(x < 0 || y < 0 || x >= 4 || y >= 4) {
        return false;
    }
    return true;
}
void fish_move(int b_tmp[6][6], fish_info f_tmp[18])
{
    int x, y, d, s, xx, yy;
    for(int i = 1; i <= 16; i++) {
        x = f_tmp[i].fx; y = f_tmp[i].fy; d = f_tmp[i].fdir; s = f_tmp[i].fstatus;
        xx = x + dx[d]; yy = y + dy[d];

        if(s) { // 살아있는 애들만

            if(!isin(xx, yy) || b_tmp[xx][yy] == -1) { // 경계를 넘거나 상어면 반시계 회전
                int cnt = 7;
                int rx, ry;

                rx = xx; ry = yy;

                while(cnt--) {
                    if(d == 8) {
                        d = 1;
                    }
                    else {
                        d++;
                    }
                    rx = x + dx[d]; ry = y + dy[d];
                    if(isin(rx, ry) && b_tmp[rx][ry] != -1) {
                        xx = rx; yy = ry; f_tmp[i].fdir = d;
                        break;
                    }
                }
            }

            if(isin(xx, yy) && b_tmp[xx][yy] != -1) {
                if(b_tmp[xx][yy] == 0) { // 빈 칸
                    b_tmp[x][y] = 0;
                    b_tmp[xx][yy] = i;

                    f_tmp[i].fx = xx; f_tmp[i].fy = yy;
                }
                else { // 물고기
                    int ex_num = b_tmp[xx][yy];
                    b_tmp[x][y] = ex_num;
                    b_tmp[xx][yy] = i;
                    // 교환
                    f_tmp[ex_num].fx = x; f_tmp[ex_num].fy = y;
                    f_tmp[i].fx = xx; f_tmp[i].fy = yy;
                }
            }
        }

    }
}
void shark_move(int o_board[6][6], fish_info o_fish[18], int x, int y, int sum) // 상어 정보
{
    int b_tmp[6][6];
    fish_info f_tmp[18];
    queue<pair<int, int > > q;
    int tx, ty, tdir;

    // 지금 상태 따로 저장(보드와 물고기 위치도..?)
    copy1(o_board, b_tmp);
    copy2(o_fish, f_tmp);

    // 자리에 있는 물고기 먹고 상어 방향 설정
    int fish_num = b_tmp[x][y];
    int fish_dir = f_tmp[fish_num].fdir;

    b_tmp[x][y] = -1; // 상어 위치 표시
    f_tmp[fish_num].fstatus = false; // 물고기 죽어
    sum += fish_num; // 물고기 번호 더하기

    tdir = fish_dir;
    tx = x + dx[tdir]; ty = y + dy[tdir];

    // 물고기 이동
    fish_move(b_tmp, f_tmp);

    //  상어가 갈 수 있는 곳을 큐에 미리 넣는다.
    while(1) {
        if(!isin(tx, ty)) {
            break;
        }

        if(b_tmp[tx][ty] > 0) { // 자리에 물고기가 있어야 갈 수 있음(-1 : 상어, 0 : 빈 곳)
            q.push({tx, ty});
        }
        tx = tx + dx[tdir]; ty = ty + dy[tdir];
    }

    if(q.size() == 0) {

        if(ans_sum < sum) {
            ans_sum = sum;
        }
        return;
    }

    // 갈 수 있는 곳을 기준으로 다시 재귀돌린다.
    while(!q.empty()) {
        int xx, yy;
        xx = q.front().first; yy = q.front().second;
        q.pop();

        // go
        b_tmp[x][y] = 0; // 상어가 간자리는 제자리로
        shark_move(b_tmp, f_tmp, xx, yy, sum);
    }
}

int main()
{
    int n, d;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%d %d", &n, &d);

            board[i][j] = n; // 물고기 번호
            fish[n].fx = i; fish[n].fy = j; fish[n].fdir = d;
        }
    }

    shark_move(board, fish, 0, 0, 0);

    printf("%d\n", ans_sum);
    return 0;
}
