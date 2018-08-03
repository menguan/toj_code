#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int a,b,c,x,y,z,n;
    kk:while(cin>>x>>y>>z>>n)
    {
        for(a=0;a<=200;a++)
        for(b=0;b<=200;b++)
        for(c=0;c<=200;c++)
          if(a*x+b*y-c*z==n)
          {  cout<<a<<" "<<b<<" "<<c<<endl;
             goto kk;
          }
        cout<<"-1"<<endl;
    }
}
          
                            
                              
