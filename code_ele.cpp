#include <iostream>
#include <string>

using namespace std;


int main() 
{
	int n;

	cin >> n;
	
	int sol[n];
	int x = 0;

	for ( int i = 0; i < n; i++ ) {
		
		int size;	
		cin >> size;
		char arr[size];
		int count = size;
		

		for ( int j = 0; j < size; j++ ) {
			cin >> arr[j];
		}

		for ( int k = 0; k < size; k++ ) {
			if ( k == 0 ) {
				if ( arr[k] == '1' ) {
					count--;
					arr[k] = '2';
					if ( arr[k + 1] == '0' ) {
					 	count--;
						arr[k + 1] = '2';
					}
				}
			}

			else if ( k == size - 1 ) {
				if ( arr[k] == '1' ) {
					count--;
					arr[k] = '2';
					if ( arr[k - 1] == '0' ) {
						count--;
						arr[k - 1] = '2';
					}
				}
			} 
			
			else {
				if ( arr[k] == '1' ) {
					count--;
					arr[k] = '2';
					if ( arr[k - 1] == '0' ) {
						count--;
						arr[k - 1] = '2';
					}
					
					if ( arr[k + 1] == '0' ) {
						count--;
						arr[k + 1] = '2';
					}
				}
			}
		}

		sol[i] = count;
		
	}

	for ( int i = 0; i < n; i++ ) {
		cout << sol[i] << endl;
	}

}

					

		 

