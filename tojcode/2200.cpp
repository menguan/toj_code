#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
long long ans;int n,m;int sx,sy,ex,ey;
int dir[4][2]={1,2,2,1,1,-2,2,-1};
void dfs(int x,int y)
{
     //cout<<"kk"<<x<<" "<<y<<endl;
     if(y<1||y>n||x<1||x>ex)
       return ;
     if(y>ey&&(y-ey+1)/2+x>ex) return ;
     if(y<ey&&(ey-y+1)/2+x>ex) return ;  
     if(x==ex&&y==ey)
     {                     
       ans++;return ;
     }
     for(int i=0;i<4;i++)
     {
        //cout<<i<<" "<<"ll"<<x<<" "<<y<<endl;
        dfs(x+dir[i][0],y+dir[i][1]);
     }  
     return ;
}         
int main()
{
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
      scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
      ans=0;
      dfs(sx,sy);
      printf("%lld\n",ans);
    }  
}
      
                             
