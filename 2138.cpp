#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int cur[100001];
int fin[100001];
int tmp[100001];
int d[3] = {-1, 0, 1};
int ans = 100000;

void go(int *t, int n, int cnt)
{
	if(n == N) {
		if((t[n] == fin[n]) && (t[n - 1] == fin[n - 1])) {
			ans = min(ans, cnt);
		}
		for(int k = 0; k < 3; k++) {
			if(n + d[k] >= 1 && n + d[k] <= N) {
				if(t[n + d[k]] == 0) { t[n + d[k]] = 1; }
				else if(t[n + d[k]] == 1) { t[n + d[k]] = 0; }
			}
		}
		if((t[n] == fin[n]) && (t[n - 1] == fin[n - 1])) {
			ans = min(ans, cnt + 1);
		}
		return;
	}
	//현재 안누를거
	if(t[n - 1] == fin[n - 1]) {
		go(t, n + 1, cnt);
	}

	//현재 누를거
	for(int k = 0; k < 3; k++) {
		if(n + d[k] >= 1 && n + d[k] <= N) {
			if(t[n + d[k]] == 0) { t[n + d[k]] = 1; }
			else if(t[n + d[k]] == 1) { t[n + d[k]] = 0; }
		}
	}

	if(t[n - 1] == fin[n - 1]) {
		go(t, n + 1, cnt + 1);
	}
}
int main()
{
	int a = 1;
	scanf("%d", &N);

	for(int i = 1; i <= N; i++) {
		scanf("%1d", &cur[i]);
		tmp[i] = cur[i];
	}

	for(int i = 1; i <= N; i++) {
		scanf("%1d", &fin[i]);
	}

	//1번 안누르기
	go(cur, 2, 0);

	//1번 누르기
	for(int i = 1; i <= 2; i++) {
		if(tmp[i] == 0) { tmp[i] = 1; }
		else { tmp[i] = 0; }
	}

	go(tmp, 2, 1);
	
	if(ans == 100000) {
		printf("-1");
	}
	else {
		printf("%d", ans);
	}
	
	return 0;
}