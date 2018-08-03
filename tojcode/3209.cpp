#include<iostream>
using namespace std;
int main()
{
  int a[100010];
  int ans[100010];
  for(int i=0;i<100010;i++)
    ans[i]=0;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  int now;
  for(int i=n-1;i>=1;i--)
  {
    now=i+1;
    while(a[i]>=a[now])     
    {      now=ans[now];      
    if(!now)break;     }
    
    if(a[i]<a[now])
    ans[i]=now;
    
  }
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<endl;
  //while(1);
}  