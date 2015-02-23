#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> &g ) {
	for ( int i = 0; i < g.size(); i++ ) {
		cout << g[i] << " ";
	}
	printf("\n");
}

void del( vector<int> &g, vector< vector<int> > &pp, vector<int> &judge ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( judge[i] != 1 ) {
			remove(pp[i].begin(), pp[i].end(), g[i]);
		} else  {
			pp[i][0] = g[i];
		}
	}
}

int main()
{
	int known = 0;
	vector<int> g;
	vector<int> p;
	
	for ( int i = 0; i < 6; i++ ) {
		p.push_back(i + 1);
	}
	
	vector< vector<int> > pp;
	
	for ( int i = 0; i < 4; i++ ) {
		pp.push_back(p);
	}
			
	vector<int> judge;
		
	while ( count(judge.begin(), judge.end(), 1 ) < 4 ) {
		judge.clear();
		for ( int i = 0; i < 4; i++ ) {
			g.push_back(pp[i][0]);
		}

		print(g);
		fflush(stdout);			
		for ( int i = 0; i < 4; i++ ) {
			int j;
			cin >> j;

			judge.push_back(j);
		}
		
		del(g, pp, judge);
		g.clear();
	}
				
	return 0;
}
