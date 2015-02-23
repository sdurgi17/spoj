#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;

struct paths {
	bool next;
	bool prev;
	bool Kth;

	paths() {
		next = false;
		prev = false;
		Kth = false;
	}
};

typedef pair<long int, long int> pl;

class graph {
	vector<paths> spidey;
	long int height;
	long int k;
	string B_L, B_R;

	priority_queue<pl, vector<pl>, greater<pl> > Q;
	vector<long int> distance;
	

	public :
		void build_graph(string B_L, string B_R) {
			for ( long int i = 0; i < height; i++ ) {
				if ( B_L[i] != 'X' ) {
					if ( i + 1 < height ) {
						if ( B_L[i + 1] != 'X' ) {
							spidey[i].next = true;
						}
					} else {
						spidey[i].next = true;
					}

					if ( i - 1 >= 0 ) {
						if ( B_L[i - 1] != 'X' ) {
							spidey[i].prev = true;
						}
					}
					
					if ( i + k  < height ) {
						if ( B_R[i + k] != 'X' ) {
							spidey[i].Kth = true;
						}
						
					} else {
						spidey[i].Kth = true;
					}
				}
			}
			
			for ( long int i = height; i < 2 * height; i++ ) {
				if ( B_R[i - height] != 'X' ) {
					if ( i + 1 < 2 * height ) {
						if ( B_R[i - height + 1] != 'X' ) {
							spidey[i].next = true;
						}
					} else {
						spidey[i].next = true;
					}

					if ( i - 1 >= height ) {
						if ( B_R[i - height - 1] != 'X' ) {
							spidey[i].prev = true;
						}
					}
					
					if ( i - height + k  <  height ) {
						if ( B_L[i + k - height ] != 'X' ) {
							spidey[i].Kth = true;
						}
					} else {
						spidey[i].Kth = true;
					}
				}
			}
		}
				
		long int dijkstra() {
			pl tmp;
			tmp.first = 0;
			tmp.second = 0;
			
			Q.push( tmp );
			distance[0] = 0;
			
			while( !Q.empty() ) {
				pl top = Q.top();
				long int vtx = top.second;
				
				distance[vtx] = top.first;
				Q.pop();
				
				if ( spidey[vtx].next ) {
					if ( vtx == height - 1 || vtx == 2 * height - 1 ) {
						return distance[vtx] + 1;
					}

					if ( distance[vtx + 1] > distance[vtx] + 1 ) {
						if ( (vtx < height &&  vtx + 1 >= distance[vtx] + 1) || (vtx >= height && (vtx + 1 - height) >= distance[vtx] + 1)) {
							distance[vtx + 1] = distance[vtx] + 1;
							pl t;
							t.first = distance[vtx + 1];
							t.second = vtx + 1;
							Q.push(t);	
						}
					}
				}

				if ( spidey[vtx].prev ) {
					if ( distance[vtx - 1] > distance[vtx] + 1 ) {
						if ( (vtx < height &&  vtx - 1 >= distance[vtx] + 1) || (vtx >= height && (vtx - 1 - height) >= distance[vtx] + 1)) {
							pl a;
							distance[vtx - 1] = distance[vtx] + 1;
							a.first = distance[vtx - 1];
							a.second = vtx - 1;
							Q.push(a);	
						}
					}
				}

				if ( spidey[vtx].Kth ) {
					if ( vtx < height )  {
							if ( vtx + height + k  >= 2 * height ) {
								return distance[vtx] + 1;
							}
							if ( vtx + k >= distance[vtx] + 1 && distance[vtx + height + k ] > distance[vtx] + 1) {
								distance[vtx + height + k ] = distance[vtx] + 1;
								pl t;
								t.first = distance[vtx + height + k];
								t.second = vtx + height + k ;
								Q.push(t);	
							
							}
						} else 	if ( vtx >= height ) {
									if ( vtx - height + k >= height ) {
										return distance[vtx] + 1;
									}
							
								if ( vtx - height + k >= distance[vtx] + 1 && distance[vtx - height + k ] > distance[vtx] + 1) { 
									distance[vtx - height + k ] = distance[vtx] + 1;
									pl t;
									t.first = distance[vtx - height + k];
									t.second = vtx - height + k ;
									Q.push(t);	
								}
						}
					}
				}
					
			
			
			return ( distance[height - 1] < distance[2 * height - 1] ? distance[height - 1] : distance[2 * height - 1] );
		}

		void print_graph() {
			for ( int i = 0; i < 2 * height; i++ ) {
				if ( spidey[i].next )
					cout << i << " next true " << endl; 

				if ( spidey[i].prev )
					cout << i << " prev true " << endl; 

				if ( spidey[i].Kth )
					cout << i << " Kth true " << endl; 
			}
		
			return;
		}
		
		void print_distances() {
			for ( int i = 0; i < 2 * height; i++ ) {
				cout << i << "   " << distance[i] << endl;
			}
		}

		graph( long int h, long int k, string B_L, string B_R) {
			paths tmp;
			for ( int i = 0; i < 2 * h; i++ ) {
				spidey.push_back(tmp);
				distance.push_back(LONG_MAX);
			}

			height = h;
			this -> k = k;
			this -> B_L = B_L;
			this -> B_R = B_R;
		}

	
};

int main()
{
	long int t;

	cin >> t;

	for ( long int  i = 0; i < t; i++ ) {
		long int h, k;
		cin >> h ;
		cin >> k;
		
		string T1, T2;
		cin >> T1;
		cin >> T2;

		graph towers(h, k, T1, T2);
		towers.build_graph(T1, T2);
		
		long int sol = towers.dijkstra();

		if ( sol != LONG_MAX ) {
			cout << sol << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
