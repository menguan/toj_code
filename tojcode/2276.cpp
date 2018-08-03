#include<iostream>   
#include<stdio.h>
#include<cmath>
using namespace std;
struct Point 
{    
          double x, y;
}p[10000]; 
double polygon_area(int n)
{          if(n<3) return 0 ;
    double s = p[0].y * (p[n-1].x - p[1].x) ;
        for(int i = 1 ; i < n ; i ++)
               s += p[i].y * (p[i-1].x - p[(i+1)%n].x );
                   return abs(s/2) ;} 
int main(){       
    int n;      
    while(cin>>n,n>=3)    
    {             
                  for(int i=0;i<n;++i)
                  cin>>p[i].x>>p[i].y;
                  double v;            
                  cin>>v;          
                  printf("BAR LENGTH: %.2f\n",v/polygon_area(n));
    }
}
