#include <iostream>

using namespace std;

int arr[1000][1000];

int max_time(int H, int A) {

	if ( H <= 0 || A <= 0 ) {
		return 0;
	}

	if ( arr[H][A] != -1 ) {
		return arr[H][A];
	}

	int t1 = 1 + max_time( H - 2, A - 8 );
	int t2 = 1 + max_time( H- 17, A + 7 );

	arr[H][A] = (t1 > t2 ? t1 : t2);

	return arr[H][A];
}


int main()
{
	int t;
		
	cin >> t;
	for ( int i = 0; i < 1000; i++ ) {
		for ( int j = 0; j < 1000; j++ ) {
			arr[i][j] = -1;
		}
	}

	for ( int i = 0; i < t; i++ ) {
		int H;
		int A;

		cin >> H;
		cin >> A;

		cout << 2 * max_time(H, A) - 1 << endl;
	}

	return 0;
}
