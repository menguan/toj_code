#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k;
int id[1200];
struct f
{
  int u,v;
  int dis;
}road[1000000]; 
bool cmp(f a,f b)
{
  return a.dis<b.dis;
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
void add(int i,int j)
{
  int ii=find(i),jj=find(j);
  id[ii]=jj;
}  
       
void init()
{
  for(int i=1;i<=n;i++)
  {
    id[i]=i;
  }
}     
int main()
{
  int t;int ans=0;
  
  while(cin>>n,n)
  {
    
    cin>>k;
    init();
    int st,en;int con=n-1;ans=0;
    for(int i=0;i<k;i++)
    {
      cin>>road[i].u>>road[i].v>>road[i].dis;
    }
    sort(road,road+k,cmp);
    for(int i=0;i<k;i++)
    {
      if(find(road[i].u)!=find(road[i].v))
      {
        add(road[i].u,road[i].v);
        con--;
        ans+=road[i].dis;
      }
      if(!con)
        break;
    } 
    if(con)
      cout<<"-1"<<endl;
    else         
      cout<<ans<<endl;
  }
}          