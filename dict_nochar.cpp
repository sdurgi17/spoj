#include <iostream>
#include <cstdio>

using namespace std;

int flag=0;

class node{
	public:
	node *next[26];
	//char ch;
	bool b;
};

node *mk(){
	node *n = new node;
	n ->  b =  false;
	for(int i = 0; i < 26; i++)
		n->next[i] = NULL;
	return n;
}

void recur(node *head, string s, string &root){
	if(head!=NULL){
		if(head->b && s!=root){
			flag=1;
			printf("%s\n", s.c_str());
		}
		for(int i=0; i<26; i++){
			if ( head->next[i] != NULL ) {
				recur(head->next[i], s+(char)('a'+i), root);
			}
		}
	}
}
				
int main()
{
	int n;
	cin>>n;
	node *head = mk(), *h = NULL;
	//cout<<"hi"<<(int)head->ch;
	string s;
//	char *s;
	int indx, ct;
	while(n-- > 0){
		h = head;
		cin >> s;
	//	scanf("%s", s);
		for(int i=0; i<s.size(); i++){
			indx = (int)(s[i] - 'a');
			if(h->next[indx] == NULL){
				node *p = mk(); 
				h->next[indx] = p;
			}
			h = h->next[indx];
			if(i== s.size() - 1)
				h->b = true;
			//cout<<h->ch<<indx<<" "; 

		}
	}

	scanf("%d", &n);
	int t = 1;
	while(n-- > 0){
		cin >> s;
	//	scanf("%s", s);
		h = head;
		ct=0;
		while(h!=NULL && ct < s.size()){
			indx = (int)(s[ct++] - 'a');
			h = h->next[indx];
			//cout<<h->ch<<" ";
		}
		printf("Case #%d:\n", t);
		if(h!=NULL)		
			recur(h, s, s);
		if(flag == 0) 
			printf("No match.\n");
		flag=0;
		t++;
	} 
	
	return 0;
}


	
