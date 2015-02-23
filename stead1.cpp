#include <iostream>
#include <map>
#include <vector>
#include <set>
#define pr pair <int, set <int> >
using namespace std;

void printarr(int arr[], int b){
	for(int i=0; i<b; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}
void permute(int start, int cows, int arr[]){
	if(start < cows-1){
		for(int i=start; i<cows; i++){
			swap(arr[i], arr[start]); 
			permute(start+1, cows, arr);
			swap(arr[i], arr[start]);

		}
		return;
	}
	else{
		printarr(arr, cows);
		return;
	}
}

int main()
{
	set <pr> mp;
	int arr[4] = {1,2,3, 4};
	permute(0, 4, arr);
	cout<<endl;/*
	set <int> p(arr, arr+4);
	p.insert(2);
	p.insert(2);
	set <int> :: iterator it = p.begin();
	for(; it!=p.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	if(p.count(1) > 0)
		cout<<"hello"<<endl;*/

	/*for

	int arr[4] = {1,1,3,2};
	vector <int> v(arr, arr+4), v1(arr,arr+4);
	cout<<mp.count(v)<<endl;
	mp[v]=1;
	cout<<mp.count(v)<<endl;
	v[1]++;
	cout<<mp.count(v)<<endl;
	v[1]--;
	cout<<mp.count(v1)<<endl;*/

	/*
	int arr[6] = {0, 4, 3, 2, 1, 2};
	int assgn[4] = {2, 2, 1, 3};

	int pref[][4] = { {1, 2, 3, 4},
			  {1, 3, 2, 4},
			  {2, 1, 3, 4},
			  {3, 2, 4, 1},
			  {4, 1, 2, 3},
			  {2, 4, 1, 2} };  
	
	int k=0, min = pref[arr[0]][0], max=min;
		int m;
		bool b = true;
		for(int i=0; i<6; i++){
			if(b)
				m = assgn[k];
			cout<<"Cow"<<arr[i]<<"Barn"<<k<<"  ";
			if(m > 0){
				if (pref[arr[i]][k] < min)
					min = pref[arr[i]][k];
				if(pref[arr[i]][k] > max)
					max = pref[arr[i]][k];
				m--;
			}
			b = false;
			if(m==0){
				k++;
				b=true;
			}
		}*/
	return 0;		
}
