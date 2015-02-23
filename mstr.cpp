#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
        
	int a[4] = {1, 1, 1, 1};
	int b[4];
	
	int sum;
        
	while(sum != 4){
                for(int i = 0; i < 4; ++i) {
			 printf("%d ", a[i]);
		}
		cout << endl;
  	        fflush(stdout);
		       sum = 0;
          	      for(int i = 0; i < 4; i++){
                	  scanf("%d", &b[i]);
                	      
			  if (b[i] != 1) {
				a[i]++;
			  }
               	    	  sum += b[i];
		     }
        }

        return 0;       
}
