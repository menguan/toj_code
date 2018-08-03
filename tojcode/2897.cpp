#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdio.h>
using namespace std;
int main() {
     char ch;
     double t,d,h;
     int i;
     while(1){
         t=d=h=-1;
         for(i = 0; i<2 ;i++){
             cin>>ch;
             if(ch=='E')
                 return 0;
             else if(ch=='T')
                 cin>>t;
             else if(ch=='D')
                 cin>>d;
             else if(ch=='H')
                 cin>>h;
         }
               if(h==-1)
                   h=t+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10);
                 else if(t==-1)
                    t=h-0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10);
                 else if(d==-1)
                      d=1/((1/273.16)-((log((((h-t)/0.5555)+10.0)/6.11))/5417.7530))-273.16;
               cout<<setprecision(1)<<fixed<<"T "<<t<<" D "<<d<<" H "<<h<<endl;
     }
    return 0;
}
