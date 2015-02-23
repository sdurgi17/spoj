#include <iostream>
#include <vector>
#define pr pair<int,int>
#define N 6

using namespace std;

vector <int> v(N);

void print(int res[2*N], int l)
{
	for(int i=0; i<l; i++)
		cout<<res[i]<<" ";
	cout<<endl;
}

void path_len(int cost, int start, int end, int l, int res[2*N], pr list[N][N], bool b[N]){
	if(start == end){
		cout<<"cost is "<<cost<<"    and path is ";
		print(res, l);
		v.assign(res, res+l); 
		return;
	}
	else{
		for(int i=0; i<N && list[start-1][i].first > 0; i++){
			pr p = list[start-1][i];
			if(b[p.first-1]){
				cout<<"yepp start" << start << " " << p.first << " " << p.second << endl;
				res[l] = p.first;
				b[p.first-1] = false;
				path_len(cost+p.second, p.first, end, l+1, res, list, b);
				b[p.first-1] = true;
			}	
		}
		return;
	}
}   

int main()
{
	pr list[N][N];
	int ct[N];
	bool bub[N];
	int res[2*N];
	for(int i=0; i<N; i++){
		bub[i] = true;
		ct[i] = 0;
		pr p(0,0);
		list[i][0] = p;
	}
		 
	int a, b, c;
	for(int i = 0; i < N-1; i++){
		cin>>a>>b>>c;

		pr p(b,c), dummy(0,0);
		list[a-1][ct[a-1]]= p;
		ct[a-1]++;
		list[a-1][ct[a-1]] = dummy;
			
		p.first = a;
		list[b-1][ct[b-1]] = p;
		ct[b-1]++;
		list[b-1][ct[b-1]] = dummy;
			
	}
	for(int i=0; i<N; i++){
		cout<<i+1<<"  ";
		for(int j=0; j<N && list[i][j].first>0; j++)
			cout << list[i][j].first << " ";
		cout<<endl;
	}
	int p=5, q=6;
	bub[p-1] = false;
	cout<<endl<<"len";
	path_len(0, p, q, 0, res, list, bub);
	cout<<endl;
	for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout<<endl;
	return 0;
}

