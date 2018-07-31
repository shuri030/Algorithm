#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


char A[55];
char B[55];
char cmp[55];

int main()
{
	//A 의 시작점을 옮기면서 A 크기 만큼만 비교한다. 차이 개수가 가장 작은것이 답
    int ans = 100, start, cnt = 0;
    
    scanf("%s", A);
    scanf("%s", B);
    
    for(int i = 0; i <= (int)strlen(B) - (int)strlen(A); i++) {
        start = i;
        for(int j = 0; j < (int)strlen(A); j++) {
            if(B[start] != A[j]) { cnt++; }
            start++;
        }
        ans = min(ans, cnt);
        cnt = 0;
    }
    
    
    printf("%d", ans);
    return 0;
}