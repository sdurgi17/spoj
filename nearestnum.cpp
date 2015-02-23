#include <iostream>

using namespace std;

int mod(int a)
{
	return (a>0 ? a : -a);
}

int findnearest(int arr[], int l, int u, int num){
	int mid = (l+u)/2;
	int r = mod(arr[mid] - num);
	cout << mid << " " << r << endl;
	if(arr[mid] == num){
		return 0;
	}
	else if(l == u){
		return r;
	}
	else if(l < u){
		int p = findnearest(arr, l, mid-1, num);
		int q = findnearest(arr, mid+1, u, num);
		
		if(p < q && p < r)
			return p;
		else if(q < p && q < r)
			return q;
		else
			return r;
	}
	else 
		return 10000;
}  

	 

int main()
{
	int arr[8] = {7, 12, 22, 34, 67, 88, 91, 99};
	cout << findnearest(arr ,0, 7, 61) << endl;
	
	return 0;
}
