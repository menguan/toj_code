#include<iostream>
#include<cstring>
using namespace std;
bool vis[110][110][110];
int dp[110][110][110];
int dir[5][2]={0,0,1,0,0,1,0,-1,-1,0};
int W,H,T,tim,li,ti,ri,bi;
int n,xx,yy;
int dfs(int x,int y,int t)
{
    if(dp[t][x][y]!=-1) return dp[t][x][y];
    if(t==T) return dp[t][x][y]=1;
    for(int i=0;i<5;i++)
    {
        xx=x+dir[i][0];
        yy=y+dir[i][1];
        if(vis[t+1][xx][yy]&&dfs(xx,yy,t+1)==1)
            dp[t][x][y]=1;
    }
    if(dp[t][x][y]==-1) dp[t][x][y]=0;
    return dp[t][x][y];
}
int main()
{
    int cas=1;
    while(cin>>W>>H>>T&&(W+H+T))
    {
        memset(vis,0,sizeof(vis));
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=H;i++)
            for(int j=1;j<=W;j++)
               for(int k=0;k<=T+1;k++)
               vis[k][i][j]=1;
        cin>>n;
        while(n--)
        {
            cin>>tim>>li>>ti>>ri>>bi;
            for(int i=ti;i<=bi;i++)
                for(int j=li;j<=ri;j++)
                   vis[tim][i][j]=0;
        }
        cout<<"Robbery #"<<cas++<<":"<<endl;
        int ans=0;
        for(int i=1;i<=H;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(vis[1][i][j])
                {
                   if(dfs(i,j,1)==1)
                        ans++;
                }
            }
        }
        if(ans==0)
        {
            cout<<"The robber has escaped."<<endl;
        }
        else
        {
            bool is=1;
            for(int i=1;i<=T;i++)
            {
                int tmp=0;
                for(int j=1;j<=H;j++)
                {
                    for(int k=1;k<=W;k++)
                    {
                        if(dp[i][j][k]==1)
                        {
                            //cout<<i<<" "<<j<<" "<<k<<endl;
                            tmp++;
                            xx=j;
                            yy=k;
                        }
                    }
                }
                if(tmp==1)
                {
                    cout<<"Time step "<<i<<": The robber has been at "<<yy<<","<<xx<<"."<<endl;
                    is=0;
                }
            }
            if(is)
                cout<<"Nothing known."<<endl;

        }
        cout<<endl;

    }
}
