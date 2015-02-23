#include <iostream>
#include <vector>

using namespace std;


struct vertex {
	int v;
	int e;
	int prnt;

	vertex* next;

	vertex() {
		next = NULL;
		prnt = -1;
	}
};

bool operator<(vertex a, vertex b ) {
	return (a.e < b.e);
}

class graph {

	public :
	
	int total_weight;
	vector<vertex*> G;
	vector<int> parent;
	vector<bool> visited;
	vector< vector<int> > adj_mat;
	int vertices;

	void insert( int v1, int v2, int e ) {
		vertex* head = G[v1];
		
		if ( e == 0 ) {
			return;
		}

		if ( head == NULL ) {
			G[v1] = new vertex;
			G[v1]->e = e;
			G[v1]->v = v2;
			G[v1]->prnt = v1;
			
			return;
		}

		while ( head->next != NULL ) {
			head = head->next; 
		}

		head->next = new vertex;
		head->next->e = e;
		head->next->v = v2;
	}
	
	void print_graph() {
		for ( int i = 0; i < G.size(); i++ ) {
			cout << " vertex " << i << " :::  ";
			print(G[i]);
		}
	}

	void print(vertex* head) {
		if ( head == NULL ) {
			 cout << " NULL " << endl;
			 return;
		} else {
			cout << head->v<< " -> ";
			print(head->next);
		}
	}

	graph(int v, int e ) {
		vertex* tmp = NULL;
	
		for ( int i = 0; i < v; i++ ) {
			G.push_back(tmp);
		}

		for ( int i = 0; i < e; i++ ) {
			int v1;
			int v2;
			int e = 1;

			cin >> v1;
			cin >> v2;
			cin >> e;
	
			insert(v1, v2, e);
			insert(v2, v1, e);
		}
	
	}

};

int main()
{
	return 0;
}
