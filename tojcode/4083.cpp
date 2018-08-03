#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
double x[1000];
int main()
{
    int t;
    cin>>t;int n;int typ;double y,a,b;
    while(t--)
    {
      memset(x,0,sizeof(x));
      cin>>n;  
      for(int i=0;i<n;i++)
      {
              cin>>typ>>y>>a>>b;
              if(typ==1)
              {
                   x[i]=b*y/a;
              }
              else
              {
                  x[i]=sqrt(b*y/a*y);
              }
      }
      sort(x,x+n);bool flag=1;int ans;
      //for(int i=0;i<n;i++)
        //cout<<x[i]<<endl;
      for(int i=0;;i++)
      {
               if(i>=100000)
               {
                 flag=0;
                 break;
               }int j;
               for(j=n-10;j>=0;j--)
               {if(i<=x[j])
                   break;}
                 if(j==-1)  
                {ans=i;break;}
      }if(n<10)
        cout<<0<<endl;
      
        else if(flag)
        cout<<ans<<endl;
        else
        cout<<"GGsimida!"<<endl;
    }
    
}                                 
                 