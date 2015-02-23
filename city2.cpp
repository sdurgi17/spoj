#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	int arr[10];
	cin>>n;
	int num;
	int ct=0;
	map <int, int> m;
	for(int i=0; i<n; i++){
		cin>>num;
		arr[i]=num;
		if(num > 0 && !m.count(num)){
			m[num] = i;
			ct++;
		}
		else if(num > 0){
			bool b=true;
			for(int k=m[num]+1; k<i; k++){
				if(arr[k]<num){
					b=false;
					break;
				}
			
			}
			cout<<"b"<<b<<endl;
			if(!b)
				ct++;
		}
	}
	cout<<"count"<<ct<<endl;

	return 0;
}
