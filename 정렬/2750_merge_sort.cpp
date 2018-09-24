// < 병합정렬 merge sort >
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int num[1002];
int sorted[1002];

void merge(int a[], int m, int mid, int n)
{
	int i = m;
	int j = mid + 1;
	int k = m;

	while(i <= mid && j <= n) {
		if(a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	//남은 데이터 삽입
	if(i > mid) {
		for(int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for(int t = i; t <= mid; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	// 정렬된 배열
	for(int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}
void mergeSort(int a[], int m, int n)
{
	if(m < n) {
		int mid = (m + n) / 2;
		mergeSort(a, m, mid);
		mergeSort(a, mid + 1, n);
		merge(a, m, mid, n);
	}
}

int main()
{	
	int N;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	mergeSort(num, 0, N - 1);
	for(int i = 0; i < N; i++) {
		printf("%d\n", num[i]);
	}
	
    return 0;
}