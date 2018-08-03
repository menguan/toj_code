#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int g[600][600];int fa[600];
int main()
{
    int p,f,c;
    while(cin>>p>>f>>c)
    {
        for(int i=1;i<=p;i++)
            for(int j=1;j<=p;j++)
              g[i][j]=1010101010;
        for(int i=1;i<=p;i++)  g[i][i]=0;
        for(int i=1;i<=f;i++)
            cin>>fa[i];
        int u,v,w;
        for(int i=1;i<=c;i++)
        {
            cin>>u>>v>>w;
            g[u][v]=g[v][u]=min(g[u][v],w);
        }
        for(int i=1;i<=p;i++)
        {
            for(int j=1;j<=p;j++)
            {
                for(int k=1;k<=p;k++)
                {
                    if(i!=j&&i!=k&&j!=k)
                        g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
                }
            }
        }
        int ans=1;
        int ddd=1010101010;
        for(int i=1;i<=p;i++)
        {
            int tt=0;
            for(int j=1;j<=f;j++)
            {
                tt+=g[fa[j]][i];
            }
            //cout<<tt<<endl;
            if(tt<ddd)
            {
                ddd=tt;
                ans=i;
            }
        }
        cout<<ans<<endl;
    }
}

