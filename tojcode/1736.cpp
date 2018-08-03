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
int sx,sy,ex,ey,n;
int map[310][310];
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
            if(next.x<0||next.x>=n||next.y<0||next.y>=n) continue;
            if(map[next.x][next.y])  continue;
            map[next.x][next.y]=1;
            next.step=first.step+1;
            Q.push(next); 
        }
    }
}
int main()
{
    
    int i,j;
    int t;
    cin>>t;
    
    while(t--)
    {
        cin>>n; 
        cin>>sx>>sy>>ex>>ey;
        memset(map,0,sizeof(map));
        cout<<BFS()<<endl;
    }
    return 0;
}
