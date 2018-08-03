#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool vis[6];
struct node
{
  int a,b,c;
}mm[6];
int ans;
void dfs(int zuo,int you,int dep,int num)
{
  //cout<<zuo<<" "<<you<<" "<<dep<<endl;
  if(dep==4)
  {
    for(int i=1;i<=6;i++)
    {
      if(!vis[i])
      {
        if(mm[i].a==zuo&&mm[i].c==you)
        {
          ans=max(ans,num+mm[i].b);
        }
        if(mm[i].b==zuo&&mm[i].a==you)
        {
          ans=max(ans,num+mm[i].c);
        }
        if(mm[i].c==zuo&&mm[i].b==you)
        {
          ans=max(ans,num+mm[i].a);
        }
        return ;
      }
    }
  }
      
  for(int i=1;i<=6;i++)
  {
    if(!vis[i])
    {
      vis[i]=1;
      if(mm[i].a==zuo)
      {
        dfs(mm[i].c,you,dep+1,num+mm[i].b);
      }
      if(mm[i].b==zuo)
      {
        dfs(mm[i].a,you,dep+1,num+mm[i].c);
      }
      if(mm[i].c==zuo)
      {
        dfs(mm[i].b,you,dep+1,num+mm[i].a);
      }
      vis[i]=0;
    }
  }
}
int main()
{
   bool flag=1;
   char dd;
   while(1)
   {
     for(int i=0;i<6;i++)
       cin>>mm[i].a>>mm[i].b>>mm[i].c;
     cin>>dd;
     if(dd=='$')
       flag=0;
     ans=-1;  
     for(int i=1;i<6;i++)  vis[i]=0;
     dfs(mm[0].a,mm[0].b,0,mm[0].c);
     for(int i=1;i<6;i++)  vis[i]=0;
     dfs(mm[0].b,mm[0].c,0,mm[0].a);
     for(int i=1;i<6;i++)  vis[i]=0;
     dfs(mm[0].c,mm[0].a,0,mm[0].b);
     if(ans==-1)
       cout<<"none"<<endl;
     else  
       cout<<ans<<endl;
     if(flag==0)
       break;  
   }
}
     

     
         
         