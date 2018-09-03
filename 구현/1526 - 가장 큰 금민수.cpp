#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int number[2] = {7, 4};
int mul[6] = {100000, 10000, 1000, 100, 10, 1};
int N;
vector<int> ans;

void go(int s, int sum)
{
    if(s > 5) {
        //printf("%d ", sum);
        ans.push_back(sum);
        return;
    }


    for(int i = 0; i < 2; i++) {
        go(s + 1, sum + mul[s] * number[i]);
    }

}
int main()
{
    scanf("%d", &N);

    for(int i = 0; i < 6; i++) {
        go(i, 0);
    }

    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] <= N) {
            printf("%d", ans[i]);
            return 0;
        }
    }

    return 0;
}
