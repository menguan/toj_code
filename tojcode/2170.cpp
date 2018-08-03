#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int id[210];
struct edge
{
    int a,b,w;
}e[1200];
int n,m;
int cmp(edge aa,edge bb)
{
    return aa.w<bb.w;
}
int find(int p)
{
    while(p!=id[p])p=id[p];
    return p;
}
void init()
{
    for(int i=1;i<=n;i++)
        id[i]=i;
}

int main()
{
    int u,v,w;int s,t;
    while(cin>>n>>m,m+n)
    {
        for(int i=0;i<m;i++)
        {
            cin>>e[i].a>>e[i].b>>e[i].w;
        }
        cin>>s>>t;
        sort(e,e+m,cmp);
        int ans=1010101010;
        for(int i=0;i<m;i++)
        {
            init();
            int d=e[i].w;
            int tmp=e[i].w;
            bool flag=0;
            for(int j=i;j<m;j++)
            {
                int ta=find(e[j].a);
                int tb=find(e[j].b);
                if(ta!=tb)
                {
                    id[ta]=id[tb];
                    tmp=e[j].w;
                }
                if(find(s)==find(t)) {flag=1;break;}
            }
            if(flag)
              ans=min(ans,tmp-d);
            else
              break;
        }
        if(ans==1010101010)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
}
s("-1");
        else
            printf("%d\n",ans);
    }
}
