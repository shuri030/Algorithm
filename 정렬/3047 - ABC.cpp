#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int num[3];
char order[3];

int main()
{
    for(int i = 0; i < 3; i++) {
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < 3; i++) {
        scanf(" %1c", &order[i]);
    }

    sort(num, num + 3);

    for(int i = 0; i < 3; i++) {
        printf("%d ", num[order[i] - 65]);
    }
}
