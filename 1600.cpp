#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;

struct monkey {
	int x;
	int y;
	int c;
	monkey(int a, int b, int d) {
		x = a;
		y = b;
		c = d;
	}
};
int board[205][205];
int visit[205][205][32];

int cnt;
int xx, yy, cc;
int k = 0, w, h;
int dx[8] = {-1, -1, +1, +1, -2, -2, +2, +2};
int dy[8] = {-2, +2, -2, +2, -1, +1, -1, +1};

int kx[4] = {1, 0, -1, 0};
int ky[4] = {0, 1, 0, -1};

queue<monkey> q;

int BFS(queue<monkey> q) {

    while(!q.empty()) {
		xx = q.front().x;
		yy = q.front().y;
		cc = q.front().c;
      
        q.pop();
        
		//일반 이동
        for(int i = 0; i < 4; i++) {
            if(xx + kx[i] >= 0 && xx + kx[i] < h && yy + ky[i] >= 0 && yy + ky[i] < w) {
                if(visit[xx + kx[i]][yy + ky[i]][cc] > visit[xx][yy][cc] + 1 && board[xx + kx[i]][yy + ky[i]] == 0) {
                    visit[xx + kx[i]][yy + ky[i]][cc] = visit[xx][yy][cc] + 1;
                    q.push(monkey(xx + kx[i], yy + ky[i], cc));
                }

            }
        }
     
        //나이트 이동
        if(cc < k) {
			cc = cc + 1;
            for(int i = 0; i < 8; i++) {
                if(xx + dx[i] >= 0 && xx + dx[i] < h && yy + dy[i] >= 0 && yy + dy[i] < w) {
                    if(visit[xx + dx[i]][yy + dy[i]][cc] > visit[xx][yy][cc - 1] + 1 && board[xx + dx[i]][yy + dy[i]] == 0) {
                        visit[xx + dx[i]][yy + dy[i]][cc] = visit[xx][yy][cc - 1] + 1;
                        q.push(monkey(xx + dx[i], yy + dy[i], cc));
                    }
            
                }
                
            }
            
        }
        
	}
        
    cnt = INT_MAX / 2;
	for(int l = 0; l <= k; l++) {
		cnt = min(visit[h - 1][w - 1][l], cnt);
	}
	return cnt;


}
void init() {
    
    for(int l = 0; l < h; l++) {
        for(int d = 0; d < w; d++) {
			for(int u = 0; u < 32; u++) {
				visit[l][d][u] = INT_MAX / 2;
			}
        }
	}
    
}


int main()
{
    
    scanf("%d", &k);
        
    scanf("%d %d", &w, &h);
    
    init();
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
			scanf("%d", &board[i][j]);
        }
    }
	q.push(monkey(0, 0, 0));
	 visit[0][0][0] = 0;
    int answer = BFS(q);
   
    if(answer == (INT_MAX / 2)) {
        printf("-1\n");
    }
    else {
        printf("%d\n", answer);
    }


}