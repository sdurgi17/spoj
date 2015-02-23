#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <cstdio>

using namespace std;

long int no_of_games( long int avg ) {
	
	int sol = 0;
	int exp = 0;		
	while( avg % 10000  != 0 ) {
	
		long int lst_dgt = 0;
	
		for ( int i = 1; i <=4; i++ ) {
			long int div = pow(10, i);
			if ( avg % div != 0 ) {
				lst_dgt = ( ( avg % div ) / (div / 10) ) ;
				break;
			}
		}
	
		cout << " last digit " << lst_dgt << endl;
		getchar();

		long int d;
		if ( lst_dgt % 2 == 0 ) {
			d = 5;
		} else if ( lst_dgt == 1 || lst_dgt == 3 || lst_dgt == 7 || lst_dgt == 9 ) {
			d = 0;
		} else if ( lst_dgt == 5 ) {
			d = 2;
		}

		sol += d * pow(10, exp);
		if ( 	
			avg = avg * d * pow(10, exp);
		
		exp++;
	}

	return sol;

}


int main()
{
	int t;
	cin >> t;
	
	for ( int i = 0; i < t; i++ ) {
		char ch = 'a';

		while ( ch != '.' ) {
			cin >> ch;
		}

		string s = "0000";
		int j = 0;

		ch = getchar();

		while ( ch != '\n' ) {
			s[j] = ch;
			ch = getchar();
			j++;
		}
		
		long int avg = 1000 * (s[0] - 48) + 100 * (s[1] - 48) + 10* (s[2]- 48) + 1 *  (s[3] - 48);
				
		if ( avg == 0 ) {
			 cout << 0 << endl;
		} else {
			cout << no_of_games(avg) << endl;
		}

	}
	
	return 0;
}
