#include <iostream>
#include <map>
#include <vector>
#define N 50

using namespace std;

class mymap : public map <vector <int> , bool> 
{
	mymap(){}
};	  	

bool allless(int vec[N], int max[N], int n){
	bool b = true;
	for(int i=0; i<n; i++){
		if(vec[i] >= max[i]){
			b = false;
			break;
		}
	}
	return b;
}

void print(int vec[N], int n){
	for(int i=0; i<n; i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

void printv(vector <int> v){
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void printseq(int vec[N], int max[N], int n, map <vector <int> , bool> &m){

	if(allless(vec, max, n)){
		//print(vec, n);
		for(int i=0; i<n; i++){
			vec[i]++;
			vector <int> v(vec, vec+n);
			if(allless(vec,max,n) && !m[v]){
				printseq(vec, max, n, m);
				m[v] = true;
			}
			vec[i]--;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int vec[N] = {0};
	int max[N];
	for(int i=0; i<N; i++)
		max[i] = 3;
	vector <int> v(vec, vec+n);
	map <vector <int> , bool> m;
	m[v] = true;
	printseq(vec, max, n, m);
	cout<<endl<<endl;
	for(map <vector <int>, bool> :: iterator it = m.begin(); it!=m.end(); it++)
		printv(it->first);
	cout<<"no. of distinct sequences " << m.size() << endl;

	return 0;
}	
