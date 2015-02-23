#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int t;

	cin >> t;

	for ( int i = 0; i < t; i++ ) {
		long long int n;
		long long int m;

		cin >> n;
		cin >> m;

		long long int e1 = 2 * ( pow(2, n) - 1 );
		long long int e2 = 2 * ( pow(2, m) - 1 );

		cout << e1 - e2 << ".00" << endl;
	}

	return 0;
}


