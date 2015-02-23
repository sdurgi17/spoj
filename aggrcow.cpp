#include <iostream>
#include <algorithm>
#define N 100000

using namespace std;

void print(long long int res[N], long long int l){
	for(long long int i=0; i<l; i++)
		cout<<res[i]<<" ";
	cout<<endl;
}

long long int get_dist(long long int res[N], long long int cows){
	int min = res[1] - res[0];
	for(long long int i=1; i<cows-1; i++){
		if(min > res[i+1] - res[i])
			min = res[i+1] - res[i];
	}
	return min;
}


long long int min_dist(long long int n , long long int cows, long long int barn[N], long long int l, long long int indx, long long int res[N]){
	if(cows == l){
		//print(res, cows);
		return get_dist(res, cows);
	}
	else if(res[l-1] == barn[N-1]){
		return 0;
	}
	else{
		int q=0;
		for(long long int i=indx+1; i<n; i++){
			res[l] = barn[i];
			long long int t = min_dist(n, cows, barn, l+1, i, res);
			if(q<t)
				q=t;
		}
		return q;
	}
}
int main()
{
	long long int tests;
	cin>>tests;
	long long int n, c;
	while(tests-- > 0){
		cin>>n>>c;
		long long int barn[N], res[N];
		for(long long int i=0; i<n; i++){
			cin>>barn[i];
		}
		sort(barn, barn+n); 
		cout << min_dist(n, c, barn, 0, -1, res) << endl;
	}
	
	return 0;
} 


