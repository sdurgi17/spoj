#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	char ch;
	long long int j = 1;

	do {
		vector<long long int> v;
		for ( int i = 0; i < 4; i++ ) {
			long long int k;
			cin >> k;

			v.push_back(k);
		}

		sort(v.begin(), v.end() );
		
		cout << "Case "<< j << ": " << v[3] + v[2] << endl;
		j++;		
	}
	while( (ch = getchar()) != EOF );
	
	return 0;
}
