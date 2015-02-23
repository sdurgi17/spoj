#include <iostream>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

bool check_validity( stack<int> &s, vector<int>& q);
int main()
{
	stack<int> s;
	vector<int> q;
	vector<bool> sol;
	int n;
	cin >> n;
	
	while (n ) { 
		for ( int i = 0; i < n; i++ ) {
			int tmp;
			cin >> tmp;
			q.push_back(tmp);
		}
	
		if ( check_validity(s, q) ) {
			sol.push_back(true);
		} else {
			sol.push_back(false);
		}
	
		cin >> n;
	}

	for ( int i = 0; i < sol.size(); i++ ) {
		if (sol[i] ) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}

	return 0;
}

bool check_validity(stack<int> &s, vector<int>& q ) {
	
	vector<int> :: iterator it;

	while( q.size() ) {
		it = min_element( q.begin(), q.end() );
		int min = *it;
		
		if ( q[0] == min ) {
			if ( !s.empty() ) {
				if ( q[0] <= s.top() ) {
					q.erase(q.begin());
				} else {
					s.pop();
				}
			} else {
				q.erase(q.begin());
			}

		}else if ( s.empty() ) {
			s.push(q[0]);
			q.erase(q.begin());
		} else {
			if ( q[0] <= s.top() ) {
				s.push(q[0] );
				q.erase(q.begin());	
			} else {
				if ( s.top() <= min ) {
					s.pop();
				} else {
					return false;
				}
			}
		}
	}
	
	return true;
}
