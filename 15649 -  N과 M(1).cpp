#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int check[9];
int num[9];

void go(int cnt)
{
    if(cnt >= M) {
        for(int i = 0; i < M; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1; i <= N; i++) {
        if(check[i] == 0) {
            check[i] = 1;
            num[cnt]  = i;
            go(cnt + 1);
            check[i] = 0;
        }
    }
}
int main()
{
    scanf("%d %d", &N, &M);

    go(0);

    return 0;
}
