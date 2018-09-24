#include <iostream>

using namespace std;

int main()
{
	int n;
	int cnt = 0;
	int a, b, c;

	cin >> n;
	
	for(int i = 1; i <= n; i++) {

		if(i >= 1 && i <= 99) {
			cnt++;
		}
		else if(i == 1000) {
			break;
		}
		else {
			a = i % 1000 / 100;
			b = i % 100 / 10;
			c = i % 10;

			if(a - b == b - c)
				cnt++;
		}
		
	}
	printf("%d", cnt);
	return 0;
}
