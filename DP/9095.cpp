#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
/*
Bottom-Up 방식 사용
작은 문제부터 풀고 큰 문제를 풀어나가는 방식(for문 사용)
*/

int num[11]; //num[n]은 1,2,3을 이용해서 n을 만들수 있는 방식의 갯

int main()
{
    int tc, n;
    //규칙 이용
    num[1] = 1;
    num[2] = 2;
    num[3] = 4;

    for(int i = 4; i < 11; i++) {
        num[i] = num[i - 1] + num[i - 2] + num[i - 3];
    }

    scanf("%d", &tc);

    for(int i = 0; i < tc; i++) {
        scanf("%d", &n);
        printf("%d\n", num[n]);
    }

    return 0;
}
