#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int N, M;
vector<int> rel[10002];
int ans[10002];
int visit[10002];
int max_com = 0;

int main()
{
    int a, b;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        rel[b].push_back(a);
    }

    queue<int> q;

    for(int i = 1; i <= N; i++) {

        int cnt = 1, n; //자기자신도 포함해줘야한다
        q.push(i);
        visit[i] = 1;

        while(!q.empty()) {

            n = q.front(); q.pop();

            for(int j = 0; j < rel[n].size(); j++) {
                if(visit[rel[n][j]] == 0) {
                    visit[rel[n][j]] = 1;
                    q.push(rel[n][j]);
                    cnt++;
                }
            }

        }

        ans[i] = cnt;
        if(cnt > max_com) { max_com = cnt; }

        while(!q.empty()) {
            q.pop();
        }
        memset(visit, 0, sizeof(visit));
    }

    for(int i = 1; i <= N; i++) {
        if(ans[i] == max_com) {
           printf("%d ", i);
        }
    }

    return 0;
}
