#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    int pre,now;
    bool flag=1;
    cin>>n;
    cin>>pre;
    int ans=1;
    for(int i=1;i<n;i++)
    {
      cin>>now;
      if(flag&&now<pre)
      {
        ans++;
        flag=0;
      }
      else if(!flag&&now>pre)
      {
        ans++;
        flag=1;
      }
      pre=now;
    }
    cout<<ans<<endl;
  }
  }