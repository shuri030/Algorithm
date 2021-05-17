#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int N, M, K;
int A[53][53];
int min_num = 98765432;

struct ro_info {
    int r;
    int c;
    int s;
};
vector <ro_info> r_info;

int turn[8];

void copy(int temp_A[53][53], int temp_B[53][53]);
void rotation_order(int tA[53][53], int n);
void rotate_Array(int temp[53][53], int kk);
void print(int temp[53][53]);

int main()
{
    int t_sum = 0;

    scanf("%d %d %d", &N, &M, &K);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // 회전하지 않은 상태에서 최소값을 구하면 안된다.. 괜히 꼼꼼하게 하려다 틀림

    int rr, cc, ss;
    for(int k = 0; k < K; k++) {
        scanf("%d %d %d", &rr, &cc, &ss);
        r_info.push_back({rr, cc, ss});
    }

    rotation_order(A, 0);

    printf("%d\n", min_num);
    return 0;
}
void print(int temp[53][53])
{
    printf("\n");
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            printf("%2d" ,temp[i][j]);
        }
        printf("\n");
    }
}
void copy(int temp_A[53][53], int temp_B[53][53])
{
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            temp_A[i][j] = temp_B[i][j];
        }
    }
}
void rotation_order(int tA[53][53], int n)
{
    if(n >= K) {
        // 최소값 구하기
        int t_sum = 0;
        for(int i = 1; i <= N; i++) {
            t_sum = 0;
            for(int j = 1; j <= M; j++) {
                t_sum += tA[i][j];
            }
            if(t_sum < min_num) { min_num = t_sum; }
        }
        return;
    }

    // 임시 배열
    int tmp[53][53] = {0, };
    copy(tmp, tA);


    for(int k = 0; k < K; k++) {
        if(turn[k] == 0) {
            turn[k] = 1;

            //k번째 회전 정보로 회전
            rotate_Array(tmp, k);
//            printf("%d=\n ", k);
//            print(tmp);
            // 다음
            rotation_order(tmp, n + 1);
            turn[k] = 0;
            copy(tmp, tA);
        }
    }
}
void rotate_Array(int temp[53][53], int kk)
{
    int arr[53][53] = {0, };
    int sr = r_info[kk].r - r_info[kk].s;
    int sc = r_info[kk].c - r_info[kk].s;
    int er = r_info[kk].r + r_info[kk].s;
    int ec = r_info[kk].c + r_info[kk].s;
    int ss = r_info[kk].s;

    copy(arr, temp);

    while(ss > 0) {
        for(int cc = sc + 1; cc <= ec; cc++) {
            arr[sr][cc] = temp[sr][cc - 1];
        }

        for(int rr = sr + 1; rr <= er; rr++) {
            arr[rr][ec] = temp[rr - 1][ec];
        }

        for(int cc = sc; cc <= ec - 1; cc++) {
            arr[er][cc] = temp[er][cc + 1];
        }

        for(int rr = sr; rr <= er - 1; rr++) {
            arr[rr][sc] = temp[rr + 1][sc];
        }
        sr++; sc++; er--; ec--;
        ss--;
    }

    copy(temp, arr);
}
