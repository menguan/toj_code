#include<iostream>
#include<cstring>
#include<stdio.h>
#include<queue>
#include<map>
using namespace std;
bool vis[100][100];
bool a[3000][4];//0up 1 you
/*struct node
{
   int x,y;
   node(){}
   node(int _x,int _y):x(_x),y(_y){}
}na,nb;
//typedef pair<node,node>  pp;

map<pair<node,node>,int >mapp;
*/
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int w,h;
int bfs()
{
    int tx;int ty;int tt;
    queue<int> q;
    vis[1][1]=1;
    int x,y,step;
    q.push(1);q.push(1);q.push(1);
    while(!q.empty())
    {
        x=q.front();q.pop();
        y=q.front();q.pop();
        tt=q.front();q.pop();
        if(x==h&&y==w)
        {
             return tt;
        }         
        for(int i=0;i<4;i++)
        {
          if(a[x+y*50][i])  continue;
          tx=x+dir[i][0];ty=y+dir[i][1];      
          if(tx<1||ty<1||tx>h||ty>w)
            continue;
          if(vis[tx][ty])  continue;
            vis[tx][ty]=1;
            q.push(tx);q.push(ty);q.push(tt+1);
        }
    }
    return 0;
}             
int main()
{
    int tmp;
   
    while(cin>>w>>h&&(w+h))
    {
       memset(a,0,sizeof(a));
       memset(vis,0,sizeof(vis));
       for(int i=1;i<=2*h-1;i++)
       {
           if(i%2==0)
           {
               for(int j=1;j<=w;j++)
               {
                  cin>>tmp;
                  a[i/2+j*50][2]=tmp;
                  a[i/2+1+j*50][0]=tmp;
                  //na=node(i,j);nb=node(i,j+1);
                 // mapp[make_pair(na,nb)]=tmp;
               }
           }
           else
           {
               for(int j=1;j<w;j++)
               {
                   cin>>tmp;
                   a[i/2+1+j*50][1]=tmp;
                   a[i/2+1+(j+1)*50][3]=tmp;    
               }
           }
       }
       cout<<bfs()<<endl;
       
    }
}
                  
                                                      
