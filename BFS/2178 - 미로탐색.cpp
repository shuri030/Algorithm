//
//  2178-미로탐색.cpp
//  algoalgo
//
//  Created by JoHanseul on 2018. 8. 16..
//  Copyright © 2018년 JoHanseul. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <queue>

using namespace std;

int board[101][101]; //인풋 배열
int check[101][101]; //최소 이동거리 담을 배열
int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS(int x, int y)
{
    int xx, yy;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    check[x][y] = 1;

    while(!q.empty()) {
        x = q.front().first; y = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++) {
            xx = x + dx[k]; yy = y + dy[k];
            if((board[xx][yy] == 1) && (check[xx][yy] > check[x][y] + 1)) {
                check[xx][yy] = check[x][y] + 1;
                q.push(make_pair(xx, yy));
            }
        }
    }

    return check[N][M];

}

int main() {

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%1d", &board[i][j]);
            check[i][j] = INT_MAX / 2;
        }
    }

    printf("%d", BFS(1, 1));

    return 0;
}
