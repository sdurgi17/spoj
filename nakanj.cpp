#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int decode(string arr) {
	
	int c = (int)arr[0] - 96;
	int r = (int)arr[1] - 49;

	return (r * 8) + c - 1;
}

int next_posn( int r, int c, int p ) {
	return (p + (r * 8) + c);
}

int bound_check( int r, int c, int posn ) {
	int row = posn / 8;
	int col = posn % 8;

	if ( row + r < 8 && col + c < 8  && row + r >= 0 && col + c >= 0) {
		return 1;
	} else { 
		return 0;
	}
}

void insert(int v1, int v2, int mat[][64] ) {
	mat[v1][v2] = 1;
}

void floyd_warshall(int mat[][64] ) {
	int k, i, j;

	for ( k = 0; k < 64; k++ ) {
		for ( i = 0; i < 64; i++ ) {
			for ( j = 0; j < 64; j++ ) {
				if ( mat[i][j] > mat[i][k] + mat[k][j] ) {
					mat[i][j] =  mat[i][k] + mat[k][j] ;
				}
			}
		}
	}
}

int main()
{
	
	int t;
	cin >>t;

	int mat[64][64];
	int i, j;
	
	for ( i = 0; i < 64; i++ ) {
		for ( j = 0; j < 64; j++ ) {
			mat[i][j] = 1000;
		}
	}

	for ( i = 0; i < 64; i++ ) {
			
		int e = 1;
		int v1 = i;

		int v2 = next_posn( -2, 1, v1 );
		int decn = bound_check( -2, 1, v1);   

		if ( decn ) {
			insert(v1, v2, mat);
		}

		decn = bound_check( -2, -1, v1);
		if ( decn ) {
			v2 = next_posn( -2, -1, v1 );
			insert(v1, v2, mat);
		}

		decn = bound_check( -1, 2, v1);
		if ( decn ) {
			v2 = next_posn( -1, 2, v1 );
			insert(v1, v2, mat);
		}
			
		decn = bound_check( -1, -2, v1);
		if ( decn ) {
			v2 = next_posn( -1, -2, v1 );
			insert(v1, v2, mat);
		}

		decn = bound_check( 1, 2, v1);
		if ( decn ) {
			v2 = next_posn( 1, 2, v1 );
			insert(v1, v2, mat);
		}

		decn = bound_check( 1, -2, v1);
		if ( decn ) {
			v2 = next_posn( 1, -2, v1 );
			insert(v1, v2, mat);
		}

		decn = bound_check( 2, -1, v1);
		if ( decn ) {
			v2 = next_posn( 2, -1, v1 );
			insert(v1, v2, mat);
		}

		decn = bound_check( 2, 1, v1);
		if ( decn ) {
			v2 = next_posn( 2, 1, v1 );
			insert(v1, v2, mat);
		}
	}	
	
	floyd_warshall(mat);
	int src, dsn;
	string p;
/*	src = 0;
	while(src < 64 ) {

	for ( int i = 7; i >= 0; i-- ) {
		for ( int j = 0; j < 8; j++ ){
			if ( src == i*8 + j ) {
				cout << 0 << " ";
			} else {
				cout << mat[src][(i * 8) + j] << " ";
			}
		}
		cout << endl;
	}
		cout << endl;
		cout << endl;
		cout << endl;
	
	src++;
	}
*/
	for ( j = 0; j < t; j++ ) {
		string p1, p2;
		cin >> p1;
		cin >> p2;
			
		src = decode(p1);
		dsn = decode(p2);
		if ( src == dsn ) {
			cout << 0 << endl;
		} else {
			cout << mat[src][dsn] << endl;
		}
		
	}
	
		return 0;
}


