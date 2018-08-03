#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,nc;
int mod=20101010;
int num[300];
int vis[300];
bool hash[20101010];
int main()
{
  string s;
  while(cin>>n>>nc)
  {
     cin>>s;
     int len=s.length();
     memset(vis,0,sizeof(vis));
     memset(hash,0,sizeof(hash));
     for(int i=0;i<len;i++)
     {
          vis[s[i]]=1;
     }
     int cnt=1;
     for(int i=0;i<300;i++)
     {
       if(vis[i])
       {
         vis[i]=cnt++;
       }
     }
     int ans=0;
     for(int i=0;i<len-n+1;i++)
     {
       int tmp=0;
       for(int j=0;j<n&&i+j<len;j++)
       {
          tmp=tmp*nc+vis[s[i+j]];
          tmp=abs(tmp)%mod;
       }
       if(hash[tmp])
         continue;
       hash[tmp]=1;
       ans++;   
     }
     cout<<ans<<endl;
  }
}