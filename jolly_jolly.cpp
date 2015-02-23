#include <iostream>
#include <string>

using namespace std;
bool divisibility(string s1, int n );

int main()
{
	int t;
	cin >> t;

	for ( int i = 0; i < t; i++ ) {
		string s1;
	
		cin >> s1;

		if ( divisibility(s1, 252) ) {
			cout << "Yes ";
		} else {
			cout << "No ";
		}

		if ( divisibility(s1, 525) ) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}

bool divisibility(string s1, int n ) {
	int a = 0;	
	for ( int i = 0; i < s1.size(); i++ ) {
		a = ( a * 10 + (s1[i] - 48) ) % n;
	}

	return ( a == 0  ? true : false );
}
		
