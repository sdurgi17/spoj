#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct posn {
	int row;
	int col;

	bool right;

	posn() {
		row = 0;
		col = 0;

		right = true;
	}
};

struct garden {
	char obj;
	int m_wood;

	garden() {
		m_wood = -1;
	}
};

int max_wood( garden arr[][220], int m, int n, posn g);
int value(garden arr[][220], posn g );

int main()
{
	int m;
	int n;
	int t;
	int dist;

	cin >> t;

	for ( int k = 0; k < t; k++ ) {

		dist = 0;

		cin >> m >> n;

		garden arr[m][220];
		posn g; // gardener

		for ( int i = 0; i < m; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				cin >> arr[i][j].obj;
			}
		}

		dist = max_wood( arr, m, n, g);
		cout<< dist << endl;
	}

	return 0;
}

int value(garden arr[][220], posn g ) {
	return ( arr[g.row][g.col].obj == 'T' ) ? 1 : 0;
}

int max_wood( garden arr[][220], int m, int n, posn g ) {
	
	int d1;
	int d2;
	
	if ( g.row >= m || g.col >= n || g.row < 0 || g.col < 0 || arr[g.row][g.col].obj == '#' ) {
		return 0;
	}
	
	if ( arr[g.row][g.col].m_wood != -1 ) {
		return arr[g.row][g.col].m_wood;
	}

	
	posn g1 = g;
	posn g2 = g;

	if ( g.right ) {
		g1.col++;
	} else {
		g1.col--;
	}

	g2.row++;
	g2.right = ( g2.right == true ) ? false : true;
	
	d1 = value(arr, g ) + max_wood( arr, m, n, g1 );
	d2 = value(arr, g) + max_wood( arr, m, n, g2 );
	

	arr[g.row][g.col].m_wood = ( d1 > d2 ? d1 : d2 );
	return ( d1 > d2 ? d1 : d2 );
}
