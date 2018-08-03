#include<iostream>
#include<cmath>
#define eps 1e-12
using namespace std;
const long double tt=sqrt(2.0);
int main()
{
  int x,y;
  while(cin>>x>>y)
  {
    
    int i=max(abs(x),abs(y));
    
    int num=(int)(pow(2*i+1.0,2));
       
    int ans;
    int xx=i,yy=-i;
    bool flag=0;
    if(yy==y&&!flag)
    {
      ans=num+x-xx;
      flag=1;
    }
    xx-=(2*i);
    if(xx==x&&!flag)
    {
      ans=num-(2*i)-y+yy;
      flag=1;
    }
    yy+=(2*i);
    if(yy==y&&!flag)
    {
      ans=num-(4*i)-x+xx;
      flag=1;
    }
    xx+=(2*i);
    if(xx==x&&!flag)
    {
      ans=num-(6*i)-yy+y;
      flag=1;
    }
    cout<<ans<<endl;  
      
      
  }
}    
