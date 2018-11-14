#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

    int T;
    int A, B;
    scanf("%d", &T);


    for(int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &A, &B);
        printf("%d\n", A + B);
    }

}
