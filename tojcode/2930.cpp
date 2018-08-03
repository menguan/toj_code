#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define N 1000005
int head[N];
struct G
{
    int v,next;
    double cost;
}edge[N];
double sum ;
bool vis[N];
int n;
int dian[N];
int dfs(int u)
{
    dian[u] = 1;
    vis[u] = true;
    for(int j = head[u];j!=-1;j=edge[j].next)
    {
        int v = edge[j].v;
        if(!vis[v])
        {
            dian[v] = dfs(v);
            dian[u] += dian[v];
            sum+=dian[v]*(n-dian[v])*edge[j].cost;//
            //cout<<u<<" "<<v<<" "<<" "<<dian[v]<<" "<<edge[j].cost<<endl;
        }
    }
    return dian[u];
}
int enu;
void addedge(int a,int b,double c)
{
    edge[enu].v = b;
    edge[enu].next = head[a];
    edge[enu].cost = c;
    head[a] = enu++;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        double c;
        memset(head,-1,sizeof(head));
        cin>>n;
        enu = 0;
        for(int i = 0;i<n-1;i++)
        {
            cin>>a>>b>>c;
            addedge(a,b,c);
            addedge(b,a,c);
        }
        sum = 0;
        memset(dian,0,sizeof(dian));
        memset(vis,0,sizeof(vis));
        dfs(0);
        sum/=(n*(n-1)/2.0);
        cout<<setprecision(6)<<fixed<<sum<<endl;
    }

}
