#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;

int T, n;
int student[100002];
int is_team[100002];
bool check[100002];

int start;
bool is_connect = false;
int cnt = 0;
vector<int> ans;

void make_team(int n)
{
    int num = n;
    while(is_team[num] == 0) {
        is_team[num] = 1;
        num = student[num];
    }

    num = student[start];

    while(check[num] == true) {
        check[num] = false;
        if(is_team[num] == 0) {
            is_team[num] = -1;
        }
        num = student[num];
    }

}

void choose(int num)
{
    check[num] = true;

    if(start == num) {
        make_team(num);
        is_connect = true;
        return;
    }

    if(check[student[num]]) {
        make_team(student[num]);
        return;
    }
    else {
        choose(student[num]);
    }

}
int main()
{
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        scanf("%d", &n);

        for(int j = 1; j <= n; j++) {
            scanf("%d", &student[j]);
        }

        for(int j = 1; j <= n; j++) {
            if(is_team[j] == 0) {
                if(is_team[student[j]] == -1 || is_team[student[j]] == 1) {
                    is_team[j] = -1;
                    continue;
                }
                start = j; is_connect = false;
                choose(student[j]);

                if(!is_connect) { is_team[start] = -1; }
                else {  is_team[start] = 1; }
            }
        }
        
        for(int j = 1; j <= n; j++) {
            if(is_team[j] == -1) { cnt++; }
            is_team[j] = 0;
        }
        ans.push_back(cnt);
        cnt = 0;
    }

    for(int i = 0; i < T; i++) {
        printf("%d\n", ans[i]);
    }


    return 0;
}
