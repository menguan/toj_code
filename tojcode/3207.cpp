#include<iostream>
#include<algorithm>
using namespace std;
int m[30000];
int b[30000];
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    for(int i=0;i<n;i++)
      cin>>m[i]>>b[i];
    sort(m,m+n);
    sort(b,b+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(m[i]>b[i])
        {
           ans+=(m[i]-b[i])*y;
        }
        else
           ans+=(b[i]-m[i])*x;
    }
    cout<<ans<<endl;
   // while(1);
}                   
