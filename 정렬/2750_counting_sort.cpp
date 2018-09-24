// < 계수 정렬 counting sort >
#include <stdio.h>
#include <iostream>
using namespace std;

int c[10000];

int main()
{	
	int N, num;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &num);
		c[num - 1]++;
	}

	for(int i = 0; i < 10000; i++) {
		if(c[i] != 0) {
			for(int j = 0; j < c[i]; j++) {
				printf("%d\n", i + 1);
			}
		}
	}
	
    return 0;
}