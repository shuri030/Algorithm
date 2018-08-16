//
//  2667 - 단지번호붙이기.cpp
//  algoalgo
//
//  Created by JoHanseul on 2018. 8. 16..
//  Copyright © 2018년 JoHanseul. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int board[26][26];
int visit[26][26];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> v;
int cnt;

void DFS(int x, int y)
{
    visit[x][y] = 1;

    for(int k = 0; k < 4; k++) {
        if(visit[x + dx[k]][y + dy[k]] == 0 && board[x + dx[k]][y + dy[k]] == 1) {
            cnt++;
            DFS(x + dx[k], y + dy[k]);
        }
    }

}

int main() {

    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%1d", &board[i][j]);
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(board[i][j] == 1 && visit[i][j] == 0) {
                cnt = 1;
                DFS(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());
    printf("%d\n", (int)v.size());

    for(int i = 0; i < v.size(); i++) {
        printf("%d\n", v[i]);
    }

    return 0;
}
