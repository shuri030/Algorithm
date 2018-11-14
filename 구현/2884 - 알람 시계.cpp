#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

    int H, M;
    scanf("%d %d", &H, &M);

    if(M >= 45) {
        printf("%d %d\n", H, M - 45);
    }
    else {
        if(H >= 1)
            printf("%d %d\n", H - 1, 60 - (45 - M));
        else {
            printf("%d %d\n", 23, 60 - (45 - M));
        }
    }


}
