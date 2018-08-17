//
//  14502-연구소.cpp
//  algoalgo
//
//  Created by JoHanseul on 2018. 8. 16..
//  Copyright © 2018년 JoHanseul. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int board[9][9];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int> > v;
int ans = 0;

bool isin(int x, int y)
{
    if(x >= 1 && y >= 1 && x <= N && y <= M) {
        return true;
    }
    else {
        return false;
    }
}
int spread()
{
    int tmp[9][9] = {0, };
    int x, y, xx, yy, cnt = 0;
    queue<pair<int, int> > q;

    //board가 변하면 안되니까 tmp 사용
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            tmp[i][j] = board[i][j];
        }
    }
    //원래 바이러스 큐에 넣어주기
    for(int i = 0; i < v.size(); i++) {
        q.push(make_pair(v[i].first, v[i].second));
    }

    while(!q.empty()) {
        x = q.front().first; y = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++) {
            xx = x + dx[k]; yy = y + dy[k];
            if(tmp[xx][yy] == 0 && isin(xx, yy)) {
                tmp[xx][yy] = 2;
                q.push(make_pair(xx, yy));
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(tmp[i][j] == 0) {
                cnt++;
            }
        }
    }

    return cnt;

}

void set_wall(int n)
{
    if(n > 3) {

        //벽 3개 세웠으니 바이러스 퍼지
        int nn = spread();
        if(ans < nn) { ans = nn; }
        return;

    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(board[i][j] == 0) {
                board[i][j] = 1;
                set_wall(n + 1);
                board[i][j] = 0;
            }
        }
    }
}
int main() {


    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%d", &board[i][j]);
            if(board[i][j] == 2) { //바이러스 세기
                v.push_back(pair<int, int>(i, j));
            }
        }
    }

    set_wall(1);


    printf("%d", ans);
    return 0;
}
