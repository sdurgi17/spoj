#include <iostream>
#include <algorithm>
#define N 10

using namespace std;

void print(int list[N], int n){
	for(int i=0; i<n; i++){
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

int profit(int n, int p[N], int w[N], int list[N], int index[N], int wt, int maxw, int l){
	
	if(wt > maxw){
		print(list, n);
		return -p[index[l-1]];
	}
	else if(l==n){
		print(list, n);
		return 0;
	}
	else{
		int r;
		if(l==0)
			r = 0;
		else
			r = index[l-1] + 1;
		int prof = 0;
		for(int i=r; i<n; i++){
			list[l] = w[i];
			index[l] = i;
			int t = p[i] + profit(n, p, w, list, index, wt+w[i], maxw, l+1);
			if(t>prof)
				prof = t;
			list[l] = 0;
			index[l] = -1;
		}
		return prof;
	}

} 

int main()
{
	int n, maxw;
	cin>>n;
	cin>>maxw;

	int list[N] = {0}, index[N], w[N], p[N];
	for(int i=0; i<n;i++){
		cin>>w[i];
		index[i] = -1;
	}
	for(int i=0; i<n;i++)
		cin>>p[i];

	cout << endl << "profit is = " << profit(n, p, w, list, index, 0, maxw, 0) << endl;
	
	return 0;
}
