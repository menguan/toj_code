#include <iostream>
#include <cmath>

#define eps 0.000001
const double pi=acos(-1.0);

using namespace std;

int main()
{
    double d,h,a,b,c,ans;
    cin>>d>>h;
    while(cin>>a>>b>>c)
    {
      if(a<=eps||b<=eps||c<=eps)
        return 0;
      a=tan(a/180.0*pi);
      b=tan(b/180.0*pi);
      c=tan(c/180.0*pi);
      ans=d*sqrt(2.0/(1.0/a/a+1.0/c/c-2.0/b/b))+h;
      
      if(ans-(int)ans<0.5) 
        cout<<(int)ans<<endl;
      else
        cout<<(int)ans+1<<endl;
    }
    return 0;
}