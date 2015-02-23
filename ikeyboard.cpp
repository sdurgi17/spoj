#include <iostream>
#include <vector>
#define pr pair<char,char>

using namespace std;

pr result[100];
int c=10000;

void print(pr list[100], int l){
	//cout<<"hi";
	for(int i=0; i<l; i++){
		cout<<i+1<<": ";
		if(list[i].first == list[i].second)
			cout<<list[i].first<<endl;
		else
			cout<<list[i].first<<"-"<<list[i].second<<endl;
	}
	cout<<endl;
} 

int minstrokes(int arr[100], pr list[100], int l, int level, char ub, int cost){
	if(l == level && list[l-1].second != ub){
		//cout<<cost<<" ";
		//print(list,l);
		return 10000;
	}
	else if(l>0 && list[l-1].second == ub){
		//cout<<"cost = "<<cost<<endl;
		//print(list,l);
		if(c>cost){
			c = cost;
			for(int i=0; i<l; i++)
				result[i] = list[i];
		}
		return 0;
	}
	else{
	int sum = 10000;
	char k;
	if(l==0)
		k = 'a';
	else
		k = (char)(list[l-1].second + 1);
	char ch=k;
	for(ch = k; ch <= ub; ch++){
		int s = 0;
		pr p;
		p.first = k;
		p.second = ch;
		list[l] = p;
		//print(list, l);
		//cout<<list[l].first<<" "<<list[l].second<<" "<<ub<<endl;
		for(char charc = k; charc <= ch; charc++){
			int j;
			for(j=0; !(charc >= list[j].first && charc <= list[j].second); j++);
			s += (charc - list[j].first + 1) * arr[charc - 'a'];
			//cout<<s<<" "<<charc-list[j].first+1<<" "<<list[j].first<<" "<<list[j].second<<"   ";
		}
		//cout<<" "<<k<<endl;
		s += minstrokes(arr, list, l+1, level, ub, cost + s);
		if(sum >  s){
			sum = s; 
		}
		list[l].first = '?';
		list[l].second = '?';
	}
	return sum;
	}
}
			 
int main()
{
	pr list[100];
	int arr[100]; /*= {20, 5, 7, 18, 20, 
			4, 2, 4, 4, 99,
			4, 4, 2, 2, 23,
			45, 4, 4, 9, 4,
			5, 4, 44, 4, 4, 7};*/
	
	char ch;
	cin >> ch;
	for(int i=0; i<26; i++)
		arr[i] = 5;
	cout<<endl;
	int k;
	cin>>k;
	cout << endl << minstrokes(arr, list, 0, k, ch, 0) << endl;

	print(result, k);
	cout<<"cost is "<<c<<endl;

	return 0;
}
