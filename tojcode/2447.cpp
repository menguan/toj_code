#include <iostream>
#include <cstring>
using namespace std;
int N,m;
struct node
{
    int a,b;
    int ci,pi,ri;
}edge[20];
int minS;
int flag[11];
void dfs(int pos,int res)
{
    if(pos==N)
    {
        if(res<minS)
        {
            minS=res;
        }
        return;
    }
    int i;
    for(i=1;i<=m;i++)
    {
        if(pos==edge[i].a && flag[edge[i].b]<=3)//这个小于等于3真是长见识
        {
            int b=edge[i].b;
            flag[b]++;

            if(flag[edge[i].ci])
            {
                dfs(b,res+edge[i].pi);
            }
            else
            {
                dfs(b,res+edge[i].ri);
            }
            flag[b]--;
        }
    }
    return;
}
int main()
{
    while(cin>>N>>m)
    {
        int i;
        for(i=1;i<=m;i++)
        {
            int a,b,c,d,e;
            cin>>a>>b>>c>>d>>e;
            edge[i].a=a;
            edge[i].b=b;
            edge[i].ci=c;
            edge[i].pi=d;
            edge[i].ri=e;
        }
        minS=0xfffffff;
        memset(flag,0,sizeof(flag));
        flag[1]=1;
        dfs(1,0);
        if(minS==0xfffffff)
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            cout<<minS<<endl;
        }
    }
    return 0;
}
