#include <iostream>
#include <stdio.h>
using namespace std;

bool prime[1002];

bool is_prime(int num)
{
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

    for(int i = 2; i <= 1000; i++) {
        if(is_prime(i)) {
            for(int j = 2; j <= 500; j++) {
                if(i * j > 1000) { break; }
                prime[i * j] = false;
            }
            prime[i] = true;
        }
        else {
            prime[i] = false;
        }
    }


    for(int i = 1; i <= N; i++) {
        scanf("%d", &number);
        if(prime[number]) {
            cnt++;
        }
    }

    printf("%d", cnt);
}
