#include <stdio.h>

int main()
{
	long long int t;

	scanf("%lld", &t);

	int i;
	for ( i = 0; i < t; i++ ) {
		long long int h, sol;
		scanf("%lld", &h);

		sol = h * (h +1) / 6;
		
		printf("%lld", sol);
	}

	return 0;
}




