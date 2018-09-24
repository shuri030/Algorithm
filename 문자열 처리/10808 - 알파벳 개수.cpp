#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;


int main()
{
    int alpha[27] = {0, };
    char word[105];
    scanf("%s", word);

    for(int i = 0; i < strlen(word); i++) {
        alpha[word[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        printf("%d ", alpha[i]);
    }


    return 0;
}
