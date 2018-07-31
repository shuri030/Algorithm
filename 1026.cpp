#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>

using namespace std;

int A[55];
int B[55];

int main()
{
	int n, answer = 0;
	scanf("%d", &n);

	//A배열 입력
	for(int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	//B배열 입력
	for(int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
	}

	sort(A, A + n); //퀵 정렬
	sort(B, B + n, greater<int>()); //greater는 functional 헤더에 들어있다.(내림차순)

	for(int i = 0; i < n; i++) {
		answer = answer + A[i] * B[i];
	}

	printf("%d\n", answer);

}
