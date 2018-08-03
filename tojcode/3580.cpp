/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa  aaa  aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaaa 
aaaaa    aaaaa    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa aaaaa          aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa aaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa     aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaa a aaaaa   aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaa  aaaaa  aaaaa aaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
bool vis[800][800];int ans;
char map[800][800];
int dir[8][2]={0,1,0,-1,1,0,-1,0,1,-1,-1,1,1,1,-1,-1};
struct node
{
    int x,y;
}now,next; 
int w,h;  
void bfs(int tx,int ty)
{
    queue<node> q;
    int step=0;
    now.x=tx;
    now.y=ty;
    vis[tx][ty]=1;
    q.push(now);
    while(!q.empty())
    {
       step++;
       now=q.front();
      
      // cout<<step<<" "<<now.x<<" "<<now.y<<endl;
       q.pop();
       for(int i=0;i<8;i++)
       {
           next.x=now.x+dir[i][0];
           next.y=now.y+dir[i][1];
           if(next.x<0||next.x>=h||next.y<0||next.y>=w) continue;
           if(vis[next.x][next.y])  continue;
           if(map[next.x][next.y]=='*')  continue;
            vis[next.x][next.y]=1;  
           q.push(next);
       }
    }
    //cout<<step<<endl;
    if(step>ans)
      ans=step;
   // system("pause");  
} 
int main()
{
    cin>>w>>h;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin>>map[i][j];
    ans=0;
    for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
    {
        if(map[i][j]=='.'&&!vis[i][j])
          bfs(i,j);
        //cout<<ans<<endl;  
    }
    cout<<ans<<endl;
    //while(1);
}                       
    
