#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10010];
int b[10010];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
      cin>>a[i];
    for(int i=0;i<m;i++)
      cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    int posa=n-1,posb=m-1;
    int ans=0;
    while(posa>-1)
    {
       for(int i=posb;i>=0;i--)
       {
          if(a[posa]>b[i])
          {
              ans+=1;
              posb=i-1;
              break;
          }
       }
       ans+=1;
       posa--;
    }
    cout<<ans<<endl;
    //while(1);
}    
              
              
                                
