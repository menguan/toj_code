#include <iostream>  //第一次学习队列 抄一次 之后还有几道就不用抄了 
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
int sx,sy,ex,ey;
int map[10][10];
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
            if(next.x<0||next.x>=8||next.y<0||next.y>=8) continue;
            if(map[next.x][next.y])  continue;
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
    while(scanf("%s%s",&a,&b)!=EOF)
    {

        sy=a[0]-'a';
        sx=a[1]-'1';
        ey=b[0]-'a';
        ex=b[1]-'1';
        memset(map,0,sizeof(map));
        printf("To get from %s to %s takes %d knight moves.\n",a,b,BFS());
    }
    return 0;
}
