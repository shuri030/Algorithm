#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int N, a, b;
    scanf("%d %d %d", &N, &a, &b);
    
    int play = ceil(log2(N)); //사람이 N명일때, 총 경기수
    int answer = 0;
    
    for(int i = 1; i <= play; i++) {
        
        int round = pow(2, i);
        if ((a - 1)/round == (b - 1)/round) { // 같이 경기하면
            answer = i;
            break;
        }
    }
    
    printf("%d", answer);
    
    return 0;
}