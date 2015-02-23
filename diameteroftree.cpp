#include <iostream>

using namespace std;

class node{
	public:
	node *left;
	node *right;
	int val;
};

int max(int a, int b){
	return (a>b ? a:b);
}
node* create(int a)
{
	node *r = new node();
	r->val = a;
	r->left = NULL;
	r->right = NULL;
	
	return r;
}

void print(node *h)
{
	if(h!=NULL){
		print(h->left);
		print(h->right);
		cout<<h->val<<" ";
	}
}	
	
void create_tree(node *root, int l, int arr[]){
	node *n = create(arr[l]);
	node *p;
	while(root != NULL){
		p = root;
		if(root->val > arr[l])
			root=root->left;
		else
			root=root->right;
	}
	if(p->val > arr[l])
		p->left=n;
	else
		p->right=n;
}		
int maxht(node *root){
	if(root==NULL){
		return 0;
	}
	else{
		int a = 1 + maxht(root->left);
		int b = 1 + maxht(root->right);
		return max(a,b);
	}
} 
int diameter(node *root){
	if(root!=NULL){
	int p=diameter(root->left);
	int q=diameter(root->right);
	int r=maxht(root->right) + maxht(root->left) + 1;
	return max(max(p,q), r);
	}
	else
		return 0;
}
	
int height( node *root, int *p) {
	if ( root == NULL ) {
		return 0;
	}	
		int a = 1 + height(root->left, p);
		int b = 1 + height(root->right, p);
		int c = max(a,b);
		if ( (  a + b - 1) > *p ) {
			*p = a + b -1;
		}
		return c;
}	
int main()
{
	int arr[] = {40, 10, 20, 19, 18, 17, 16, 21, 22, 23, 24, 25}; 
	node *h = create(arr[0]);
	for(int i=1; i<12; i++){
		create_tree(h, i, arr);
		cout<<"maxht"<<maxht(h)<<endl;
	}
	print(h);
	cout<<endl;
	cout<<"dia"<<diameter(h)<<endl;
	int pp = -1, *p = &pp;
	//*p = -1;
	int k = height(h, p);
	cout << "diametre "  << *p << endl;

	return 0;
}
