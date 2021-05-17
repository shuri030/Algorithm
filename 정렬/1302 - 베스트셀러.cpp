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
vector<string> subject;
vector<string> cmp;
int cnt[1000];
int flag, ans;

int main()
{
    char book[55];
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%s", book);
        for(int j = 0; j < subject.size(); j++) {
            if(book == subject[j]) {
                cnt[j]++;
                if(ans < cnt[j]) {
                    ans = cnt[j];
                }
                flag = 1;
            }
        }
        if(flag == 0) {
            subject.push_back(book);
        }
        book[0] = '\0';
        flag = 0;
    }

    for(int i = 0; i < subject.size(); i++) {
        if(cnt[i] == ans) {
            cmp.push_back(subject[i]);
        }
    }

    sort(cmp.begin(), cmp.end());

    cout << cmp[0] << "\n";
}
