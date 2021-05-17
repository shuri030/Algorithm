#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
int result[50][10];
int players[15];
int ground[4];
int flag[15];
void init();
void make_order(int k);
void inning();
int max_score = 0;

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &result[i][j]);
        }
    }
    init();
    // 순서 생성
    make_order(1);
    printf("%d\n", max_score);

    return 0;
}
void init()
{
    for(int i = 0; i < 4; i++) {
        ground[i] = 0;
    }
}
void make_order(int k) //k번쨰
{
    if(k >= 10) {
//        for(int i = 1; i <= 9; i++) {
//            printf("%d ", players[i]);
//        }
//        printf("\n");
//
        inning();
        return;
    }

    if(k == 4) {
        players[k] = 0;
        make_order(k + 1);
    }

    else {
        for(int i = 1; i <= 8; i++) {
            if(flag[i] == 0) {
                players[k] = i;
                flag[i] = 1;
                make_order(k + 1);
                flag[i] = 0;
            }
        }
    }

}
void inning() {
    int turn = 1; int score = 0;

    for(int i = 0; i < N; i++) { //이닝 돌기
        int out = 0, rr = 0;
        init(); // 그라운드 비워

        while(out < 3) {
            rr = result[i][players[turn]];

            if(rr == 0) { // 아웃
                out++;
            }
            else if(rr == 1) { // 안타
                for(int k = 3; k >= 1; k--) {
                    if(k == 3) {
                        if(ground[k] == 1) { //홈으로 갈차례면
                            ground[k] = 0; score++; //자리비우고 점수++
                        }
                    }
                    else {
                        if(ground[k] == 1) { //누가있으면 전진
                            ground[k] = 0; ground[k + 1] = 1; //자리비우고 전진
                        }
                    }
                }
                ground[1] = 1; // 타자
            }
            else if(rr == 2) { // 2루
                for(int k = 3; k >= 1; k--) {
                    if(k == 3 || k == 2) {
                        if(ground[k] == 1) { //홈으로 갈차례면
                            ground[k] = 0; score++; //자리비우고 점수++
                        }
                    }
                    else {
                        if(ground[k] == 1) { //누가있으면 전진
                            ground[k] = 0; ground[k + 2] = 1; //자리비우고 전진
                        }
                    }
                }
                ground[2] = 1; // 타자
            }
            else if(rr == 3) { // 3루
                for(int k = 3; k >= 1; k--) {
                    if(ground[k] == 1) {
                        ground[k] = 0; score++; //자리비우고 점수++
                    }
                }
                ground[3] = 1;
            }
            else if(rr == 4) { // 홈런
                for(int k = 3; k >= 1; k--) {
                    if(ground[k] == 1) {
                        ground[k] = 0; score++; //자리비우고 점수++
                    }
                }
                ground[0] = 0; score++;
            }
            turn++;
            if(turn == 10) {
                turn = 1;
            }//다시 1
        }
    }

    if(score >= max_score) {
        max_score = score;
    }
}
