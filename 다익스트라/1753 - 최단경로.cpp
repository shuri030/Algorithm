#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <functional>

using namespace std;

typedef struct node {
    int to;
    int cost;
}node;

int V, E, K;
int u, v, w;
vector<node> n[20002];

struct sorting {
    int operator() (node a, node b) {
        return a.cost > b.cost;
    }
};
void dijkstra(int k)
{
    priority_queue<node, vector<node>, sorting> pq;
    vector<int> ans(V+1,INT_MAX / 2);
    ans[k] = 0;
    pq.push({k, 0});

    while(!pq.empty()) {
        int here = pq.top().to;
        int cost = pq.top().cost;
        pq.pop();

        if(cost > ans[here]) { continue; }

        int there, next_cost;

        for(int i = 0; i < n[here].size(); i++) {
            there = n[here][i].to;
            next_cost = cost + n[here][i].cost;
            if(next_cost < ans[there]) {
                ans[there] = next_cost;
                pq.push({there, next_cost});
            }
        }

    }

    for(int i = 1; i <= V; i++) {
        if(ans[i] == INT_MAX / 2) {
            printf("INF\n");
        }
        else {
            printf("%d\n", ans[i]);
        }
    }


}

int main()
{

    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    for(int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        n[u].push_back(node{v,w});
    }

    dijkstra(K);

    return 0;
}
