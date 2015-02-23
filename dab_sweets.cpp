#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

long double probability(vector<long double> &v, int s_no ) {
	return ( v[s_no] / (v[0] + v[1] + v[2]) );
}

long double bayes(vector<vector<long double> > &v, int n, char sweet ) {
	int s_no;
	if (sweet == 'L')		
	{
		s_no = 0;
	} else if (sweet == 'G')		
	{
		s_no = 1;
	}
	if (sweet == 'R')		
	{
		s_no = 2;
	}

	long double p1 = probability(v[n - 1], s_no);
	long double p_total = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		p_total += probability(v[i], s_no);	
	}

	return (p1/ p_total);
} 

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)	{
		vector<vector<long double> > v;
		int k;
		cin >> k;

		for (int i = 0; i < k; ++i){
				vector<long double> s;
				long double l;
				long double g;
				long double r;

				cin >> l;
				cin >> g;
				cin >> r;
				
				s.push_back(l);
				s.push_back(g);
				s.push_back(r);
				
				v.push_back(s);
		}

		long double n;
		cin >> n;

		char sweet;
		cin >> sweet;

		printf("%.9LF\n", bayes(v, n, sweet));
	}	
	
	return 0;
}
