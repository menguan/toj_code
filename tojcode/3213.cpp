#include<iostream>
#include<iomanip>
#include<cmath>
const double pi=3.1415926535; 
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        double r,R,H,HH,V,h;
        cin>>r>>R>>H>>V;
        if(abs(R-r)<0.000000000001)
        {
            h=V/(pi*r*r);
            if(h>H)
            h=H;
            cout<<setprecision(6)<<fixed<<h<<endl;
            continue;
        }
        else
        {
            HH=(H*r)/(R-r);
            double VH=pi*r*r*HH/3;
            double k=VH/(VH+V);
            int y=3;
            double t=pow(k,1.0/y);
            h=(HH-HH*t)/t;
            if(h>H)
            h=H;
            cout<<setprecision(6)<<fixed<<h<<endl;
            continue; 
        }
   }
   return 0;
} 