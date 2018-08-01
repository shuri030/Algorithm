#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

int tc, n, m;
int imp[105];
int visit[105];


int find_max()
{
    
    int max_o = -INT_MAX;
    
    for(int i = 0; i < n; i++) {
        if((visit[i] == 0) && (imp[i] > max_o)) {
            max_o = imp[i];
        }
    }
    
    return max_o;
    
}
int main()
{
    
    
    scanf("%d", &tc);
    
    for(int t = 1; t <= tc; t++) {
        queue<int> q;
        
        scanf("%d %d", &n, &m);
        
        int od = 0;
        
        for(int i = 0; i < n; i++) {
            scanf("%d", &imp[i]);
            q.push(i);
        }
        
        int ma = find_max();
        
        while(!q.empty()) {
            
            int x = q.front();
            
            if(imp[x] == ma) {
                od++;
                visit[x] = od;
                if(x == m) {
                    break;
                }
                q.pop();
                ma = find_max();
                
            }
            else {
                q.pop();
                q.push(x);
            }
        }
        
        printf("%d\n", od);
        memset(imp, 0, sizeof(imp));
        memset(visit, 0, sizeof(visit));
        
        
        
    }
    
    return 0;
}