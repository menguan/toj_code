#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
double a[101010];
int main()
{
     long long n,m,u,v,w;
     while(cin>>n>>m)
     {
          a[0]=0;
          for(int i=1;i<=n;i++)
            cin>>a[i];
          for(int i=0;i<m;i++)
          {
             cin>>u>>v>>w;
             a[u]+=w/2.0;
             a[v]+=w/2.0;
          }
          sort(a+1,a+n+1);
          double ali=0,bob=0; 
          for(int i=n;i>0;i-=2)
          {
              ali+=a[i];
              bob+=a[i-1];
          }
          //cout<<ali<<" "<<bob<<endl;
          cout<<(long long)(ali-bob)<<endl;
     }
}                     
