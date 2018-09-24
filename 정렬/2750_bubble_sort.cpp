// < 버블정렬 bubble sort >
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

	int tmp;
	//옆 값이랑 비교해서 작은 값을 왼쪽으로 보낸다
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N - 1; j++) {
			if(num[j] > num[j + 1]) {
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}

	for(int i = 0; i < N; i++) {
		printf("%d\n", num[i]);
	}
	
    return 0;
}