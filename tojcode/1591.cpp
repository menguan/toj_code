#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
  int count=1;
  int a,b,c;
  while(cin>>a>>b>>c)
  {
    if(a==0&&b==0&&c==0)
     return 0;
     
    cout<<"Triangle #"<<count++<<endl; 
    if((a<=0&&b<=0)||(a<=0&&c<=0)||(c<=0&&b<=0))
    {cout<<"Impossible."<<endl<<endl;
    continue;}
    
    if(c!=-1&&(c<a||c<b))
    {cout<<"Impossible."<<endl<<endl;
    continue;}
    
    
    if(c==-1)
    {
      double t=sqrt(1.0*a*a+b*b);
      cout<<"c = "<<setprecision(3)<<fixed<<t<<endl;
    }
    if(a==-1)
    {
      double t=sqrt(1.0*c*c-b*b);
      cout<<"a = "<<setprecision(3)<<fixed<<t<<endl;
    }
    if(b==-1)
    {
      double t=sqrt(1.0*c*c-a*a);
      cout<<"b = "<<setprecision(3)<<fixed<<t<<endl;
    }
    cout<<endl;
  }
}  