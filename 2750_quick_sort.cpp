// 퀵 정렬 (quick sort)
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int num[1001];

void quicksort(int *num, int head, int tail)
{
	if(head >= tail) { // 길이가 1일때
		return;
	}

	int key = head;
	int i = head + 1;
	int j = tail, tmp;

	while(i <= j) { //엇갈릴 때 까지
		while(num[i] <= num[key]) { //키보다 큰 값찾을때까지
			i++;
		}
		while(num[j] >= num[key] && j > head) { //키보다 작은 값 찾을 때까지
			j--;
		}

		if(i > j) { //엇갈리면 키 값과 교체
			tmp = num[key];
			num[key] = num[j];
			num[j] = tmp;
		}
		else { //안 엇갈리면 i, j교체
			tmp = num[i];
			num[i] = num[j];
			num[j] = tmp;
		}
	}

	quicksort(num, head, j - 1);
	quicksort(num, j + 1, tail);

}

int main()
{	
	int N;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	quicksort(num, 0, N - 1);

	for(int i = 0; i < N; i++) {
		printf("%d\n", num[i]);
	}
	
    return 0;
}