#include <iostream>
#include <map>

using namespace std;

int main() 
{
	int f;
	map<int, int> ff;
	int j = 0;

	cin >> f;

	for ( int i = 0; i < f; i++ ) {
		int id;
		int n;

		cin >> id;
		
		ff[id] = j;		
		j++;
		cin >> n;

		for ( int k = 0; k < n; k++ ) {
			cin >> id;
			ff[id] = j;
			j++;
		}
	}

	cout << ff.size() - f;

	return 0;
}

