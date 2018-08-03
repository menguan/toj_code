#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a;
    while(cin>>a,a)
    {
        double v[a],t[a];
        for(int i=0;i<a;i++)
        {
            cin>>v[i]>>t[i];
        }
        long double hhh=100000000;
        for(int i=0;i<a;i++)
        {
            if(t[i]>=0&&(((4.5/v[i])*3600+t[i])<hhh))
            hhh=(4.5/v[i])*3600+t[i];
        }
            
        cout<<ceil(hhh)<<endl;
    }
  return 0;
} 