#include<iostream>//子节点入度只能为1 
#include<cstring>
#include<stdio.h>
#include<string>
#define MAX 50000
using namespace std;
int parent[MAX+1],a,b,nedges,nvertices;
bool visit[MAX+1];
int main()
{
 int count = 1;
 while(scanf("%d%d",&a,&b))
 {
  if(a == -1 && b == -1)
  break;
  if(a == 0 && b == 0)
  {
   printf("Case %d is a tree.\n",count);
   count++;
   continue;
  }
        nvertices=0,nedges=0;
  bool flag = 1;
  memset(parent,0,sizeof(parent));
  memset(visit,0,sizeof(visit));
  while(!(a==0&&b==0))
  {
   if(flag == true)
   {
    if(parent[b]>0)
    flag = false; 
    if(visit[a] == false)
    nvertices++,visit[a]=true;
    if(visit[b] == false)
    nvertices++,visit[b]=true;
    nedges++;
    parent[b]=a;
   }
   scanf("%d%d",&a,&b);        
  }
     if(nvertices==nedges+1&&flag==1)
  printf("Case %d is a tree.\n",count);
  else
  printf("Case %d is not a tree.\n",count);
  count++;
 }
}
