#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int u[100005],v[100005],w[100005],fath[100005],r[100005],t[100005];
int find(int x){return fath[x]==x?x:fath[x]=find(fath[x]);}
bool cmp(int x,int y) { return w[x]<w[y];}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int minc=(1<<31)-1;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&t[i]);
            if(t[i]<minc) minc=t[i];
            fath[i]=i;
        }
        for(int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            u[i]=x,v[i]=y;w[i]=z*2+t[x]+t[y];
            r[i]=i;
        }
        sort(r,r+m,cmp);
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int e=r[i];
            int x=find(u[e]),y=find(v[e]);
            if(x!=y)
            {
                ans+=w[e];
                fath[x]=y;
            }
        }
        cout<<ans+minc<<endl;
    }
    return 0;
}         