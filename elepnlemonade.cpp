#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int tests;
	cin>>tests;
	while(tests-- > 0){
	        vector < priority_queue <int> > roomlist;
	        vector <int>  visits;
		int n, m, t, tt;
		cin>>n;
		cin>>m;
		for(int i=0; i<m; i++){
			cin>>t;
			visits.push_back(t);
		}
		for(int i=0; i<n; i++){
			cin>>t;
			priority_queue <int> pq;
			for(int j=0; j<t; j++){
				cin>>tt;
				pq.push(tt);
			}
			roomlist.push_back(pq);
		}
		int sum = 0;
		for(int i=0; i<m; i++){
			if(!roomlist[visits[i]].empty()){
				sum += roomlist[visits[i]].top();
				roomlist[visits[i]].pop();
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

				
				


