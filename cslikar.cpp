#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct cell {
	char ch;
	int flood_time;
	bool visited;
	int dist;

	cell() {
		flood_time = INT_MAX;
		visited = false;
		dist = INT_MAX;
	}
};

struct posn {
	int r;
	int c;
	int flood_time;
	int dist;
};

class kaktus_grid {
	public :
		int r;
		int c;

		cell grid[50][50];
		queue<posn> q;
		posn start;
		posn end;

		void update_flood_times() {
			while ( !q.empty() ) {
				posn top = q.front();
				q.pop();
				push_neighbours(top);
			}
		}

		void push_neighbours( posn top ) {
			 check_adj( top, top.r + 1, top.c );
			 check_adj( top, top.r - 1, top.c );
			 check_adj( top, top.r, top.c + 1 );
			 check_adj( top, top.r, top.c - 1 );
		}

		void check_adj( posn top, int r, int c ) {
			if ( r >= 0 && r < this->r && c >= 0 && c < this->c ) {
				if ( grid[r][c].ch != 'X' && grid[r][c].ch != 'D' ) {
					if ( grid[r][c].flood_time > top.flood_time + 1 ) {
						grid[r][c].flood_time = top.flood_time + 1;
						posn p;

						p.r = r;
						p.c = c;
						p.flood_time = top.flood_time + 1;

						q.push(p);
					}
				}
			}
		}
		
		void min_path() {
			update_flood_times();
			
			q.push(start);

			while ( !q.empty() ) {
				posn top = q.front();
				q.pop();
				check_neighbours(top);
			}
			
			if ( grid[end.r][end.c].dist != INT_MAX )  {
				cout << grid[end.r][end.c].dist << endl;
			} else {
				cout << "KAKTUS" << endl;
			}
		}
		
		void check_neighbours( posn top ) {
			check_adjacent(top, top.r + 1, top.c );
			check_adjacent(top, top.r - 1, top.c );
			check_adjacent(top, top.r, top.c + 1 );
			check_adjacent(top, top.r, top.c - 1 );
		}

		void check_adjacent( posn top, int r, int c ) {
			if ( r >= 0 && r < this->r && c >= 0 && c < this->c ) {
				if ( grid[r][c].ch != 'X' ) {
					if ( grid[r][c].flood_time > top.dist + 1  && grid[r][c].dist > top.dist + 1) {
						grid[r][c].dist = top.dist + 1;
						posn p;

						p.r = r;
						p.c = c;
						p.dist = top.dist + 1;

						q.push(p);
					}
				}
			}
		}
			
		void print_flood_times() {
			for ( int i = 0; i < r; i++ ) {
				for ( int j = 0; j < c; j++ ) {
					if ( grid[i][j].dist != INT_MAX ) {
						cout << grid[i][j].dist << " ";
					} else {
						cout << "#" << " ";
					}
				}
				cout << endl;
			}
			cout << endl << endl;
		}

		kaktus_grid( int r, int c ) {
			this->r = r;
			this->c = c;

			for ( int i = 0; i < r; i++ ) {
				for ( int j = 0; j < c; j++ ) {
					cell tmp;
					cin >> tmp.ch;
					
					if ( tmp.ch == '*' ) {
						tmp.flood_time = 0;
						tmp.visited = true;
						
						posn p;
						
						p.r = i;
						p.c = j;
						p.flood_time = 0;
						q.push(p);
					} else if ( tmp.ch == 'S' ) {
						start.r = i;
						start.c = j;
						start.dist = 0;
						tmp.dist = 0;
					} else if ( tmp.ch == 'D' ) {
						end.r = i;
						end.c = j;
					} 

					grid[i][j] = tmp;
				}
			}
		}
};

int main()
{
	int r;
	int c;

	cin >> r;
	cin >> c;

	kaktus_grid k(r, c);
	k.min_path();

	return 0;
}
