#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n;int fa,len;
bool vis[10001];
int point[10001];
int road[10001];
long long a,b;
void dfs(int pos)
{
    int temp=10000000;
   
    for(int i=pos+1;i<n;i++)
    {
      if(point[i]==pos&&!vis[i]) 
      {
        //cout<<"ll"<<road[i]<<endl;
        temp=min(temp,road[i]);
      }
    } //cout<<"kk"<<temp<<endl;
    for(int i=pos+1;i<n;i++)
    {
       if(point[i]==pos&&!vis[i]&&temp==road[i])
       {   
           vis[i]=1;
           b+=temp;
           //cout<<temp<<" "<<b<<endl;
           dfs(i);
           break;
       }
    }
    return ;
}                             
int main()
{
    int cas=1;
    while(scanf("%d",&n)!=EOF)
    {
       memset(vis,0,sizeof(vis));
       memset(point,0,sizeof(point));
       memset(road,-1,sizeof(road));
       for(int i=1;i<n;i++)
       {
          scanf("%d%d",&fa,&len);
          point[i]=fa;
          road[i]=len;
       }
       a=0;b=0;
       for(int i=0;i<n;i++)
       {   
           if(!vis[i])
           {
              a++;
              dfs(i);
           }
       }
       cout<< "Case #"<<cas++<<": "<<a<<" "<<b<<"\n";
       
    }
}
                                                                       
    
    
