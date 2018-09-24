#include <iostream>

using namespace std;

int a, b;
int a2 = 0, b2 = 0;

int change(int ab) {

	int n = 0;

	n = n + ab/100;
	ab = ab % 100;
	n = n + (ab/10) * 10;
	ab = ab % 10;
	n = n + ab * 100;

	return n;
}

int main()
{

	scanf("%d %d", &a, &b);

	a2 = change(a);
	b2 = change(b);

	if(a2 > b2)
		printf("%d", a2);
	else
		printf("%d", b2);

}
