#include <iostream>

using namespace std;

int main() 
{
	
	int n;
	int m;
	cin >> n;

	int time[n][n];

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			cin >> time[i][j];
		}
	}

	cin >> m;
	
	// 0 => restaurent // 1 => gas // 2 => dest //

	int test[m][3];
	for ( int i = 0; i < m; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			cin >> test[i][j];
		}
	}

	for ( int i = 0; i < m; i++ ) {
		// sum s to g and g to d 
		int t1 = time[ ( test[i][0] ) ][ ( test[i][1] ) ] + time[ ( test[i][1] ) ][ ( test[i][2] ) ];
		cout << t1 << " ";
		int t2 = t1 - time[ (test[i][0]) ][ (test[i][2]) ];
		cout << t2 << endl;
	}

	return 0;
}
