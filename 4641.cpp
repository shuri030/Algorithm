#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{	
	int n, d, cnt = 0;

	while(1) {
		while(1) {
			scanf("%d", &n);
			if(n == -1) { return 0; }
			else if(n != 0) {v.push_back(n); }
			else { break; }
		}

		for(int i = 0; i < v.size(); i++) {
			d = v[i] * 2;
			for(int j = 0; j < v.size(); j++) {
				if(d == v[j]) {
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
		v.clear();
		cnt = 0;
	}
    return 0;
}