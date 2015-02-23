#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyz";

struct node {
	bool presence;
	vector<node* > v;

	node () {
		for ( int i = 0; i < 26; i++ ) {
			v.push_back(NULL);
		}
		
		presence = false;
	}
};

class trie {
	node* head;

	public :

	void insert(string &s ) {
		node* tmp = head;
		for ( int i = 0; i < s.size(); i++ ) {
			if ( tmp->v[s[i] - 97] == NULL ) {
				tmp->v[s[i] - 97] = new node;
			}
			if ( i == s.size() - 1) {
				tmp->v[s[i] - 97]->presence = true;
				break;
			}
			tmp = tmp->v[s[i] - 97];
		}
	}
	
	node* search(string &s) {
		node* tmp = head;
		for ( int i = 0; i < s.size(); i++ ) {
			int index = s[i] - 97;
			if ( tmp->v[index] == NULL ) {
				return NULL;
			} if ( i == s.size() - 1) {
				return (tmp->v[index]);
			}
			
			tmp = tmp->v[index];
		}
	}
			
	void print_all_similar( node* head, string &s ) {
		if ( head == NULL ) 
			return;
		if ( head->presence ) {
			cout << s << endl;
			string s2 = s;				
			for ( int i = 0; i < (head->v).size(); i++ ) {
				if ( head->v[i] != NULL ) {
					s2 += alpha[i];
					print_all_similar(head->v[i], s2 );
					s2[s2.size() - 1] = '\0';
				}
			}

			return;
		}
	
		string s2 = s;				
		for ( int i = 0; i < (head->v).size(); i++ ) {
			if ( head->v[i] != NULL ) {
				s2 += alpha[i];
				print_all_similar(head->v[i], s2 );
				s2.erase(s2.end() - 1);
			}
		}
	}
	
	void print_all( node* head, string &s ) {
		if ( head == NULL )  {
			return;
		} 

		if ( head->presence ) {
			printf("%s\n",s.c_str());
		}

		for ( int i = 0; i < (head->v).size(); i++ ) {
			if ( head->v[i] != NULL ) {
				s += alpha[i];
				print_all(head->v[i], s);
				s.erase(s.end() - 1);
			}
		}
	}

	trie() {
		head = new node;
	}
};

int main() 
{
	
	trie t;
	int n;
	scanf("%d", &n);

	for ( int i = 0; i < n; i++ ) {
		string s;
		cin >> s;
		
		t.insert(s);
	}

	int k;
	scanf("%d", &k);

	for ( int i = 0; i < k; i++ ) {
		string s;
		cin >> s;

		cout << "Case #" << i + 1 << ":" << endl;
		node* srch = t.search(s);

		if ( srch != NULL  ) {
			if ( srch->presence ) {
				srch->presence = false;
				t.print_all(srch, s);
				srch->presence = true;
			} else {
				t.print_all(srch, s);
			}

		} else {
			cout << "No match." << endl;
		}
	}

	return 0;
}
