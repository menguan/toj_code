#include<iostream>
#include<cstring>
#include<stdio.h>
#include<vector>
using namespace std;
char m[100];
bool vis[100];
int main()
{
  int a,b,c;
  while(scanf("%d%d%d",&a,&b,&c)!=EOF)
  {
    if(a==0&&b==0&&c==0)
      break;
    scanf("%s",m);
    memset(vis,0,sizeof(vis));
    vector<char> v;
    v.clear();
    int pos;
    int len=strlen(m);
    for(int i=0;i<len;i++)
    {
      if(m[i]>='a'&&m[i]<='i')
      {
        vis[i]=1;
        v.push_back(m[i]);
      }
    }
    if(v.size()>0)
    {
     pos=(v.size()-a%v.size())%v.size();
    for(int i=0;i<len;i++)
    {
      if(vis[i])
      {
        vis[i]=0;
        m[i]=v[pos];
        pos=(pos+1)%v.size();
      }
    }//printf("%s\n",m);
    }
    v.clear();
    for(int i=0;i<len;i++)
    {
      if(m[i]>='j'&&m[i]<='r')
      {
        //cout<<i<<endl;
        vis[i]=1;
        v.push_back(m[i]);
      }
    }
    //cout<<v.size()<<endl;
    if(v.size()>0)
    {
      pos=(v.size()-b%v.size())%v.size();
    for(int i=0;i<len;i++)
    {
      if(vis[i])
      {
        vis[i]=0;
        //cout<<i<<" "<<pos<<endl;
        m[i]=v[pos];
        pos=(pos+1)%v.size();
      }
    }//printf("%s\n",m);
    }
    v.clear();
    for(int i=0;i<len;i++)
    {
      if((m[i]>='s'&&m[i]<='z')||m[i]=='_')
      {
        vis[i]=1;
        v.push_back(m[i]);
      }
    }
    if(v.size()>0)
    {
     pos=(v.size()-c%v.size())%v.size();
    for(int i=0;i<len;i++)
    {
      if(vis[i])
      {
        vis[i]=0;
        m[i]=v[pos];
        pos=(pos+1)%v.size();
      }
    }
    }
    printf("%s\n",m);
  }
}   
  
  