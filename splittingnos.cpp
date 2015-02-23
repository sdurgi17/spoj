#include <iostream>

using namespace std;

int main()
{
	int tests;
	cin>>tests;
	while(tests-- > 0){
		long long int n, k;
		cin>>n;
		cin>>k;
		if(k==0)
			cout<<0<<" "<<n<<endl;
		else
			cout<<n/k<<" "<<n%k<<endl;
	}
	return 0;
}
