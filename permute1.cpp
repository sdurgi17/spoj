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


void permute(int *v, int start, int n)
{  
  if (start == n-1) {
    print(v, n);
  }
  else {
    for (int i = start; i < n; i++){ 
     
      int tmp = v[i];         //swap v[start] and v[i]
      v[i] = v[start];
      v[start] = tmp;
   
      permute(v, start+1, n);
     
      v[start] = v[i];       //undo swap v[start] and v[i]
      v[i] = tmp;
    }
  }
}


int main()
{
  int v[] = {1, 2, 3};
  permute(v, 0, sizeof(v)/sizeof(int));

  return 0;
}

