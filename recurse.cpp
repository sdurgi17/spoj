#include <iostream>
#include <algorithm>

using namespace std;

void print(int *v, int size)
{
  if (v != 0) {
    for (int i = 0; i < size; i++) {
      cout<<v[i]<<" ";
    }
    cout<<endl;
  }
} 


void permute( int v[4], int start, int n)
{  
  if (start == n-1) {
	  print(v, n);
	//cout<<"hi"<<" start="<<start<<endl;
  }
  else {
    for (int i = start; i < n; i++) {
	cout<<"start="<<start<<" i="<<i<<endl;
  	 permute(start+1, n);
  }
  }
}


int main()
{
  int v[] = {1, 2, 3, 4};
  permute(0, 4);

  return 0;
}

