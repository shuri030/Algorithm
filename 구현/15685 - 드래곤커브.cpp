#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int visit[101][101];
queue<int> q;
vector<int> v;

void curve(int a, int b, int g, int cur_g)
{
    if(cur_g > g) { return; }
    
    int n;

    while(!q.empty()) {
        n = q.front(); q.pop();
        v.push_back(n);

        if(n == 0) {
            a = a + 1;
            visit[b][a] = 1;
        }
        else if(n == 1) {
            b = b - 1;
            visit[b][a] = 1;
        }
        else if(n == 2) {
            a = a - 1;
            visit[b][a] = 1;
        }
        else if(n == 3) {
            b = b + 1;
            visit[b][a] = 1;
        }
    }

    for(int i = (int)v.size() - 1; i >= 0; i--) {
        if(v[i] == 0) {
            q.push(1);
        }
        else if(v[i] == 1) {
            q.push(2);
        }
        else if(v[i] == 2) {
            q.push(3);
        }
        else if(v[i] == 3) {
            q.push(0);
        }
    }


    curve(a, b, g, cur_g + 1);
}
int main()
{
    int N;
    int x, y, d, g;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &x, &y, &d, &g);
        visit[y][x] = 1;
        q.push(d);
        curve(x, y, g, 0);

        v.clear();
        while(!q.empty()) { q.pop(); }
    }

    int cnt = 0;

    for(int i = 0; i < 100; i++) {
        for(int j = 0 ; j < 100; j++) {
            if((visit[i][j] == 1) && (visit[i][j + 1] == 1) && (visit[i + 1][j + 1] == 1) && (visit[i + 1][j] == 1))
                cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}
