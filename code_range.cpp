#include <iostream>
#include <vector>

using namespace std;
void make_changes( int , int, int, int, int* );

int main() 
{
	int t;
	int min, max;

	vector<int> sol;

	cin >> t;

	for ( int i =0; i < t; i++ ) {
		int n, m;
		cin >> n;
		cin >> m;
		int arr[n];
		
		for ( int k = 1; k <= n; k++ ) {
			arr[k-1] = k;
		}

		for ( int j = 0; j < m; j++ ) {
			int w, x, y, z;
			
			cin >> w; 
			cin >> x; 
			cin >> y; 
			cin >> z; 

			make_changes( w, x, y, z, arr);
		}

		int min, max;
		min = max = arr[0];
		for ( int a = 0; a < n; a++ ) {
			if ( arr[a] < min ) 
				min = arr[a];
			else if ( arr[a] > max ) 
				max = arr[a];
		}

		sol.push_back(max - min );

	}

	vector<int> :: iterator it = sol.begin();

	for ( it = sol.begin(); it != sol.end(); it++ ) {
		cout << *it << endl;
	}

	return 0;


}

void make_changes( int w, int x, int y, int z, int *arr ) {
	
	if ( w == 1 ) { 
		for ( int i = x - 1; i < y; i++ ) {
			arr[i] += z;
		}
	} else {
		for ( int i = x - 1; i < y; i++ ) {
			arr[i] -= z;
		}
	}
}



