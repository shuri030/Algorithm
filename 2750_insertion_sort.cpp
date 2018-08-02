// < 삽입정렬 insertion sort >
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int num[1002];

int main()
{	
	int N;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	int tmp, j;
	//특정한 위치에 삽입(필요할때만), 이미 정렬 된 배열은 빠르게 정렬가능
	for(int i = 0; i < N; i++) {
		j = i;
		while(j > 0 && num[j - 1] > num[j]) {
			tmp = num[j - 1];
			num[j - 1] = num[j];
			num[j] = tmp;
			j--;
		}
	}

	for(int i = 0; i < N; i++) {
		printf("%d\n", num[i]);
	}
	
    return 0;
}