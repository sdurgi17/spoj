#include <iostream>

using namespace std;

int main()
{
	int tests;
	cin>>tests;
	while(tests-- > 0){
		float d;
		int u, n;
		cin>>d>>u>>n;
		int best = 0;
		float rate = d*u, rt = rate;
		int m, c;
		float r;
		for(int i=0; i<n; i++){
			cin>>m>>r>>c;
			rt = ((float)c/(float)m) + r*(float)u;
			if(rt < rate){
				rate = rt;
				best = i+1;
			}
			//cout<<rate <<" "<<rt<<endl;
		}
		cout<<best<<endl;
	}
	return 0;
}
		
