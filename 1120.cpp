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