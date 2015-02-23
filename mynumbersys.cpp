#include <iostream>
#include <vector>

using namespace std;

void print(vector <int> v){
	for(int i=0; i<v.size(); i++)
		cout<<v[i];
	cout<<endl;
}

int numberise(vector <int> v){
	int k=0;
	for(int i=v.size()-1; i>=0; i--){
		k += v[i];
		k *= 10;
	}
	return k/10;
} 

int generate(vector <int> &v, int l, int n){
	if(l <= n){
		int sum=0;
		for(int i=4; i<=6; i++){
			v.push_back(i);
			sum += generate(v, l+1, n);
			v.erase(v.end() - 1);
		}
		return sum + numberise(v);
	 }
	 else
		 return 0;
}

int getlevel(vector <int> &v, int num, int key){
	if(num < key){
		int sum=0;
		for(int i=4; i<=6; i++){
			v.push_back(i);
			sum = 1 + getlevel(v, numberise(v), key);
			v.erase(v.end() - 1);
		}
		return sum;
	 }
	 else if(num >= key)
		 return 0;
	
}

int main()
{
	int k;
	cin >> k;
	vector <int> v;
	cout << endl << getlevel(v, 0, 466546) << endl; 
	cout << "sum of all nos with no of digits at most " << k << " is = "<< generate(v, 0, k) << endl;
	
	return 0;
}		 
