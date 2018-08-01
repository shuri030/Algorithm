#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm> 
using namespace std;

int visit[10000];
int check[10000];

int prime[10000]; 

int start, want;
int flag = 0;
int ans = 0;
int a, b, c, d, n;

bool isPrime(int num) {
	for(int i = 2; i < num; i++) {
		if(num % i == 0)
			return false;
	}
	return true;
}

void BFS(int start) {
	
	ans = 0;
	flag = 0;

	check[start] = 1;
	queue<int> q;
	q.push(start);

	while(!q.empty()) {
		int cur = q.front();
		q.pop(); 

		if(cur == want) {
			ans = visit[cur];
			check[cur] = 1;
			flag = 1;
			break;

		}
	
		n = cur;

		a = n / 1000; //1000의 자리
		n = n % 1000;

		b = n / 100; //100의 자리
		n = n % 100;

		c = n / 10; //10의 자리
		d = n % 10; //1의 자리


		//1의 자리 
		for(int i = 0; i < 10; i++) {
			int num = (a * 1000) + (b * 100) + (c * 10) + i;

			if(prime[num] == 1 && check[num] == 0) { 
				q.push(num);
				visit[num] = visit[cur] + 1;
				check[num] = 1;
			}
		}

		//10의 자리
		for(int i = 0; i < 10; i++) {
			int num = (a * 1000) + (b * 100) + (i * 10) + d;
		
			if(prime[num] == 1 && check[num] == 0) { 
				q.push(num);
				visit[num] = visit[cur] + 1;
				check[num] = 1;
				
			}
		}

		//100의 자리
		for(int i = 0; i < 10; i++) {
			int num = (a * 1000) + (i * 100) + (c * 10) + d;
			
			if(prime[num] == 1 && check[num] == 0) { 
				q.push(num);
				visit[num] = visit[cur] + 1;
				check[num] = 1;
				
			}
		}
		//1000의 자리
		for(int i = 1; i < 10; i++) {
			int num = (i * 1000) + (b * 100) + (c * 10) + d;
			
			if(prime[num] == 1 && check[num] == 0) { 
				q.push(num);
				visit[num] = visit[cur] + 1;
				check[num] = 1;
				
			}
		}

	
	}


}
int main() 
{
	int T;
	cin >> T;

	//소수 구하기(1000~9999)
	for(int i = 2; i <= 10000; i++) {
		if(isPrime(i)) {
			prime[i] = 1;

		}
	}

	//입력받기
	for(int k = 0; k < T; k++) {
		scanf("%d %d", &start, &want);
		
		memset(check, 0, sizeof(check));
		memset(visit, 0, sizeof(visit));

		BFS(start);

		if(flag == 1)
			printf("%d\n", ans);
		else
			printf("Impossible\n");
	}



}
