#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct cell {
	char ch;
	bool visit;
	int r;
	int c;

	cell() {
		visit = false;
	}
};

bool check_maze_validity( cell maze[][21], cell start, cell end, int m, int n );

bool operator== ( cell a, cell b ) {
	if ( a.r == b.r && a.c == b.c ) {
		return true;
	} else {
		return false;
	}
}

int main()
{
	int t;
	cin >> t;
	vector<bool> sol;

	for ( int k = 0; k < t; k++ ) {
		 
		int m, n;
		cell start, end;

		cin >> m;
		cin >> n;
		cell maze[m][21];
	
		int ctr = 0;
		for ( int i = 0; i < m; i++ ) {
			for ( int j = 0; j <n; j++ ) {
			
				cin >> maze[i][j].ch;
				maze[i][j].r = i;
				maze[i][j].c = j;
		
				if ( ( i == 0 ) || ( i == m - 1 ) || ( j == 0 ) || ( j == n - 1) ) {
					if ( maze[i][j].ch == '.' ) {
						if ( ctr == 0  ) {
							//maze[i][j].visit = true;
							start = maze[i][j];
						} else {
							end = maze[i][j];
						}
					
						ctr++;
					}
				}
			}
		}

		if ( ctr == 2 ) {
			if ( check_maze_validity( maze, start, end, m, n ) ) {
				sol.push_back(true);
			} else {
				sol.push_back(false);
			}

		} else {
			sol.push_back(false);
		}
	}

	for ( int i = 0; i < sol.size(); i++ ) {
		if ( sol[i] ) {
			cout << "valid"<< endl;
		}else {
			cout << "invalid"<< endl;
		}
	}
			
	return 0;
}

bool check_maze_validity( cell maze[][21], cell start, cell end, int m, int n ) {
	
	if ( start.ch == '#' ) {
		return false;
	}
	
		
	if ( start.visit == true ) {
		return false;
	} 
	
	if ( start == end ) {
		return true;
	}

	bool decn;
	int row = start.r;
	int col = start.c;

/*	getchar();
	cout << endl << "row " << row;
	cout << "col " << col;
	cout << endl;
*/
	maze[row][col].visit = true;
	
	if ( start.r != 0 ) {
		decn = check_maze_validity( maze, maze[row - 1][col], end, m, n );
		
		if ( decn ) {
			return decn;
		}
	}
	
	if ( start.c != n - 1 ) {
		

		decn = check_maze_validity( maze, maze[row][col + 1], end, m, n );
		
		if ( decn ) {
			return decn;
		}
	}
	
	if ( start.r != m - 1 ) {
		decn = check_maze_validity( maze, maze[row + 1][col], end, m, n );
		
		if ( decn ) {
			return decn;
		}
	}
	
	if (  start.c != 0 ) {
		decn = check_maze_validity( maze, maze[row][col - 1], end, m, n );
		
		if ( decn ) {
			return decn;
		}
	}
	

	return false;
}
