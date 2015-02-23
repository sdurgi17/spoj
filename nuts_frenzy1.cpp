#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include<cstdlib>

using namespace std;

void prime_generator( vector<int> &prime );
bool is_prime( int n );
void print( vector<int> v );
int prime_div(long long int &k, int p );
long long int sum_of_factors( long long int k, vector<int> prime );
int time_taken( long long int k, long long int rate);

int main()
{
	vector<int> prime;
	prime_generator( prime );
	
	int t;
	cin >> t;
	srand(127);

	for ( int i = 0; i < t; i++ ) {
		long long int k;
		long long int i;
		long long int f;
		k = rand();
		i = rand()%1000000;
		f = rand()%100;
		cout<<k <<" "<< i <<" "<< f<<endl;

		cout << time_taken(k, i) << " ";
		if ( f != 0 ) {
			cout << time_taken(k, (k/f)) << " ";
		} else {
			cout << k << " ";
		}

		cout << time_taken(k, sum_of_factors(k, prime) - k - 1) << endl;
		//getchar();
	}
	
	return 0;
}

void prime_generator( vector<int> &prime ) {
	prime.push_back(2);

	for ( int i = 3; i < 32000; i++ ) {
		if ( is_prime(i) ) {
			prime.push_back(i);
		}
	}
	
//	cout << " prime size " << prime.size() << endl;
}
	
bool is_prime( int n ) {
	for ( int i = 2; i < sqrt(n) + 1; i++ ) {
		if ( n % i == 0 ) {
			return false;
		}
	}

	return true;
}

long long int sum_of_factors( long long int k, vector<int> prime ) {
	long long int sum = 1;

	for ( int i = 0; ( i < prime.size() && prime[i] <= k ); i++ ) {
//		cout << i << " " << prime[i] << endl;
		int n = prime_div(k, prime[i] );
		sum *= ( ( pow(prime[i], n + 1) - 1 ) / (prime[i] - 1) );
	}
	
	if ( k != 1 ) {
		sum *= ( (k*k - 1 ) / (k - 1) );
	}

	return sum;
}

int prime_div(long long int &k,int p ) {
	int ctr = 0;
	
	if ( k <= 1) {
		return ctr;
	}

	while ( k % p == 0 ) {
		ctr++;
		k = k / p;
	}
	
	return ctr;
}

void print( vector<int> v ) {
	for ( int i = 0; i < v.size(); i++ ) {
		cout << v[i] << endl;
		getchar();
	}
}

int time_taken( long long int k, long long int rate ) {
	int time = 0;
	
	if ( rate <= 1 ) {
		rate = 1;
	}

	time = k / rate;

	if ( k % rate != 0 ) {
		time++;
	}

	return time;
}
