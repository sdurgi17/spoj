#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hcf(int x, int y){
	int min=(x<y?x:y);
	for(int i=min; i>0; i--){
		if(x%i==0 && y%i==0)
			return i;
	}
}
int main()
{
	int yes, tmp, res, n;
	cin>>n;
	while(n > 0){
	
	vector < vector <int> > vv;
	for(int i=0; i<n; i++){
		vector <int> v;
		for(int j=0; j<3; j++){
			cin>>tmp;
			if(i==0 && j==0)
				res=tmp;
			else
				res=hcf(tmp, res);
			v.push_back(tmp);
		}
		vv.push_back(v);
	}
	long long int sum=0;
	for(int i=0; i<vv.size(); i++){
		long int num1=1;
		for(int j=0; j<3; j++){
			num1*=vv[i][j]/res;
		}
		sum+=num1;
	}
	
	cout<<sum<<endl;
	cin>>n;
	}

	return 0;
}	 
