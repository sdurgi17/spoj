#include <iostream>

struct vid {
	int n;
	int next;
	int loopDist;
	int loopL;
	bool visited;
};

void videoM(vector<int> &studs, vector<vid> &v, int k, int m);
int main(int argc, char const *argv[])
{
	int n;
	int k;
	int m;

	cin >> n;	
	cin >> k;	
	cin >> m;

	vector<int> studs;
	for (int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			studs.push_back(tmp);
	}	

	vector<vid> v;
	for (int i = 0; i < k; ++i){
		vid tmp;
		cin >> tmp.next;	
		v.push_back(tmp);
	}

	videoM(studs, v, k, m);

	return 0;
}

void videoM(vector<int> &studs, vector<vid> &v, int k, int m) {
	for ( int i = 0; i < v.size(); i++ ) {
		if ( !v[i].visited ) {	
			setGraphStats( v, i);
		}
	}

}

void setGraphStats( vector<vid> &v, int i ) {

}
