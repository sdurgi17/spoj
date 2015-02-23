#include <iostream>
#include <vector>
#define N 5

using namespace std;

struct node{
	int val;
	int freq;
	node *left;
	node *right;
};

class queue{
	public:
	vector < node * > arr;
	int size;
	queue(){
		size=0;
	}

	void heapify (int i){

		int min = i;
		if(i*2+1 < size && arr[i*2+1]->freq < arr[i]->freq)
			min = i*2+1;
		if(i*2+2 < size && arr[i*2+2]->freq < arr[min]->freq)
			min = i*2+2;

		if(i!=min){
			node *tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
			heapify(min);
		}
	} 
	 
	void minheap(){
		for(int i=(size-1)/2; i>=0; i--){
			heapify(i);
		}
	}

	node* min(){
		minheap();
		return arr[0];
	}

	void pop(){
		arr.erase(arr.begin());
		size--; 
	}

	void push(node *l, node *r){
		node *n = new node();
		n->left = l;
		n->right = r;
		n->freq = l->freq + r->freq; 
		arr.push_back(n);
		size++;
	}

	void insert(int num){
		node *n = new node();
		n->left = NULL;
		n->right = NULL;
		n->freq = num;
		arr.push_back(n);
		size++;
	}
	int length(){
		return size;
	}
	
	void printarr(){
		for(int i=0; i<size; i++){
			cout<<arr[i]->freq<<" ";
		}
		cout<<endl;
	}
	void huffman(){
		while(size > 1){
			node *l = min();
			pop();
			node *r = min();
			pop();
			push(l, r);
		}
	}
};

void print(node* root, string &s){
	if(root!=NULL){
		if(root->left == NULL && root->right == NULL)
			cout<<root->freq<<"  "<<s<<endl;
		s += "0";
		print(root->left, s);
		s.erase(s.length()-1);
		s += "1";
		print(root->right, s);
		s.erase(s.length() - 1);
	}
}

int main()
{
	queue q;
	string s("");
	int freq;
	for(int i=0; i<N; i++){
		cin>>freq;
		q.insert(freq);
	}
	q.huffman();
	node *r = q.arr[0];  
	print(r, s);
	cout<<endl;

	return 0;
}
