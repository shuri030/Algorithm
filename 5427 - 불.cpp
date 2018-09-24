#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <queue>
#include <algorithm>

using namespace std;

int w, h;
char board[1002][1002];
int visit[1002][1002];
int ss[1002][1002];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    queue<pair<int, int> > fire; //불
    queue<pair<int, int> > sang; //상근
    int tc, ans = 0;

    scanf("%d", &tc);
    
    for(int t = 1; t <= tc; t++) {
        scanf("%d %d", &w, &h);
        
        //visit과 상근 초기화
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                visit[i][j] = ss[i][j] = INT_MAX / 2;
            }
        }
        
        //input
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                scanf(" %1c", &board[i][j]);
                if(board[i][j] == '@') {
                    sang.push(make_pair(i, j));
                    ss[i][j] = 0;
                }
                else if(board[i][j] == '*') {
                    fire.push(make_pair(i, j));
                    visit[i][j] = 0;
                }
            }
        }
       
        int fx, fy, xx, yy;
        //불 번지기(몇초에 그 자리가 불에 번지는지)
        while(!fire.empty()) {
            fx = fire.front().first; fy = fire.front().second;
            fire.pop();
            
            for(int k = 0; k < 4; k++) {
                xx = fx + dx[k]; yy = fy + dy[k];
                if(xx >= 1 && xx <= h && yy >= 1 && yy <= w) {
                    if(board[xx][yy] == '.' || board[xx][yy] == '@') {
                        if(visit[xx][yy] > visit[fx][fy] + 1) {
                            visit[xx][yy] = visit[fx][fy] + 1;
                            fire.push(make_pair(xx, yy));
                        }
                    }
                }
            }
        }
        
        //상근이 이동하기
        int x, y;
        while(!sang.empty()) {
            x = sang.front().first; y = sang.front().second;
            sang.pop();
            
            if((x == 1) || (x == h) || (y == 1) || (y == w)) { //경계에 있으면
                ans = ss[x][y] + 1; //현재 상태에서 1초지나야 탈출이니까
                break;
            }

            for(int k = 0; k < 4; k++) {
                xx = x + dx[k]; yy = y + dy[k];
                if(xx >= 1 && xx <= h && yy >= 1 && yy <= w) {
                    if((board[xx][yy] == '.') && (visit[xx][yy] > ss[x][y] + 1) && (ss[xx][yy] > ss[x][y] + 1)) { //현재상태에서 +1했을때보다 클때만 이동
                        ss[xx][yy] = ss[x][y] + 1;
                        sang.push(make_pair(xx, yy));
                    }
                }
            }
        }
        if(ans == 0) {
            printf("IMPOSSIBLE\n");
        }
        else {
            printf("%d\n", ans);
        }
        memset(board, 0, sizeof(board));
		while(!sang.empty()) { sang.pop(); }
    }

    return 0;
}