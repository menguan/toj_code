#include <iostream> 
#include <cstdio> 
#include <string.h> 
using namespace std; 
 
double eps = 1e-5; 
const int N = 10010; 
double num[N]; 
int main(){ 
    int n,k; 
    while(scanf("%d%d",&n,&k) != EOF){ 
       double maxvalue = 0.0; 
       for(int i = 0; i < n; ++i){ 
           scanf("%lf",&num[i]); 
           if(maxvalue < num[i]) 
               maxvalue = num[i]; 
       } 
       double lp = 0.00,rp = maxvalue,ans = 0.0; 
       while(rp - lp > eps){ 
          double mid = (rp + lp) / 2.0; 
          int sum = 0; 
          for(int i = 0; i < n; ++i){ 
            int x = (num[i] / mid ); 
            sum += x; 
          } 
          if(sum >= k){ 
              ans = mid; 
              lp = mid; 
          } 
          else{ 
              rp = mid; 
          } 
       } 
       rp = rp * 100; 
       int yy = rp; 
       printf("%.2lf\n",yy * 0.01); 
    } 
} 
