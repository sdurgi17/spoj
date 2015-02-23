#include <iostream>

using namespace std;
bool ispalin(string s, int lb, int ub){

	bool b = (s[lb] == s[ub]);
	//cout<<s[lb]<<" "<<s[ub]<<" "<<ub-lb<<endl;
	if(lb-ub == 1 || ub==lb )
		return true;
	else
		return(b && ispalin(s, lb+1, ub-1));
	
}

int main()
{
	string s;
	cin>>s;
	cout<<ispalin(s, 0, s.size()-1)<<endl;

	return 0;
}

