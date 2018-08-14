#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int num[9];
int visit[9];
int n;

void go(int k)
{
    if(k > n) {
        for(int i = 1; i <= n; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
        return;
    }


    for(int i = 1; i <= n; i++) {
        if(visit[i] == 0) {
            num[k] = i;
            visit[i] = 1;
            go(k + 1);
            visit[i] = 0;
        }

    }

    return;
    
}
int main()
{

    scanf("%d", &n);

    go(1);
    return 0;
}
