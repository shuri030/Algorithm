#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int n, k;
int visit[1000010];
int ans = 0;

int BFS(int n) {
    
    visit[n] = 0;
    queue<int> q;
    int cur;
    cur = n;
    q.push(cur);
    
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        
        if((cur + 1) <= 100000 && visit[cur + 1] > visit[cur] + 1) {
            q.push(cur + 1);
            visit[cur + 1] = visit[cur] + 1;
        }
        
        if((cur - 1) >= 0 && (cur - 1) <= 100000 && visit[cur - 1] > visit[cur] + 1) {
            q.push(cur - 1);
            visit[cur - 1] = visit[cur] + 1;
        }
        
        if((cur * 2) <= 100000 && visit[cur * 2] > visit[cur] + 1) {
            q.push(cur * 2);
            visit[cur * 2] = visit[cur] + 1;
        }
        
    }
    
    return visit[k];
    
}
int main()
{

    scanf("%d %d", &n, &k);
    
    for(int i = 0; i <= 100000; i++) {
        visit[i] = INT_MAX / 2;
    }
    
    printf("%d", BFS(n));
  
    return 0;  
}