#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int n;
int prime[5000000];
int cnt;
bool vis[10000000];
int main()
{
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<10000000;i++)
    {
        if(!vis[i])
        {
          prime[cnt++]=i;
          for(int j=i+i;j<10000000;j+=i)
                vis[j]=1;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int g=n;
        int now=1;
        for(int i=0;i<cnt;i++)
        {
            if(n<prime[i])break;
            if(n%prime[i]==0)
            {
                now*=prime[i];
                while(n%prime[i]==0)
                {
                    n/=prime[i];

                }
            }
        }
        if(now==1)cout<<2<<endl;
        else cout<<g/now+1<<endl;
    }
}
