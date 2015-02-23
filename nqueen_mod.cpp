#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


struct queen {
	int col;
	bool perm;

	queen() {
		perm = false;
	}
	
};

void print(vector<queen> &v, int n );
void place_queen( int row, vector<queen> &v, int n );
bool find ( vector<queen> &v, queen q );

bool operator==( queen a, queen b ) {
	if ( a.col == b.col ) {
		return true;
	} else {
		return false;
	}
}

int main()
{
	int n;
	cin >> n;
	char c;

	while ( (c = getchar()) != EOF ) {
		
		queen q;
		q.col = -1;
		
		vector<queen> v(n, q);	
		
		for ( int i = 0; i < n; i++ ) {
			int k;
			cin >> k;

			if ( k != 0 ) {
				v[i].col = k - 1;
				v[i].perm = true;
			}
		
		}
			
		for ( int i = 0; i < n; i++ ) {
			place_queen(i, v, n );
			print(v, n);
		}
	
		print(v, n);
		
		cin >> n;
	}

	return 0;
}

void place_queen( int row, vector<queen> &v, int n ) {
	int q_present = 0;
	
	if ( v[row].col != -1 ) {
		
		if ( v[row].col == n - 1  && v[row].perm == false) {
			v[row].col = -1;
			place_queen(row - 1, v, n);
			place_queen(row, v, n);
		
			return;
		}

		if ( v[row].perm == true ) {
			place_queen(row - 1, v, n);
			return;
		} else {
			q_present = v[row].col + 1;
			v[row].col = -1;
		}
	}

	for ( int col = q_present; col < n; col++ ) {
		int q_c = 0;
	
		queen q;
		q.col = col;
			
		if ( count(v.begin(), v.end(), q) ) {
			for ( int i = 0; i < n; i++ ) {
				if ( v[i].col != -1 ) {
					if ( i + v[i].col == row + col || i - v[i].col == row - col ) { 
						q_c++;
						break;
					}
				}
			}
			if ( q_c == 0 ) {
				v[row].col = col;	
				return;
			} else {
				if ( q_c != 1 ) {
					cout << " q_c " << q_c << endl;
					getchar();
				}
			}
		}
	}

	place_queen(row - 1, v, n);
	place_queen(row, v, n);
}

void print( vector<queen> &v, int n ) {
	for ( int i = 0; i < n; i++ ) {
		printf("%d ",v[i].col + 1  );
	}
	cout << endl;
}

bool find ( vector<queen> &v, queen q ) {
	vector<queen> :: iterator it;

	for ( it = v.begin(); it != v.end(); it++ ) {
		if ( *it == q ) {
			return true;
		}
	}

	return false;
}
