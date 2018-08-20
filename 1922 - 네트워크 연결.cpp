#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <functional>
#include <algorithm>
using namespace std;

struct com {
    int c1;
    int c2;
    int cost;

    com() {}
    bool operator <(const com &an) const {
        return cost < an.cost;
    }
};
com com[100002];

int N, M;
int par[1002];

int find(int u)
{
    if(par[u] == u) return u;
    else
        return par[u] = find(par[u]);
}

int main()
{
    int a, b, c, ans = 0;
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        com[i].c1 = a;
        com[i].c2 = b;
        com[i].cost = c;
    }

    sort(com, com + M);


    for(int i = 1; i <= N; i++) {
        par[i] = i;
    }

    for(int i = 0; i < M; i++) {
        int u = find(com[i].c1);
        int v = find(com[i].c2);

        if(u != v) {
            par[u] = v;
            ans += com[i].cost;
        }
        else {
            continue;
        }
    }

    printf("%d", ans);
    return 0;
}
