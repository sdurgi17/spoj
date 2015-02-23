#include <iostream>
#include <vector>
#include <climits>

using namespace std;
struct comp {
	int agency;
	int salary;
	int severence;
};

int min_cost(int cost, int emps, comp &e, int month, vector<int> &p);
int min_cost_dynamic(int emps, comp &e, int month, vector<int> &p, int arr[][24] );

int v[40];

int main()
{
	int n;
	cin >> n;
	int c = 1;
		
	while(n) {

		vector<int> p;
		comp e;
	
		cin >> e.agency;	
		cin >> e.salary;	
		cin >> e.severence;	

		for ( int i = 0; i < n; i++ ) {
			int k;
			cin >> k;
			p.push_back(k);
		}

		int arr[300][24];

		for ( int i = 0; i < 24; i++ ) {
			for ( int j = 0; j < 300; j++ ) {
				arr[i][j] = -1;
			}
		}

		cout << "Case " << c << ", cost = $" << min_cost_dynamic( 0, e, 0, p, arr ) << endl; 
		c++;

		cin >> n;
	}
 	
	cout << "monthly requirements " << endl;
	for ( int i = 0; i < 24; i++ ) {
		cout << v[i] << " ";
	}

	return 0;
}

int min_cost(int cost, int emps, comp &e, int month, vector<int> &p) {
	if ( month > p.size() - 1 ) {
		return cost;
	}

	if ( p[month] >= emps ) {
		cost += ( p[month] - emps ) * e.agency + p[month] * e.salary;
		return  min_cost(cost, p[month], e, month + 1, p);
	} else {
		int min = INT_MAX;
		int tmp_cost;

		for ( int i = p[month]; i <= emps; i++ ) {
			int cst_tmp = cost + ( emps - i ) * e.severence + ( i * e.salary );
			int cst_inst = min_cost( cst_tmp, i, e, month + 1, p);
					
			if ( cst_inst < min ) {
				min = cst_inst;
			}
		}
		
		return min;
	}
}

/*
int min_cost_dynamic(int emps, comp &e, int month, vector<int> &p, int arr[][24] ) {
	if ( month > p.size() - 1 ) {
		return 0;
	}
	
	if ( arr[emps][month] != -1 ) {
		return arr[emps][month];
	}

	if ( p[month] >= emps ) {
		arr[emps][month] = ( p[month] - emps ) * e.agency + p[month] * e.salary + min_cost_dynamic(p[month], e, month + 1, p, arr );
		return arr[emps][month];
	} else {
		int min = INT_MAX;
		
		for ( int i = p[month]; i <= emps; i++ ) {
			int cst_inst = (emps - i ) * e.severence + ( i * e.salary ) + min_cost_dynamic(i, e, month + 1, p, arr);

			if ( cst_inst < min ) {
				min = cst_inst;
			}
		}

		arr[emps][month] = min;
	
		return arr[emps][month];
	}
}
*/

int min_cost_dynamic(int emps, comp &e, int month, vector<int> &p, int arr[][24] ) {
	if ( month > p.size() - 1 ) {
		return 0;
	}
	
	if ( arr[emps][month] != -1 ) {
		return arr[emps][month];
	}

	if ( p[month] >= emps ) {
		arr[emps][month] = ( p[month] - emps ) * e.agency + p[month] * e.salary + min_cost_dynamic(p[month], e, month + 1, p, arr );
		v[month] = p[month];

		return arr[emps][month];
	} else {
		int min = INT_MAX;
		
		for ( int i = p[month]; i <= emps; i++ ) {
			int cst_inst = (emps - i ) * e.severence + ( i * e.salary ) + min_cost_dynamic(i, e, month + 1, p, arr);

			if ( cst_inst < min ) {
				min = cst_inst;
				v[month] = i;		
			}
		}

		arr[emps][month] = min;
	
		return arr[emps][month];
	}
}
