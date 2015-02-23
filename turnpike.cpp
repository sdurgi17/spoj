#include <iostream>
#define N 10

using namespace std;

int count(int d, int distances[N*(N-1)/2], bool free[N*(N-1)/2], int pikes[N], int lb, int ub, int n, bool b){

	int ct = 0, lb1 = (b ? 1 : 0), ub1 = (b ? n-1 : n-2);
	for(int i=ub; i<=ub1; i++){
		for(int j=0; j<nlarge; j++){
			if(free[j] && pikes[l]-pikes[i] == distances[j]){
				ct++;
				free[j] = false;
			}
		}
	}
	for(int i=lb1; i<=lb; i++){
		for(int j=0; j<nlarge; j++){
			if(free[j] && pikes[l]-pikes[i] == distances[j]){
				ct++;
				free[j] = false;
			}
		}
	}
	return ct;
}

void turnpike(int distances[N*(N-1)/2], bool free[N*(N-1)/2], int n, int nlarge, int l, int max, int lb, int ub, int pikes[N]){

	int ind;
	for(int ind=nlarge-1, ind>=0; ind--){
		if(free[ind])
			break;
	}
	if( ind == 0)
		return;
	else {

		pikes[l] = max - distances[ind];
		free[ind] = false;
		ict == ;
		if(pikes == l)
			turnpike(distances, free, n, nlarge, l+1, max, lb+1, ub, pikes);
		 
		pikes[n-l] = distances[ind];
		turnpike(distances, free, n, nlarge, l+1, max, lb, ub-1, pikes);

		bool b = true;
		for(int i=0; i<lb, i++){
			if(distances[i] == 
		turnpike


