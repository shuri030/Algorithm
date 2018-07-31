#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;

char word[55][55];
char ans[55];

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        scanf("%s", word[i]);
    }
    
    for(int i = 0; i < strlen(word[0]); i++) {
        ans[i] = word[0][i];
    }

    
    for(int i = 0; i < strlen(word[0]); i++) {
        for(int j = 0; j < N - 1; j++) {
            if(word[j][i] != word[j + 1][i]) {
                ans[i] = '?';
                break;
            }
            else {
                ans[i] = word[j][i];
            }
        }
    }

    
    for(int i = 0; i < strlen(word[0]); i++) {
        printf("%c", ans[i]);
    }
    return 0;
}