#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
using namespace std;
int n,w;
int qu;
int now[100010];
//bool vis[100010];
//double nn[100010];
int main()
{
      while(cin>>n>>w&&(n+w))
      {
          int tt=n;
          int num;
          memset(now,0,sizeof(now));
          //memset(vis,0,sizeof(vis));
          //for(int i=0;i<100010;i++)  nn[i]=0.0;
          int maxn=-1;
          int cnt=0;
          for(int i=0;i<n;i++)
          {
              cin>>num;
              now[num/w]++;
              cnt=max(cnt,num/w);
              maxn=max(now[num/w],maxn);
          }

          double ans=0.01;
          int u=cnt;
          for(int i=0;i<100010;i++)
          {
              ans+=now[i]*1.0/maxn*(u)/cnt;
              //cout<<now[i]<<" "<<maxn<<" "<<u<<endl;
              u--;
              tt-=now[i];
              if(tt==0) break;
          }
          cout<<setprecision(10)<<fixed<<ans<<endl;
      }
}
