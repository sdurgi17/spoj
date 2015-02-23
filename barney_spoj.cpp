#include <iostream>
#include <vector>

using namespace std;

void del ( int x, vector<int> &s );
void barney_dist( vector<vector <int> > &s1, int gf_num, int gf, vector<int> &p, int gfts_total ); 
void print( vector<int> s ); 
int sum( vector<int> s );

int count;
 
int main()
{
	vector<int> s1;
	int gf, n;
	vector<int> min_gfts;
	vector<int> max_gfts;

	cin >> gf;

	cin >> n;

	count = 0;

	for ( int i = 0; i < gf; i++ ) {
		int min, max;
		cin >> min;
		cin >> max;
		
		min_gfts.push_back(min);
		max_gfts.push_back(max);
		
	}
	int x;
	cin >> x;
	cin >> x;

	vector< vector<int> > possible_no_gfts;
	
	for ( int i = 0; i < gf; i++ ) {
		vector<int> temp;
		for ( int j = min_gfts[i]; j <= max_gfts[i]; j++ ) {
			temp.push_back(j);
		}
		possible_no_gfts.push_back(temp);
	}

	vector<int> p;

	barney_dist(possible_no_gfts, 0, gf, p, n);
	cout << count;

	return 0;
}

void barney_dist( vector<vector <int> > &s1, int gf_num, int gf, vector<int> &p, int gfts_totl ) 
{
	vector<int> :: iterator it;

	if ( p.size() == gf ) {
		if ( sum(p) == gfts_totl ) {
			count++;
		}
		return;
	}

	for( it = s1[gf_num].begin(); it != s1[gf_num].end(); it++ ) {
		p.push_back(*it);
		barney_dist( s1, gf_num + 1, gf, p, gfts_totl);
		del( *it, p);
	}
}

void del ( int x, vector<int> &s ) 
{
	vector<int> :: iterator it;
	
	for ( it = s.begin(); it != s.end(); it++ ) {
		if ( *it == x ) {
			s.erase(it);
			return;
		}
	}

}

void print ( vector<int> s ) 
{
	for ( int i = 0; i < s.size(); i++ ) {
		cout << s[i] << " ";
	}
	cout << endl;
}

int sum ( vector<int> s )
{
	vector<int> :: iterator it;

	int sum = 0;
	for ( it = s.begin(); it != s.end(); it++ ) {
		 sum += *it;
	}

	return sum;
}
