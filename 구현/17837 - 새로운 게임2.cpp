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

int N, K;
int board[14][14]; // 0 흰 1 빨 2 파
int dx[5] = {0, 0, 0, -1, 1}; // 오 왼 위 아래
int dy[5] = {0, 1, -1, 0, 0};
vector<int> mark[14][14]; // 체스판 정보

struct piece_info {
    int x;
    int y;
    int dir;
};
struct piece_info pi[12];
int turn = 1;
bool end_flag = false;

void go(int n, int x, int y, int dir, int color)
{
    int xx, yy; // 가려는 곳
    xx = x + dx[dir]; yy = y + dy[dir];
    int index = 0;
    queue<int> tmp;
    queue<int> move; // 흰색
    stack<int> re_move; // 빨간색

    while(mark[x][y][index] != n) { // 앞에서부터 담는다.
        tmp.push(mark[x][y][index]);
        index++;
    }

    if(color == 0) { // 순서대로
        while(index < mark[x][y].size()) { // 해당 번호부터 끝까지 담는다. 순서대로
            move.push(mark[x][y][index]);
            index++;
        }

        while(!move.empty()) {
            int num = move.front(); move.pop();
            mark[xx][yy].push_back(num);
            pi[num].x = xx; pi[num].y = yy; //위치정보 갱신

            if(mark[xx][yy].size() >= 4) {
                end_flag = true;
                return;
            }
        }

    }

    else if(color == 1) { // 거꾸로
        while(index < mark[x][y].size()) { // 해당 번호부터 끝까지 담는다. 거꾸로
            re_move.push(mark[x][y][index]);
            index++;
        }

        while(!re_move.empty()) {
            int num = re_move.top(); re_move.pop();
            mark[xx][yy].push_back(num);
            pi[num].x = xx; pi[num].y = yy; //위치정보 갱신

            if(mark[xx][yy].size() >= 4) {
                end_flag = true;
                return;
            }
        }
    }

    mark[x][y].clear();

    while(!tmp.empty()) { // 다시 담기
        int num = tmp.front(); tmp.pop();
        mark[x][y].push_back(num);
    }
}


int main()
{
    scanf("%d %d", &N, &K);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    int x, y, dir;
    for(int i = 1; i <= K; i++) {
        scanf("%d %d %d",  &x, &y, &dir);
        mark[x][y].push_back(i);
        pi[i].x = x; pi[i].y = y; pi[i].dir = dir;
    }


    while(turn != -1) {
        for(int i = 1; i <= K; i++) {
            int xx, yy, dd; // 가려는 곳
            dd = pi[i].dir;
            xx = pi[i].x + dx[dd]; yy = pi[i].y + dy[dd];

            if(xx < 1 || yy < 1 || xx > N || yy > N || board[xx][yy] == 2) { // 범위 벗어나거나 파란색이면
                // 위치 반대로
                if(dd == 1 || dd == 3) {
                    dd++;
                }
                else {
                    dd--;
                }
                xx = pi[i].x + dx[dd]; yy = pi[i].y + dy[dd]; // 이동하려는 곳 다시 갱신
                pi[i].dir = dd; // 위치는 다시 갱신
            }

            // 가려는 곳이,,
            if(xx >= 1 && yy >= 1 && xx <= N && yy <= N) { // 범위 안이고
                if(board[xx][yy] == 0 || board[xx][yy] == 1) { // 흰 & 빨
                    go(i, pi[i].x, pi[i].y, dd, board[xx][yy]);
                }
            }

        }
        if(end_flag == true) {
            break;
        }
        else if(turn >= 1000) {
            turn = -1; break;
        }
        turn++;
    }

    printf("%d\n", turn);
    return 0;
}
