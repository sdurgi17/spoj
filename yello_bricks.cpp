#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct dimension {
	int l;
	int b;
	int h;
};

long long int no_of_cubes( vector<dimension> Q, int min );

int main()
{
	int s;
	vector<long long int> sol;

	cin >> s;
	while ( s ) {
		vector<dimension> Q;

		int min = INT_MAX;
		for ( int i = 0; i < s; i++ ) {
			dimension tmp;
		
			cin >> tmp.l;		
			if ( tmp.l < min ) 
				min = tmp.l;

			cin >> tmp.b;		
			if ( tmp.b < min ) 
				min = tmp.b;
	
			cin >> tmp.h;		
			if ( tmp.h < min ) 
				min = tmp.h;
	
			Q.push_back(tmp);	
		}

		sol.push_back( no_of_cubes(Q, min) );
		cin >> s;
	}

	for ( int i = 0; i < sol.size(); i++ ) {
		cout << sol[i] << endl;
	}
	
	return 0;
}

long long int no_of_cubes( vector<dimension> Q, int min ) {
	long long int sol = 0;

	for ( int i = min; i >= 1; i-- ) {
		int check = 1;
		for ( int j = 0; j < Q.size(); j++ ) {
			long long int c;
			if ( Q[j].l % i == 0 && Q[j].b % i == 0 && Q[j].h % i == 0 ) {
				c = ( Q[j].l / i)  * ( Q[j].b/ i) * ( Q[j].h/ i );
				sol = sol + c;
			} else {
				sol = 0;
				check = 0;
				break;
			}
		}

		if ( check == 1 ) {
			return sol;
		}
	}
	
}



