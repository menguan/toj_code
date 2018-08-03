#include <iostream>
#include <cmath>
using namespace std;

int solve(int n){
     	int ret = 0, cnt = 0;
      	for (int i = 30; i >= 0; --i) 
       {		if ((int)pow(2.0,i) < n) 
       {			n -= (int)pow(2.0,i);			
       ret += (int)pow(2.0,i+1);		
       	cnt++;		
       }	}	return ret + cnt % 2;
   }
int main(){	
       int t, n;	
       	
       cin >> t;	
       while (t--) 
       {		cin >> n;		
       cout << solve(n + 1) << endl;	}	
       return 0;}