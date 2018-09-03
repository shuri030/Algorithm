#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <functional>
#include <algorithm>
using namespace std;

typedef struct node {
    int to;
    int cost;
}node;

int N, M, X;
vector<node> road[1002];
int dis[1002];

struct sorting {
    int operator() (node a, node b) {
        return a.cost > b.cost;
    }
};

int dijkstra(int s, int e)
{
    for(int i = 0; i < 1001; i++) {
        dis[i] = INT_MAX / 2;
    }
    priority_queue<node, vector<node>, sorting> pq;
    dis[s] = 0;
    pq.push({s, 0});

    while(!pq.empty()) {
        int here = pq.top().to;
        int cost = pq.top().cost;
        pq.pop();


        for(int i = 0; i < road[here].size(); i++) {
            int there = road[here][i].to;
            int next_cost = cost + road[here][i].cost;

            if(next_cost < dis[there]) {
                dis[there] = next_cost;
                pq.push({there, next_cost});
            }
        }
    }

    return dis[e];

}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &N, &M, &X);


    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        road[a].push_back({b, c});
    }

    int res = -1;

    for(int i = 1; i <= N; i++) {

        res = max(res, (dijkstra(i, X) + dijkstra(X, i)));
    }

    printf("%d",res);


    return 0;
}
