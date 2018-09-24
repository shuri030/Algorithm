#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int num[1005];
int N, L;

int main(void)
{
	int cnt = 0, tmp;

	scanf("%d %d", &N, &L);
	for(int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + N);
	tmp = 0;

	for(int i = 0; i < N; i++) {
		if(num[i] - num[tmp] <= L - 1) {
			continue;
		}
		cnt++;
		tmp = i;
	}
	printf("%d", cnt + 1);
	return 0;
}
