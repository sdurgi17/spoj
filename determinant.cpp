#include <iostream>
#include <vector>
#define sign(k) (k%2 == 0 ? 1 : -1) 

using namespace std;

void print(vector <vector <int> > v){
	int n=v.size();
	for(int i=0; i<n; i++){
		for(int j=0; j< n; j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int deter(vector <vector <int> > v, int n){
	if(n < 1)
		return 0;
	else if(n==2)
		return (v[0][0] * v[1][1] - v[0][1] * v[1][0]);
	else if(n > 2){
		int sum = 0, dummy;
		for(int i=0; i<n; i++){
			vector < vector <int> > v1(n-1);
			//int a=0, b=0;
			for(int p=1; p<v.size(); p++){
				for(int q=0; q<v.size(); q++){
					if(q!=i){
						v1[p-1].push_back(v[p][q]);
					}
				}
			}
			//cout<<v[0][i]<< " "<< sign(num-n+i) << endl;
			//print(v1);
			dummy = deter(v1, n-1);
			sum += sign(i) * v[0][i] * dummy;
			print(v1);
			cout << sign(i) << " " << v[0][i] << " " << dummy << " " << sum << endl;
		}
		//cout << sum << endl;
		return sum;
	}
}
			  

int main()
{
	int n;
	cin>>n;
	vector < vector <int> > v(n);
	int a;
	for(int i=0; i<n; i++){
		for(int j=0; j< n; j++){
			cin >> a;
			v[i].push_back(a);
		}
	}
	//print(v);
	//print(s);
	cout<<endl<<"determinant = "<<deter(v, n)<<endl;
	
	return 0;
}
