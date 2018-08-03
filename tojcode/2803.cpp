#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        double a,b,c;
        cin>>a>>b>>c;
        double d=b*b-4*a*c;
        if(d<0)
          cout<<"No solution!"<<endl;
        else  if(abs(d-0)<0.000000001)
        {
            double t=b*(-1)/(2*a);
            cout<<setprecision(3)<<fixed<<t<<endl;
        }
        else  
        {
            double t1= (b*(-1)-sqrt(d))/(2*a);
            double t2= (b*(-1)+sqrt(d))/(2*a);
            cout<<setprecision(3)<<fixed<<t1<<" "<<t2<<endl;     
        }
    }
    return 0;
}  