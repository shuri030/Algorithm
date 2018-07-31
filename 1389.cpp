#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm> 
#include <limits.h>
using namespace std;

vector<int> user[110];
int visit[110];
int check[110];

int n, m;
int a, b;

int BFS(int num) 
{
	int cnt = 0;
	visit[num] = 0;
	check[num] = 1;
	queue<int> q;
	q.push(num);

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for(int j = 0; j < user[cur].size(); j++) {
			if(visit[user[cur][j]] > visit[cur] + 1 && check[user[cur][j]] == 0) {
				visit[user[cur][j]] = visit[cur] + 1;
				check[user[cur][j]] = 1;
				q.push(user[cur][j]);
			}
		}
	}

	//케빈베이컨 수
	for(int i = 1; i <= n; i++) {
		cnt = cnt + visit[i];
	}

	return cnt;

}
//visit 초기화
void init() {

	for(int i = 1; i <= n; i++) {
		visit[i] = INT_MAX / 2;

	}

	for(int i = 1; i <= n; i++) {
		check[i] = 0;

	}


}
int main() 
{
	

	scanf("%d %d", &n, &m);

	//친구관계 만들기
	for(int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);

		user[a].push_back(b);
		user[b].push_back(a);
	}

	
	int count = 0, answer;
	int ans = INT_MAX / 2;

	for(int i = 1; i <= n; i++) {
		init(); //visit 초기화

		count = BFS(i);

		if(count < ans) {
			ans = count;
			answer = i;
		}
	}

	printf("%d", answer);
	
}
