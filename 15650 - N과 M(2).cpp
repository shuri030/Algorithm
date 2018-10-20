#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int check[9];

void go(int cnt, int cur)
{
    if(cnt >= M) {
        for(int i = 1; i <= N; i++) {
            if(check[i] == 1) {
                printf("%d ", i);
            }
        }
        printf("\n");
        return;
    }


    for(int i = cur; i <= N; i++) {
        if(check[i] == 0) {
            check[i] = 1;
            go(cnt + 1, i);
            check[i] = 0;
        }
    }
}
int main()
{
    scanf("%d %d", &N, &M);

    go(0, 1);

    return 0;
}
