#include<iostream>
#include<algorithm>
using namespace std;
int w[60000],h[60000];
int main()
{
  int n;
  while(cin>>n,~n)
  {
    for(int i=1;i<=n;i++)
    {
      cin>>w[i]>>h[i];
    }
    int ans=-1;
    int wsum=0;
    for(int i=1;i<=n;i++)
    {
        wsum=w[i];
        for(int j=i-1;j>=1;j--)
        {
          if(h[i]<=h[j])
          {
            wsum+=w[j];
          }
          else
            break;
        }
        for(int j=i+1;j<=n;j++)
        {
          if(h[i]<=h[j])
            wsum+=w[j];
          else
            break;
        }
        ans=max(ans,h[i]*wsum);
      }
      cout<<ans<<endl;
    }
}        
                        