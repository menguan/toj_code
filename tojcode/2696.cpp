#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
bool vis[20];
struct f
{
       int x,y;
}beep[20];
int get;int po;int sx,sy;
int len;
int ans;
void dfs(int x,int y)
{
    int ret;
    if(get==po)
    {
        ret=len+abs(x-sx)+abs(y-sy);
        if(ret<ans)
          ans=ret;
    }
    for(int i=0;i<po;i++)
    {         
      if(vis[i])  continue;
      vis[i]=1;
      get++;
      len+=(abs(x-beep[i].x)+abs(y-beep[i].y));
      dfs(beep[i].x,beep[i].y);
      vis[i]=0;
      get--;
      len-=(abs(x-beep[i].x)+abs(y-beep[i].y));    
    }
}
              
int main()
{
    int t;int r,c;
    cin>>t;
    while(t--)
    {
       memset(vis,0,sizeof(vis));
       memset(beep,0,sizeof(beep));
       cin>>r>>c>>sx>>sy>>po;
       ans=1212121212;
       get=0;
       len=0;
       for(int i=0;i<po;i++) 
       {
          cin>>beep[i].x>>beep[i].y;
       }           
       dfs(sx,sy);
       cout<<"The shortest path has length "<<ans<<endl;
    }
}
         
