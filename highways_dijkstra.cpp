#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
	int vertex;
	int edge_length;
	node* next;

	node() {
		next = NULL;
	}
};

bool fn( int x ) {
	if ( x != LLONG_MAX ) {
		return true;
	} else {
		return false;
	}
}
typedef pair<long long int, int> pl;

class graph {

	int v;
	int e;

	vector<node*> arr;
	priority_queue<pl, vector<pl>, greater<pl> > Q;

	public :
		vector<long long int> distance;
		void insert( int v1, int v2, int e )  {
			node* head = arr[v1];
			node *tmp = head;
			if ( head == NULL ) {
				arr[v1] = new node;
				arr[v1]->vertex = v2;
				arr[v1]->edge_length = e;
				
				return;
			}
					
			while ( tmp -> next != NULL ) {
				tmp = tmp -> next;
			}

			 tmp -> next = new node;
			 tmp -> next ->vertex = v2;
			 tmp -> next ->edge_length = e;

			return;
		}

		long long int dijkstra(int src, int dsn ) {
			pair<long long int, int> a;
			a.first = 0;
			a.second = src;

			Q.push(a);
			int vtx = 0;
			
			while ( !Q.empty() ) {
				vtx = Q.top().second;
					
				if ( distance[vtx] >= Q.top().first ) {
					distance[vtx] = Q.top().first;
					Q.pop();
				
					if ( vtx == dsn ) {
						return distance[vtx];
					}
				
					node* tmp = arr[vtx];
					while (	tmp != NULL ) {
						if ( distance[vtx] + tmp->edge_length < distance[tmp->vertex] && distance[vtx] != LLONG_MAX) {
							pair<long long int, int> mod;
							distance[tmp->vertex] = distance[vtx] + tmp->edge_length;
							mod.second = tmp->vertex;
							mod.first = distance[tmp->vertex];
							Q.push(mod);
						}
						tmp = tmp -> next;
					}
				} else {
					Q.pop();
				}
			}
			return distance[dsn];
		}

		void print_graph() {
			for ( int i = 0; i < v; i++ ) {
				node* tmp = arr[i];
				cout << " vertex " << i  << " ";
				while ( tmp != NULL ) {
					cout << tmp -> vertex << " -> ";
					tmp = tmp -> next;
				}
				cout << endl;
			}
		}
					
		graph(int v, int e) {
		
			for ( int i = 0; i < v; i++ ) {
				arr.push_back(NULL);
				distance.push_back(LLONG_MAX);
			}
	
			this -> v = v;
			this -> e = e;
		}
};

int main()
{
	
	int t;
	cin >> t;

	for ( int j = 0; j < t; j++ ) {
		int v, e;

		cin >> v;
		cin >> e;
	
		int src, dsn;
		cin >> src;
		cin >> dsn;
	
		graph cities(v, e);

		for ( int i = 0; i < e; i++ ) {
			int v1, v2, e;
			cin >> v1;
			cin >> v2;
	
			cin >> e;
	
			cities.insert(v1 - 1, v2 -1, e );
			cities.insert(v2 - 1, v1 -1, e );
	
		}	

		long long int sol = cities.dijkstra(src - 1, dsn - 1);

		if ( sol != LLONG_MAX ) {
			cout << sol << endl;
		} else {
			cout << "NONE" << endl;
		}
	}
		
	return 0;
}
