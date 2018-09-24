#include <stdio.h>
#include <iostream>
#include <algorithm>
#define N_MAX 1000003 //N은 10의 6승
using namespace std;

int dp[N_MAX];
/*
다이나믹 프로그래밍은 dp배열 정의가 중요.(모든 상태를 생각하며 정의) - memoization
여기서 dp배열은 결과가 dp[n]일때, n으로 만들어지기까지 몇 번 연산해야하는지 담는다.


사용한 방법은 재귀를 이용한 Top-Down 방식
 단계가 작은 문제부터 풀어나간다.
*/

void go(int n)
{
    if(n < 1) { //1보다 작아지면 되돌아간다.
        return;
    }

    //할 수 있는 계산들
    if(n % 3 == 0) {
        if(dp[n / 3] > dp[n] + 1) {
            dp[n / 3] = dp[n] + 1;
            go(n / 3);
        }
    }
    if(n % 2 == 0) {
        if(dp[n / 2] > dp[n] + 1) {
            dp[n / 2] = dp[n] + 1;
            go(n / 2);
        }
    }
    if(dp[n  - 1] > dp[n] + 1) {
        dp[n - 1] = dp[n] + 1;
        go(n - 1);
    }

    return;
}
void init()
{
    for(int i = 0; i < N_MAX; i++) {
        dp[i] = INT_MAX / 2;
    }
}
int main()
{
    int N;

    scanf("%d", &N);

    init(); //가장 적은 연산의 수를 구해야하니, 큰 수로 초기화시키고 시작한다.

    dp[N] = 0; //N이 되기까지의 연산의 수는 0
    go(N);

    printf("%d", dp[1]); //1로 만들어지기까지의 연산 횟수를 물었으니 dp[1] 출력


    return 0;
}
