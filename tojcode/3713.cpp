#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
struct my
{
    int index;
    int l;
    int n;
    int d[1005];
    bool operator > (const my &x)const
    {
        return l>x.l;
    }
}wo[1005];
priority_queue<my,vector<my>,greater<my> >q;
bool vis[1010];
int main()
{
    int n;
    while(cin>>n)
    {
        int i,j;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;++i)
        {
            wo[i].index=i+1;
            cin>>wo[i].l>>wo[i].n;
            for(j=0;j<wo[i].n;++j)
                cin>>wo[i].d[j];
        }
        vis[1]=1;
        q.push(wo[0]);
        int ans=0;
        while(!q.empty())
        {
            my x=q.top();
            ans=x.l;
            q.pop();
            for(i=0;i<x.n;++i)
            {
                if(x.d[i]!=x.index&&vis[x.d[i]]==0)
                {
                    vis[x.d[i]]=1;
                    wo[x.d[i]-1].l+=x.l;
                    q.push(wo[x.d[i]-1]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
