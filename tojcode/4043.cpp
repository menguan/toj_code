#include<iostream>
#include<algorithm>
using namespace std;
int sum[100010]={0};
int main()
{
  int n,m,t;
  while(cin>>n>>m)
  {
    for(int i=1;i<=n;i++)
    {
       cin>>t;
       sum[i]=(sum[i-1]+t)%m;
    }
    int maxn=0;
    for(int i=n;i>0&&i>maxn;i--)
    {
      for(int j=1;j+i-1<=n;j++)
      {
        if((sum[j+i-1]-sum[j-1])%m==0)
        {
          maxn=max(maxn,i);
          break;
        }    
      }
    }
    cout<<maxn<<endl;
  }
}      