#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.H>
#include <algorithm>
using namespace std;

int main()
{
    char long_name[102];
    vector<char> ans;

    scanf("%s", long_name);

    for(int i = 0; i < strlen(long_name); i++) {
        if(long_name[i] >= 65 && long_name[i] <= 90) {
            ans.push_back(long_name[i]);
        }
    }

    for(int i = 0; i < ans.size(); i++) {
        printf("%c", ans[i]);
    }

    return 0;
}
