#include <iostream>  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct Node   
{
    int x;
    int y;
    int step;
};
int lie,hang;
int sx,sy,ex,ey;
int map[160][160];
char mapn[160][160];
int dir[8][2]={-2,1,-2,-1,-1,2,-1,-2,1,2,1,-2,2,-1,2,1};
Node first,next;
int BFS()
{
    int i;
    queue<Node>Q;   
    first.x=sx;
    first.y=sy;
    first.step=0;
    Q.push(first);   
    map[first.x][first.y]=1;
    while(!Q.empty())
    {
        first=Q.front();      
        Q.pop();         
        if(first.x==ex&&first.y==ey) return first.step;
        for(i=0;i<8;i++)  
        {
            next.x=first.x+dir[i][0];
            next.y=first.y+dir[i][1];
            if(next.x<0||next.x>=hang||next.y<0||next.y>=lie) continue;
            if(map[next.x][next.y])  continue;
            if(mapn[next.x][next.y]=='*')  continue;
            map[next.x][next.y]=1;
            next.step=first.step+1;
            Q.push(next); 
        }
    }
}
int main()
{
    char a[3],b[3];
    int i,j;
    memset(map,0,sizeof(map));
    
    cin>>lie>>hang;   
    for(int i=0;i<hang;i++)
    {
      for(int j=0;j<lie;j++)
      {
        cin>>mapn[i][j];
        if(mapn[i][j]=='K')
        {
          sx=i;
          sy=j;
        }
        else if(mapn[i][j]=='H')
        {
          ex=i;
          ey=j;
        }    
          
      }
    }
    cout<<BFS()<<endl;
    //while(1);
         
        
    return 0;
}
