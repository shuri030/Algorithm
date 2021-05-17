#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int N;
int board[22][22];
int max_n;

void move(int block[22][22], int n);
void init(int t[22][22], int b[22][22]);
void up(int temp[22][22]);
void left(int temp[22][22]);
void down(int temp[22][22]);
void right(int temp[22][22]);

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
            if(board[i][j] > max_n) { max_n = board[i][j]; } //최대값
        }
    }
    move(board, 0); // DFS

    printf("%d\n", max_n);

    return 0;
}
void init(int t[22][22], int b[22][22])
{
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            t[i][j] = b[i][j];
        }
    }
}
void move(int block[22][22], int n)
{
    if(n >= 5) {
        return;
    }

    int temp[22][22] = {0, };
    init(temp, block);

    //up
    up(temp);
    move(temp, n + 1);
    init(temp, block);

    //left
    left(temp);
    move(temp, n + 1);
    init(temp, block);

    //down
    down(temp);
    move(temp, n + 1);
    init(temp, block);

    //right
    right(temp);
    move(temp, n + 1);
    init(temp, block);
}
void up(int temp[22][22])
{
    int B[22][22] = {0, };
    vector<int> num;

    for(int j = 0; j < N; j++) {
        for(int i = 0; i < N; i++) {
            if(temp[i][j] != 0) { //같을때(위,아래)
                num.push_back(temp[i][j]);
            }
        }
        int nsize = (int)num.size();
        if(nsize == 1) {
            B[0][j] = num[0];
        }
        else if(nsize > 1) {
            int k = 0; int bi = 0;
            while(k < (nsize - 1)) {
                if(num[k] == num[k + 1]) { // 같을 때
                    B[bi][j] = num[k] + num[k + 1];
                    if(B[bi][j] > max_n) { max_n = B[bi][j]; }
                    k= k + 2; bi++;

                }
                else {
                    B[bi][j] = num[k];
                    k++; bi++;
                }
                if(k == (nsize - 1)) {
                    B[bi][j] = num[k];
                    break;
                }
            }
        }
        num.clear();
    }
    init(temp, B);
}
void left(int temp[22][22])
{
    int B[22][22] = {0, };
    vector<int> num;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(temp[i][j] != 0) { //같을때(위,아래)
                num.push_back(temp[i][j]);
            }
        }
        int nsize = (int)num.size();
        if(nsize == 1) {
            B[i][0] = num[0];
        }
        else if(nsize > 1) {
            int k = 0; int bj = 0;
            while(k < (nsize - 1)) {
                if(num[k] == num[k + 1]) { // 같을 때
                    B[i][bj] = num[k] + num[k + 1];
                    if(B[i][bj] > max_n) { max_n = B[i][bj]; }
                    k= k + 2; bj++;

                }
                else {
                    B[i][bj] = num[k];
                    k++; bj++;
                }
                if(k == (nsize - 1)) {
                    B[i][bj] = num[k];
                    break;
                }
            }
        }
        num.clear();
    }
    init(temp, B);
}
void down(int temp[22][22])
{
    int B[22][22] = {0, };
    vector<int> num;

    for(int j = 0; j < N; j++) {
        for(int i = N - 1; i >= 0; i--) {
            if(temp[i][j] != 0) { //같을때(아래, 위)
                num.push_back(temp[i][j]);
            }
        }

        int nsize = (int)num.size();
        if(nsize == 1) {
            B[N - 1][j] = num[0];
        }
        else if(nsize > 1) {
            int k = 0; int bi = N - 1;
            while(k < (nsize - 1)) {
                if(num[k] == num[k + 1]) { // 같을 때
                    B[bi][j] = num[k] + num[k + 1];
                    if(B[bi][j] > max_n) { max_n = B[bi][j]; }
                    k= k + 2; bi--;

                }
                else {
                    B[bi][j] = num[k];
                    k++; bi--;
                }
                if(k == (nsize - 1)) {
                    B[bi][j] = num[k];
                    break;
                }
            }
        }
        num.clear();
    }
    init(temp, B);
}
void right(int temp[22][22])
{
    int B[22][22] = {0, };
    vector<int> num;

    for(int i = 0; i < N; i++) {
        for(int j = N; j >= 0; j--) {
            if(temp[i][j] != 0) { //같을때(위,아래)
                num.push_back(temp[i][j]);
            }
        }
        int nsize = (int)num.size();
        if(nsize == 1) {
            B[i][N - 1] = num[0];
        }
        else if(nsize > 1) {
            int k = 0; int bj = N - 1;
            while(k < (nsize - 1)) {
                if(num[k] == num[k + 1]) { // 같을 때
                    B[i][bj] = num[k] + num[k + 1];
                    if(B[i][bj] > max_n) { max_n = B[i][bj]; }
                    k= k + 2; bj--;

                }
                else {
                    B[i][bj] = num[k];
                    k++; bj--;
                }
                if(k == (nsize - 1)) {
                    B[i][bj] = num[k];
                    break;
                }
            }
        }
        num.clear();
    }
    init(temp, B);
}
