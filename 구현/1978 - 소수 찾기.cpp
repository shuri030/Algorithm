#include <iostream>
#include <stdio.h>
using namespace std;

bool is_prime(int num)
{
    if(num == 1) { return false; }

    for(int i = 2; i < num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int N, number, cnt = 0;
    scanf("%d", &N);


    for(int i = 1; i <= N; i++) {
        scanf("%d", &number);
        if(is_prime(number)) {
            cnt++;
        }
    }

    printf("%d", cnt);
}
