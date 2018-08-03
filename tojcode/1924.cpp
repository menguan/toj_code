#include<iostream>
#include<cstring>
#define maxn 10000000
using namespace std;
int n;
int dis[50][50];
int visit[50],lowcost[50];
void prim()
{
  memset(visit,0,sizeof(visit));
  int pos=0;int sum=0;
  for(int i=1;i<=n;i++)
    lowcost[i]=dis[1][i];
  visit[1]=1;
  for(int i=1;i<n;i++)
  {
    int minn=maxn;
    for(int j=1;j<=n;j++)
    {
      if(lowcost[j]<minn&&!visit[j])
      {
        minn=lowcost[j];
        pos=j;
      }
    }
    visit[pos]=1;
    sum+=minn;
    for(int j=1;j<=n;j++)
    {
      if(lowcost[j]>dis[pos][j]&&!visit[j])
        lowcost[j]=dis[pos][j];
    }
  }
  cout<<sum<<endl;
}              
  
int main()
{
   int t;char a,b;int dir;
   while(cin>>n,n)
   {
     for(int i=1;i<=n;i++)
     {
       for(int j=1;j<=n;j++)
       {
         if(i==j)
           dis[i][j]=0;
         else
           dis[i][j]=maxn;
       }
     }        
     
     for(int i=1;i<n;i++)
     {
       cin>>a;
       cin>>t;
       while(t--)
       {
         cin>>b>>dir;
         if(dis[a-'A'+1][b-'A'+1]>dir)
         {
           dis[a-'A'+1][b-'A'+1]=dis[b-'A'+1][a-'A'+1]=dir;
         }
       }
     }
     prim();
   }
  
}           
         
       