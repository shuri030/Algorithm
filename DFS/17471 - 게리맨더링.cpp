#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
int people[15]; //인구수
int team[15]; //팀을 정할 배열
int visit[15]; // 방문체크
vector<int> area[15]; //연결리스트
int ans = 12345678;
bool check = false;
int check_cnt;

void make_team(int start, int n, int c); //팀을 짜자
bool is_connected(int k, int tt, int com); //연결되어있나 DFS

int main()
{
    int num;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &people[i]);
    }

    for(int i = 1; i <= N; i++) {
        scanf("%d", &M);

        for(int j = 1; j <= M; j++) {
            scanf("%d", &num);
            area[i].push_back(num);
            area[num].push_back(i);
        }
    }

    for(int i = 1; i <= N; i++) {
        team[i] = 1;
        for(int j = 1; j <= (N - 1); j++) {
            make_team(i, j, 1); // 1명부터 N-1명까지 돌려보자
        }
        team[i] = 0;
    }

    if(ans == 12345678) {
        printf("-1\n");
    }
    else {
        printf("%d", ans);
    }

}
void make_team(int start, int n, int c) // 시작점, 목표 명수, 현재 명수
{
    if(c == n) {
        int flag1 = 0, flag2 = 0; int team2 = 0;
        for(int k = 1; k <= N; k++) {
            if(team[k] == 0) {
                team2 = k;
                break;
            }
        }

        for(int i = 1; i <= N; i++) { visit[i] = 0; } check = false; check_cnt = 0;
        flag1 = is_connected(start, 1, n); // 팀1 연결되어있나?
        for(int i = 1; i <= N; i++) { visit[i] = 0; } check = false; check_cnt = 0;
        flag2 = is_connected(team2, 0, N - n); // 팀2 연결되어있나?


        if(flag1 == false || flag2 == false) {
            return;
        }
        else {
            //두개의 팀이 둘다 연결된 구역이면 명수 차이 구하기
            int sum1 = 0, sum2 = 0;
            for(int k = 1; k <= N; k++) {
                if(team[k] == 1) {
                    sum1 += people[k];
                }
                else {
                    sum2 += people[k];
                }
            }

            if(ans > abs(sum1 - sum2)) {
                ans = abs(sum1 - sum2);
            }
        }
        return;
    }

    for(int i = start; i <= N; i++) {
        if(team[i] == 0) {
            team[i] = 1;
            make_team(i, n, c + 1);
            team[i] = 0;
        }
    }
}
bool is_connected(int k, int tt, int com) //지금 값, 팀 구별 값, 전체 카운트
{
    //DFS
    check_cnt++;
    visit[k] = 1;

    if(com == check_cnt) {
        check = true;
        return check;
    }

    for(int i = 0; i < area[k].size(); i++) {
        if((team[area[k][i]] == tt) && (visit[area[k][i]] == 0)) {
            is_connected(area[k][i], tt, com);
        }

        if(check == true) {
            return check;
        }
    }

    return check;
}
