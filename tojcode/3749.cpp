#include<iostream>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
const int wei[4]={4,4,2,1};
vector<int> v[4];
map<string,int > name;
map<int ,int > abi;
map<string,int > ::iterator pos;
string na,po;
int ab;int m;int cnt;int ans;bool flag;
bool vis[30];
int tt[100000][3];
int getpo(string s)
{
    if(s[0]=='d') return 0;
    if(s[0]=='m') return 1;
    if(s[0]=='s') return 2;
    if(s[0]=='g') return 3;
}
int getid(string s)
{
    return name[s];
}
void dfs(int p,int num,int pp)
{
    //cout<<p<<" "<<num<<" "<<pp<<endl;
    //system("pause");
    if(p==4)
    {
        flag=1;
        int tmp=0;
        for(int i=0;i<23;i++)
        {
            //cout<<i<<" "<<abi[i]<<endl;
            if(vis[i])
                tmp+=abi[i];
        }
        for(int i=0;i<m;i++)
        {
            if(vis[tt[i][0]]&&vis[tt[i][1]])
                tmp+=tt[i][2];
        }
        //cout<<tmp<<endl;
        if(tmp>ans)
            ans=tmp;
        return ;
    }
    if(num==wei[p])
    {
        dfs(p+1,0,0);
        return ;
    }
    for(int i=pp;i<v[p].size();i++)
    {
        vis[v[p][i]]=1;
        dfs(p,num+1,i+1);
        vis[v[p][i]]=0;
    }
    return ;
}
int main()
{
    while(cin>>na>>ab>>po)
    {
        name.clear();abi.clear();cnt=0;
        for(int i=0;i<4;i++) v[i].clear();
        memset(vis,0,sizeof(vis));
        v[getpo(po)].push_back(name[na]=cnt++);
        abi[getid(na)]=ab;
        for(int i=0;i<22;i++)
        {
            cin>>na>>ab>>po;
            v[getpo(po)].push_back(name[na]=cnt++);
            abi[getid(na)]=ab;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>na>>po>>ab;
            tt[i][0]=getid(po);
            tt[i][1]=getid(na);
            tt[i][2]=ab;
        }
        flag=0;
        ans=-1010101010;
        dfs(0,0,0);
        if(flag)
            cout<<ans<<endl;
        else
            cout<<"impossible"<<endl;
    }
}
