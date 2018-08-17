//
//  11726 - 2xn 타일링.cpp
//  algoalgo
//
//  Created by JoHanseul on 2018. 8. 17
//  Copyright © 2018년 JoHanseul. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1001]; //2*i의 사각형을 채울 수 있는 방법의 수
//bottom-up

int main() {

    int n;

    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= 1000; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    scanf("%d", &n);
    printf("%d", dp[n]);

    return 0;
}
