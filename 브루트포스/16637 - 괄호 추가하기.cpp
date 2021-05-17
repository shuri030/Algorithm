#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <limits.h>
#include <algorithm>
using namespace std;

int n;
char formular[22];
bool check[11];
int op_n;

int ans = -INT_MAX;

void show()
{
    for(int i = 0; i < op_n; i++) {
        printf("%d ", check[i]);
    }
    printf("\n");
}
int cal(string a, string op, string b)
{
    if(op == "+") {
        return stoi(a) + stoi(b);
    }
    else if(op == "-") {
        return stoi(a) - stoi(b);
    }
    else if(op == "*") {
        return stoi(a) * stoi(b);
    }
    return 0;
}
int priority()
{
    int oi;
    string a, b, c, o;
    int sum;
    string num, op, num2;
    string ss;
    queue<string> q;
    bool flag = false;

    for(int i = 0; i < op_n; i++) {
        if(check[i]) flag = true;
    }

    if(!flag) {
        string temp;
        for(int i = 0; i < n; i++) {
            temp = formular[i];
            q.push(temp);
        }
    }
    else {
        for(int i = 0; i < op_n; i++) {
            oi = (i * 2) + 1; // 식에서 연산자의 원래 인덱스
            a = formular[oi - 1]; b = formular[oi]; c =  formular[oi + 1];
            if(check[i]) { // 괄호가 있는 연산자면
                ss = to_string(cal(a, b, c));
                q.push(ss); // 미리 계산해서 넣기
            }
            else { // 괄호가 없는 연산자면

                if(i == 0) { //맨 앞
                    q.push(a);
                    q.push(b);
                }
                else if(check[i - 1]) { // 앞 괄호가 있을때
                    if (i == op_n - 1) { // 맨 뒤 연산자일때
                        q.push(b);
                        q.push(c);
                    }
                    else {
                        q.push(b); // 본인만
                    }
                }
                else if(!check[i - 1]) { // 앞 괄호가 없을때
                    if (i == op_n - 1) { // 맨 뒤 연산자일때
                        q.push(a);
                        q.push(b);
                        q.push(c);
                    }
                    else {
                        q.push(a);
                        q.push(b);
                    }
                }
            }
        }
    }


    // 계산
    num = q.front(); q.pop();

    while(!q.empty()) {
        //printf("%d", num - '0');
        op = q.front(); q.pop();
        num2 = q.front(); q.pop();

        //printf(" %c %d\n", op, num2 - '0');
        num = to_string(cal(num, op, num2));

    }

    sum = stoi(num);
    return sum;
}
void add_bracket(int index)
{
    int tmp = -INT_MAX;

    if(index >= op_n) {
        // 계산
        //show();
        tmp = priority();
        if(ans < tmp) {
            ans = tmp;
        }
        return;
    }

    //계산
    //show();
    tmp = priority();
    if(ans < tmp) {
        ans = tmp;
    }

    for(int i = index; i < op_n; i++) {
        if(!check[i]) { // 괄호 둔곳이 아니면
            check[i] = true; // 괄호 두고
            add_bracket(i + 2);
            check[i] = false;
        }
    }
}


int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf(" %c", &formular[i]);
    }

    op_n = (int)(n / 2);

    add_bracket(0);

    printf("%d", ans);
    return 0;
}
