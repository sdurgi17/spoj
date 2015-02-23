#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void print( int arr[][50], int n );
void place_queen( int row, int arr[][50], int n );

int main()
{
	int n;
	cin >> n;
	while ( n != EOF ) {
		int arr[n][50];
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				arr[i][j] = 0;
			}
		}
	
		for ( int i = 0; i < n; i++ ) {
			int k;
			cin >> k;
			if ( k > 0 ) {	
				arr[i][k - 1] = 2;
			}
		}
		
		for ( int i = 0; i < n; i++ ) {
			place_queen(i, arr, n );
		}
	
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				if ( arr[i][j] == 1 || arr[i][j] == 2 ) {
					cout << j + 1 << " ";
				}
			}
		}
		cout << endl;
		
		cin >> n;
	}

	return 0;
}

void place_queen( int row, int arr[][50], int n ) {
	int q_present = 0;

	for ( int i = 0; i < n; i++ ) {
		if ( arr[row][i] == 1 ) {
			arr[row][i] = 0;
			if ( i == n - 1 ) {
				place_queen(row - 1, arr, n);
				place_queen(row, arr, n);
				return;
			}
			
			q_present = i + 1;
		}

		if ( arr[row][i] == 2 ) {
			place_queen(row - 1, arr, n);
			return;
		}
	}
	
	for ( int col = q_present; col < n; col++ ) {
		int q_c = 0;
		for ( int j = 0; j < n; j++ ) {
			for ( int k = 0; k < n; k++ ) {
				if ( j == row || k == col || j + k == col + row || j - k == row - col ) {
					if ( arr[j][k] == 1 || arr[j][k] == 2 ) {
						q_c++;
						break;
					}
				}
			}
		}

		if ( q_c == 0 ) {
			arr[row][col] = 1;
			return;
		}
	}

	place_queen(row - 1, arr, n);
	place_queen(row, arr, n);
}

void print( int arr[][50], int n ) {
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}
