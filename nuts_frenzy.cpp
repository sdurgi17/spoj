#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define N 3200

using namespace std;

long long int time(long long int max_sp, long long int nuts) {
	int i = nuts / max_sp;
	if(nuts % max_sp == 0)
		return i;  
	return i + 1;
}

bool isprime(long long int num) {
	for(long long int i = 2; i <= (long long int)sqrt(num); i++) { 
		if(num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int cases, ctr = 0;
	long long int kk_max;

	vector <long long int> primes;
	vector <long long int> pno;

	cin >> cases;

	while(ctr < cases) {
		long long int i, s = 1, tmp, ct, t, flag, ii, kk, ff;
		cin>>kk;
		cin>>ii;
		cin>>ff;
		long long int root = (kk / 2);
		if(ctr == 0) {
			kk_max = root;
			for(i = 2; i <= kk_max; i++) {
				if(isprime(i))
					primes.push_back(i);
			}
		}	 
		else if(kk_max < root){
			for(i = kk_max + 1; i <= root; i++) {
				if(isprime(i))
					primes.push_back(i);
		 	}
			kk_max = root;
		}

		tmp = kk; 

		for(int p = 0; p < primes.size() && primes[p] <= root; p++) {
			ct = 0;
			flag = 0;
			i = primes[p]; 
			while(tmp % i == 0) {
				ct++;
				tmp = tmp / i;
				flag = 1;
			}
			if(flag == 1) {
				t = (pow(i, ct + 1) - 1) / (i - 1);
			//cout<<"i="<<i<<" ct="<<ct<<" tmp="<<tmp<<" t="<<t<<endl; 
			s *= t;
			}	
		}
		if (s > 1)
			s = s - 1 - kk; 
	
		//cout<<endl<<"s = "<<s<<endl;
		
		long long int ivan_sp = ii, filbert_sp = kk / ff, tracy_sp = s, nuts = kk;
		if(filbert_sp == 0)
			filbert_sp = 1;

		//cout<<endl<<ivan_sp<<" "<<filbert_sp<<" "<<tracy_sp<<" "<<nuts<<endl;
		cout << time(ivan_sp, nuts) << " " << time(filbert_sp, nuts) << " " << time(tracy_sp, nuts) << endl;
		ctr++;
	}

	return 0;
}
