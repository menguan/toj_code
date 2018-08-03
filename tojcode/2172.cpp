#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
struct f
{
       int x;int y;
       int len;
}con[60000];
map<string,int> has;
map<string,int> ::iterator it;
int bnum;
int m;int n;
char name[6000][30];
int id[6000];
int sz[6000];
bool vis[6000];
void init()
{
     for(int i=0;i<=m;i++)
     {
         id[i]=i;
         sz[i]=1;
     }
}     
bool cmp(f mm, f nn)
{
     return mm.len<nn.len;
}
int getid(char* temp)
{
    it=has.find(temp);
    if(it!=has.end())
     return it->second;
                                           
    has[temp]=bnum++;
    return bnum-1;    
}
int find(int p)
{
    while(p!=id[p])
    {
       id[p]=id[id[p]];
       p=id[p];
    }
    return p;
}
int uni(int p,int q)
{
    if(sz[p]>sz[q])
    {
       id[q]=p;
       sz[p]+=sz[q];
    }
    else 
    {
      sz[q]+=sz[p];
      id[p]=q;
    }
}  
int main()
{
    char s1[30],s2[30];int g;
    memset(name,0,sizeof(name));
    scanf("%d%d",&m,&n);
    
    has.clear();
    init();bnum=0;
    for(int i=0;i<n;i++)
    {
       scanf("%s%s%d",s1,s2,&g);
       con[i].x=getid(s1);
       con[i].y=getid(s2);
       con[i].len=g;
      // cout<<con[i].x<<" "<<con[i].y<<" kk"<<endl;
    }
    int ans=0;int pp,qq;
    int cnt=0;
    sort(con,con+n,cmp);
    for(int i=0;i<n;i++)
    {
         if(cnt==m-1)
           break;
         pp=find(con[i].x);
         qq=find(con[i].y);
         if(pp==qq)
           continue;
         cnt++;
         uni(pp,qq);
         ans+=con[i].len;
    }//cout<<ans<<endl;//cout<<cnt<<"ll"<<endl;
    //memset(vis,0,sizeof(vis));
    ans+=((m-cnt)*10);
    printf("The total cost is %d Yuan %d Jiao.\n",ans/10,ans%10);
   // while(1);                         
}            
                                   
      
