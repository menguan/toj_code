#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,d;
int a[50010];
bool ok(long long now)
{
  int cnt=1;
  int res=0;
  long long nn=0;
  
  //while(cnt<=n)
  //{
  for(int i=1;i<=d;i++)
  {
    nn/=2;
    while(nn<now&&cnt<=n)
    {
      //cout<<"kk "<<nn<<endl;
      nn+=a[cnt++];
      //cout<<(bool)(nn+a[cnt]<now)<<endl;
    }
   // cout<<nn<<endl;
    if(nn<now)
      return 0;
    //res++;
    
  }
  //if(res<=d)
    return 1;
  //return 0;
}  
int main()
{
  cin>>n>>d;
  long long ans=1;
  long long high=0;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    high+=a[i];
  }
  //cout<<ok(1)<<endl;  
  //system("pause");  
  long long low=1;
  long long mid;
  while(low<=high)
  {
    mid=(low+high)/2;
    //cout<<mid<<endl;
    if(ok(mid))
    {
      ans=mid;
      //cout<<ans<<endl;
      low=mid+1;
    }
    else
      high=mid-1;
  }
  long long nn=0;
  int cnt=1;
  int pre=1;
  int cc=1;
  cout<<ans<<endl;
  //while(cnt<=n)
  for(int i=1;i<=d;i++)
  {
    nn/=2;
    while(cnt<=n&&nn<ans)
    {
      nn+=a[cnt++];
    }
    
    for(int j=pre;j<cnt;j++)
    {
       cout<<i<<endl;
    }
    
    pre=cnt;
  }
  for(int i=cnt;i<=n;i++)
    cout<<d<<endl;
  //while(1);
}
    
  