#include<iostream>
#include<math.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int map[105][105],n;
bool hash[105][105];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
bool dfs(int x,int y,int min,int max)
{
 if(map[x][y]<min||map[x][y]>max)
  return false;
 hash[x][y]=true;
 if(x==n&&y==n)
  return true;
    int i,x1,y1;
 for(i=0;i<4;i++)
 {
  x1=x+dir[i][0];
  y1=y+dir[i][1];
  if(x1>=1&&x1<=n&&y1>=1&&y1<=n&&!hash[x1][y1])
  {
    if(dfs(x1,y1,min,max))return true;

  }
 }
 return false;

}
int main()
{
 int N,i,j,maxn,minn,l,r,x=0,k;
 cin>>N;
 while(N--)
 {
  x++;
  cin>>n;
  maxn=0;
  minn=0x3fffffff;
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   {
    cin>>map[i][j];
    if(map[i][j]>maxn)maxn=map[i][j];
    if(map[i][j]<minn)minn=map[i][j];
   }
   int ans=r;
  l=0;r=maxn-minn;
  while(l<=r)
  {

   int mid;
   mid=(l+r)/2;
   int tmp=map[1][1]-mid;
   for(k=tmp>0?tmp:0;k<=map[1][1];k++ )
   {
     memset(hash,false,sizeof(hash));
    if(dfs(1,1,k,k+mid))
     break;
   }
      if(k<=map[1][1]) ans=mid,r=mid-1;
                   else l=mid+1;
  }
  cout<<"Scenario #"<<x<<':'<<endl;
  cout<<ans<<endl<<endl;
 }
}
