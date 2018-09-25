#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int num[7] = {1000000, 100000, 10000, 1000, 100, 10, 1};
    int num_set[10] = {0, };
    int N;

    int i = 0, cal = 0, ans = 1;
    scanf("%d", &N);

    while(i < 7) {
        if(N / num[i] > 0) {
            break;
        }
        i++;
    }

    for(int k = i; k < 7; k++) {
        cal = N / num[k];
        if(cal != 6 && cal != 9) {
            num_set[cal]++;
            if(ans < num_set[cal]) { ans = num_set[cal]; }
        }
        else {
            if(num_set[6] < num_set[9]) {
                num_set[6]++;
                if(ans < num_set[6]) { ans = num_set[6]; }
            }
            else if(num_set[6] > num_set[9]) {
                num_set[9]++;
                if(ans < num_set[9]) { ans = num_set[9]; }
            }
            else {
                num_set[6]++;
                if(ans < num_set[6]) { ans = num_set[6]; }
            }
        }
        N = N % num[k];
    }

    printf("%d", ans);

    return 0;
}
