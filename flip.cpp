#include <iostream>
#include <vector> 

using namespace std;

int mod(int x)
{
	if(x>=0)
		return x;
	return -x;
} 
bool identical(vector <int> a, vector <int> b)
{
	for(int i=0; i<a.size(); i++){
		if( a[i]!= b[i] )
			return false;
	}
	return true;
}

void flip(int n, vector <int> &arr){
	vector <int> cp(arr.begin(), arr.end());
	for(int i=0; i<n; i++)
		arr[i]=-cp[n-i-1];
}

int main()
{
	int cases, ct=0, tmp, n;
	cin >> cases;
	vector < vector <int> > vv;

	while(ct<cases){
	
	cin>>n;

	vector <int> flips;
	vector <int> chk, chk1, arr;

	for(int i=0; i<n; i++){
		cin>>tmp;
		arr.push_back(tmp);
	}
	vector <int> brr(arr.begin(), arr.end());
	 

	for(int i=0; i<n; i++){
		chk.push_back(n-i);
		chk1.push_back(i+1);
	}

	int i,j;
 
	for(int i=0; i<n; i++){
		if(identical(brr, chk1)){
			break;
		}
		for(j=0; j<n; j++){
			if(mod(brr[j])==chk[i])
				break;
		
		}
		if(!(j==n-1-i && brr[j] > 0)){
		if(j!=0){
			
				flips.push_back(j+1);
				flip(j+1, brr);
		}
			if(brr[0]>0){
				flips.push_back(1);
				flip(1, brr);
			}
		

			flips.push_back(n-i);
			flip(n-i, brr);
		}

	}
	vv.push_back(flips);
	ct++;
	}

	for(int i=0; i<vv.size(); i++){
		cout<<i+1<<"  "<<vv[i].size()<<"  ";
		for(int j=0; j<vv[i].size(); j++)
			cout<<vv[i][j]<<"  ";
		cout<<endl;
	}
	return 0;
}	
