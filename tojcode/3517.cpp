#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,maxn;
int map[2005][2005],sum[2005];
bool flag[2005];
int bfs(int begin)
{
    int temp,ans;
    maxn=-1;
    memset(flag,0,sizeof(flag));
    queue<int> q;
    flag[begin]=1;
    q.push(begin);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        for(int i=1;i<=n;++i)
        {
            if(map[temp][i]!=-1&&(!flag[i]))
            {
                flag[i]=1;
                q.push(i);
                sum[i]=sum[temp]+map[temp][i];
                if(sum[i]>maxn)
                {
                    maxn=sum[i];
                    ans=i;
                }
            }
        }
        
    }
    return ans;
}
int main()
{
    int t,ans,u,st,en,dis;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int u=n-1;
        memset(map,-1,sizeof(map));
        while(u--)
        {
            cin>>st>>en>>dis;
            map[st][en]=map[en][st]=dis;
        }
        sum[1]=0;
        ans=bfs(1);
        sum[ans]=0;
        ans=bfs(ans);
        cout<<maxn<<endl;
    }
}
