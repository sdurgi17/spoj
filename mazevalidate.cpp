#include <iostream>
#include <vector>
#define pr pair<int,int>

using namespace std;

int ii, jj;
int array[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} }; 

/*void print(vector <pr> v){
	for(int i=0; i<v.size(); i++){
		cout<<v[i].first<<","<<v[i].second<<"  ";
	}
	cout<<endl;
}*/
bool validate(char mat[][20], int m, int n){
	int ct=0;

	for(int i=0; i<m; i++){

		if(mat[i][0] == '.'){
			ct++;
			ii=i; jj=0;
		}
		if (n > 1){
			if(mat[i][n-1] == '.'){
				ct++;
				ii=i; jj=n-1;
			}
		}
	}
	for(int i=1; i<n-1; i++){

		if(mat[0][i] == '.'){
			ct++;
			ii=0; jj=i;
		}
		if(m>1){
			if(mat[m-1][i] == '.'){
				ct++;
				ii=m-1; jj=i;
			}
		}
	}

	return (ct==2);
}

bool valid(char mat[][20], int m, int n, int i, int j, vector <pr> &vstd){
	if(i<0 || i>m-1 || j<0 || j>n-1)
		return false;
	else if(mat[i][j] == '#')
		return false;
	else if((mat[i][j] == '.') && (i==0 || i==m-1 || j==0 || j==n-1) && (i!=ii || j!=jj)){
		//print(vstd);
		return true;
	}
	else{
		bool x = false;
		for(int k=0; k<4; k++){
			bool b = true;
			if (!(i+array[k][0] < 0 || i+array[k][0] > m-1 || j+array[k][1] < 0 || j+array[k][1] > n-1)){
				for(int l=0; l<vstd.size(); l++){
					if(vstd[l].first == i+array[k][0] && vstd[l].second == j+array[k][1]){
						b = false;
						break;
					}
				} 
				if(b){
					pr p(i+array[k][0], j+array[k][1]);
					vstd.push_back(p); 
					x = x || valid(mat, m, n, i+array[k][0], j+array[k][1], vstd);
					vstd.erase(vstd.end()-1);
				}
			}
		}
		return x;
	}
}   		

int main()
{
	int tests;
	cin>>tests;
	while(tests-- > 0){
	int m, n;
	cin >> m >> n;
	char mat[m][20];// = {{'x', 'x', 'x', 'x'}, {'.', '.', '.', 'x'}, {'x', 'x' ,'.', 'x'}};
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> mat[i][j];
		}
	}
	vector <pr> vstd;
	if(validate(mat, m, n)){
		pr p(ii, jj);
		vstd.push_back(p);
		//cout<<"prelim pased"<<endl;
		//cout<<ii<<" iinjj "<<jj<<endl;
		if(valid(mat, m, n, ii, jj, vstd))
			cout<<"valid"<<endl;
		else
			cout<<"invalid"<<endl;
	}
	else
		cout<<"invalid"<<endl;
	}
	
	return 0;
}
