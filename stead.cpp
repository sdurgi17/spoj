#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;
int a=0;
void print(vector <int> &assgn, int b){
	for(int i=0; i<b; i++)
		cout<<assgn[i]<<" ";
	cout<<endl;
}
void printarr(int arr[], int b){
	for(int i=0; i<b; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int permute(int cows, int b, int arr[], int start, vector <int> &assgn, int pref[][4], set <map <int, set<int> > > &ss, map <int, set<int> > &m){
	if(start == cows-1){
		if(ss.count(m) > 0)
			return 1000;
		 else{
			 map <int, set<int> > :: iterator it = m.begin();
			set <int> :: iterator ip = (it->second).begin();
			int k=0, t, min = pref[*ip][it->first], max=min;
			for( ; it!=m.end(); it++){
				for(ip = (it->second).begin(); ip!=(it->second).end(); ip++){  
					cout<<"Cow"<<*ip<<"Barn"<<it->first<<"  ";
					t = pref[*ip][it->first];
					if(t<min)
						min = t;
					if(t > max)
						max = t;
				}
			}
			cout<<endl;
			ss.insert(m);
			return (max-min+1);
		}
	}
	if(start<cows-1){
		int q=1000;
		for(int i=start; i<cows; i++){
			int tmp = arr[i];
			arr[i] = arr[start];
			arr[start] = tmp;

			set <int> se;
			int k = 0;
			bool b = true;
			int mm;
			for(int j=0; j<cows; ){
				if (b){
					mm = assgn[k];
				}
				if(mm > 0){
					se.insert(arr[j]);
					mm--;
					j++;
				}
				b = false;
				if(mm==0){
					m[k] = se;
					k++;
					se.clear();
					b = true;
				}
			}
			//ss.insert(m);
			int t = permute(cows, b, arr, start+1, assgn, pref, ss, m);
			if(t<q)
				q=t;
			m.clear();
			arr[start] = arr[i];
			arr[i] = tmp; 
		}
		return q;
	}
}

int min_range(int cows, int b, int cap[], vector <int> &assgn, int pref[][4], int arr[],  int s, set <vector <int> > &mp, set <map <int, set<int> > > &ss, 
map <int, set<int> > &m ){
	if(mp.count(assgn) > 0){
		return 1000;
	}
	else{
		mp.insert(assgn);
	}
	bool bo=true;
	for(int i=0; i<b; i++){
		if(assgn[i]>cap[i]){
			bo=false;
			break;
		}
	}
	if(!bo)
		return 1000;
	else if(s==cows){
		//cout<<"a";
		print(assgn, b);
		//int  k = 1;
		//ss.clear();
		int k = permute(cows, b, arr, 0, assgn, pref, ss, m);
		return k;
	}
	else{
		//cout<<"A"<<s<<" ";
		int q=1000;
		for(int i=0; i<b; i++){
			assgn[i]++;
			int t = min_range(cows, b, cap, assgn, pref, arr, s+1, mp, ss, m);
			if(t<q)
				q=t;
			assgn[i]--; 
		}
		return q;
	}
} 

int main()
{
	map <int, set<int> > m;
	set <vector <int> > mp;
	set <map <int, set <int> > > ss;
	int b=2, cows=3, cap[4] = {1,3,3,2}, assgn[4]={0, 0, 0, 0}, arr[6] = {1,2,3,4,5,6}, s=0;
	vector <int> v(assgn, assgn+4);
	int pref[][4] = // { {1 ,2, 3}, {2, 1, 3}, {3, 2, 1}, {1, 2, 3}};
			{ {1, 2, 3, 4},
			  {1, 3, 2, 4},
			  {2, 1, 3, 4},
			  {3, 2, 4, 1},
			  {4, 1, 2, 3},
			  {2, 4, 1, 3} };
	cout << min_range(cows, b, cap, v, pref, arr, 0, mp, ss, m) << endl;
	//cout<<permute(5, arr, 0)<<endl;
	return 0;
}
