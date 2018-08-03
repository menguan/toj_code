#include<iostream>
#include<cstring>
#include<stdio.h>
#include<iomanip>
//#include<cmath>
#define eps 1e-8
using namespace std;
double x0,y0,x1,y1,x2,y2,x3,y3,x4,y4;
void solve()
{
     double a,b,c,d;
     a=x2-x1;  
     b=y2-y1;  
     c=x4-x3;  
     d=y4-y3;  
     
     if(a*d==b*c){ 
          if((x3-x1)*b==(y3-y1)*a)   
           puts("LINE");  
            else    
            puts("NONE");  }  
     else{   
             x0=(a*d*x3-b*c*x1+a*c*y1-a*c*y3)/(a*d-b*c);   
             y0=(a*d*y1-b*c*y3+b*d*x3-b*d*x1)/(a*d-b*c);   
             printf("POINT %.2f %.2f\n",x0,y0);  
             }
}    
                                                  
int main()
{
    cout<<"INTERSECTING LINES OUTPUT"<<endl;
    int t;
    cin>>t;
    while(t--)
    {
       cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
       solve();
    } 
    cout<<"END OF OUTPUT"<<endl;        
}  
