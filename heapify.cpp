#include <iostream>

using namespace std;

void print(int a[], int l)
{
	for(int i=0; i<l; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void minheapify(int a[], int i, int l){
	int small = i;
	if(2*i+1 < l && a[2*i+1] < a[i])
		small = 2*i+1;
	if(2*i+2 < l && a[2*i+2] < a[small])
		small = 2*i+2;
	if(small != i){
		int tmp = a[small];
		a[small] = a[i];
		a[i] = tmp;
		minheapify(a, small, l);  
	}
}
void maxheapify(int a[], int i, int l){
	int small = i;
	if(2*i+1 < l && a[2*i+1] > a[i])
		small = 2*i+1;
	if(2*i+2 < l && a[2*i+2] > a[small])
		small = 2*i+2;
	if(small != i){
		int tmp = a[small];
		a[small] = a[i];
		a[i] = tmp;
		maxheapify(a, small, l);  
	}
}
void minheap(int a[], int l){
	for(int k=l/2-1; k>=0; k--){
		minheapify(a, k, l);
	}
}
void maxheap(int a[], int l){
	for(int k=l/2-1; k>=0; k--){
		maxheapify(a, k, l);
	}
}
void hofftree(int arr[], int ref[], int indx, int &l){
	while(indx > 0){
		minheap(ref, indx+1);
		int tmp1 = ref[0];
		ref[0] = ref[indx];
		ref[indx] = tmp1;
		indx--;
		minheap(ref, indx+1);
		int tmp2 = ref[0];
		ref[0] = ref[indx];
		ref[indx] = tmp2;
		//indx--;
		//minheap(ref, indx+1);
		ref[indx] = tmp1+tmp2; 
		arr[l] = tmp1+tmp2;
		l++;
		maxheap(arr, l);
	}
}
	 
int main()
{
	int arr[15] = {5, 9, 50, 11, 25};
	int ref[15] = {5, 9, 50, 11, 25};
	//int a[5] = {5,3,4,1,2};
	print(arr, 5);
	//minheap(a, 5);
	int l = 5;
	hofftree(arr, ref, 4, l);
	print(arr,l);
	return 0;
}
	
