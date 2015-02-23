#include <stdio.h>

long long int move(int /* no of discs */, int /*from */, int /*to */, int /* via */ );
int main()
{
	int n;
	
	scanf("%d", &n);
	
	int arr[n];
	int i;
		
	for (  i = 0; i < n; i++ ) {
		scanf("%d", &arr[i]);
	}
	
	for (  i = 0; i < n; i++ ) {
		printf("%lld\n", move( arr[i], 1, 3, 2) );
	}

	return 0;
}

long long int move( int n, int a, int c, int b ) 
{
	long long int num = 0;
	if ( n == 1 && ( a != 2 && c != 2 ) ) {
		return 2;
	} else if ( n == 1 ) {
		return 1;
	}
		
	num += 2;
	num += 3 * move( n -1, a, c, b );

	return num;
}
