#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>&v)
{
	for(int i=0; i<v.size(); i++)
		cout<<v[i]<<" ";
	cout<<endl;
}
void swp(int lb, int mid, int ub,  vector <int>& v){
	vector <int> tmp(ub-lb+1);
	for(int i=mid; i<=ub; i++)
		tmp[i-mid] = v[i];
	for(int i=lb; i<=mid-1; i++)
		tmp[ub-mid-lb+1+i]=v[i];
	for(int i=lb; i<=ub; i++)
		v[i] = tmp[i-lb];
} 

void permute(vector<int>& v, int lb, int ub, int c){
	if(c<ub){
		print(v);
		swp(lb, c, ub, v);
		permute(v, lb, c+1 , c+1 ); 
		permute(v, c+1, ub, c+1);
		//permute(v, lb, i, c-1); 
	}
	//return;
}
int main()
{
	int arr[] = {1, 2, 3, 4};
	vector <int> v(arr, arr+4);
	permute(v, 0, v.size() - 1, 1);

	return 0;
}
