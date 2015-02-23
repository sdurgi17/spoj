#include <iostream>
#include <vector>

using namespace std;
long long int mod = 1000000007;

void multiply(long long int a[][2], long long int b[][2], long long int c[][2] );
void power_n( long long int a[][2], long long int c[][2], long long int n );

int main() 
{
	int t;
	cin >> t;

	long long int a[2][2] = { 1, 1, 1, 0 };
	long long int c[2][2];

	for ( int i = 0; i < t; i++ ) {
		long long int n;
		cin >> n;
		
		power_n(a, c, n + 1);
		long long int fn = c[0][1] % mod;
		long long int fn1 = c[0][0] % mod;
		
		long long int sol = ( fn * fn1 ) % mod;
		cout << "$" << sol - 1 << endl;
	}
	
	return 0;
}

void multiply( long long int a[][2], long long int b[][2], long long int c[][2] ) {

	long long int d[2][2], e[2][2];
	
	for ( int i = 0; i < 2; i++ ) {
		for ( int j = 0; j < 2; j++ ) {
			
			e[i][j] = b[i][j];
			d[i][j] = a[i][j];
		}
	}

	for ( int i = 0; i < 2; i++ ) {
		for ( int j = 0; j < 2; j++ ) {
			int sum = 0;
			for ( int k = 0; k < 2; k++ ) {
				sum = ( ( sum % mod ) + ( d[i][k] * e[k][j] ) % mod );
			}
			c[i][j] = sum % mod ;
		}
	}
}

void power_n( long long int arr[][2], long long int sol[][2], long long int n ) {
	
	if ( n == 1 ) {
		sol[0][0] = arr[0][0];
		sol[0][1] = arr[0][1];
		sol[1][0] = arr[1][0];
		sol[1][1] = arr[1][1];

		return;
	}

	if ( n == 2 ) {
		multiply( arr, arr, sol );
		return;
	}
	else if ( n % 2 == 0 ) {
		power_n( arr, sol, n/2 );
		multiply( sol, sol, sol);
	} else {
		power_n(arr, sol, n - 1);
		multiply(arr, sol, sol );
	}

	return;
}
