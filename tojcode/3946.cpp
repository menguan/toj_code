#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;int n,m;
    cin>>t;
    int minn;int temp;
    for(int i=1;i<=t;i++)
    {
       minn=1000000;
       cin>>n>>m;
       while(m--)
       {
            cin>>temp;
            if(minn>temp)
              minn=temp;
       }
       int tt=n/minn;
       cout<<"Case #"<<i<<": ";
       if(tt%2)
         cout<<"Bob"<<endl;
       else 
         cout<<"Alice"<<endl;
    }
}                        
