#include <iostream>
#include <algorithm>
#define pare pair<int, float>
using namespace std;

bool operator <(pare a, pare b){
	return (a.first < b.first);
}

float ctr;

/*void printarr(int sub[], pare ap[], int l){
	for(int i=0; i<l; i++){
		cout<<ap[sub[i]].first<<" ";
	}
	cout<<endl;
}*/ 

void prob(pare ap[], int subset[], int levels, int sum, int s, int l, int indx, float pr){
	if(s > sum ||  l == levels ){
		//printarr(subset, ap, l);
		return;
	}
	else{

		float ct;
		ctr += pr;
		//printarr(subset,ap,l);
		//cout<<indx<<endl
		for(int i=indx; i<levels ; i++){
			subset[l] = i;
			ct = (pr*(1-ap[i].second))/ap[i].second;
		
			prob(ap, subset, levels, sum, s+ap[i].first, l+1, i+1, ct);
			subset[l] = 0;
		}
	}
}
			 
			 

int main()
{
	int tests;
	cin>>tests;
	while(tests-- > 0){
	ctr = 0;
	int levels;
	cin>>levels;
	pare ap[levels], ape[levels];
	int subset[levels]; 
	int t, zero=0, one=0;

	for(int i=0; i<levels; i++){
		cin>>t;
		ap[i].first = t;
	}
	float tr;
		
	for(int i=0; i<levels; i++){
		cin>>tr;
		ap[i].second = tr/100.0;
	}
	int k = 0;
	for(int i=0; i<levels; i++){
		if(ap[i].second != 0.0 && ap[i].second != 1.0){
			ape[k] = ap[i]; 
			k++;
		}
		else if(ap[i].second == 0.0)
			zero+=ap[i].first;
		else if(ap[i].second == 1.0)
			one+=ap[i].first;

	} 
	sort(ap, ap+levels);
	/*for(int i=0; i<levels; i++)
		cout<<ap[i].first<<" "<<ap[i].second<<endl;*/
	int sum = 0;
	float pr = 1.0;
	for(int i=0; i<levels; i++){
		sum+=ap[i].first;
	}
	for(int i=0; i<k; i++){
		pr*=ape[i].second;
	}
	//cout<<pr<<endl;
	if(sum/2 < zero)
		cout<<0.0<<endl;
	else{
		prob(ape,subset,k,sum/2-zero,0,0,0,pr);
		cout<<ctr<<endl;
	}

	}//while test > 0

	return 0;
}

