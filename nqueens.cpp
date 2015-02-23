#include <iostream>
#include <cstdlib>

using namespace std;

void print(int queens[10], int n){
	for(int i=0; i<n; i++){
		cout<<queens[i]<<" ";
	}
	cout<<endl;
}

int nqueens(int n, int queens[10], int i){

	if(i<n){
		int sum = 0;
		for(int j=0; j<n; j++){
			queens[i] = j;
			bool b = true;
			for(int k=0; k<i; k++){
				if (abs(i-k) == abs(j - queens[k]) || j == queens[k])  
					b = false;
			}
			if(b)
				sum += nqueens(n, queens, i+1);
			queens[i] = -1;
		}
		return sum;
	}
	else if(i == n){
		print(queens, n);
		return 1;
	}
}

int main()
{
	int n;
	cin>>n;
	int queens[10];
	for(int i=0; i<10; i++)
		queens[i] = -1;
	cout << endl << "total no of soln(s) = " << nqueens(n, queens, 0);
	
	return 0;
}  
			 
