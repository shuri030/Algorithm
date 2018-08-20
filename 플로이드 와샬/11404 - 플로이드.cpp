#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <functional>
#include <algorithm>
using namespace std;

int N, M;
int cost[102][102];

int main()
{
    int a, b, c;

    scanf("%d", &N);
    scanf("%d", &M);

    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            if(i == j) {
                cost[i][j] = 0;
            }
            else {
                cost[i][j] = INT_MAX / 2;
            }
        }
    }

    for(int i = 1; i <= M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        cost[a][b] = min(cost[a][b], c);
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(cost[i][k] + cost[k][j] < cost[i][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(cost[i][j] == INT_MAX / 2) {
                printf("0 ");
            }
            else {
                printf("%d ", cost[i][j]);
            }

        }
        printf("\n");
    }


    return 0;
}
