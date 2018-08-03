#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define NIL 10101010
using namespace std;
const int N = 80;
struct Point
{
   int x,y;
   int cnt;
   bool operator <(const Point &tt) const
   {
       return cnt > tt.cnt;
   }
};
int graph[N][N];
int Visited[N][N];//转向次数 
int turn[N][N];//方向 
int mk[N][N];//是否计算 
int w, h;
int m, n;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool isBound(int x, int y)
{
   if(x < 0 || y < 0)
       return false;
   if(x > m || y > n)
       return false;
   return true;
}
int bfs(Point bp, Point ep)
{
   Point a, b;
   int i, j;
   priority_queue<Point> Q;
    for(i = 0; i <= m; i++)
       for(j = 0; j <= n; j++)
       {
           Visited[i][j] = NIL;
           mk[i][j] = 0;
       }
   
   Visited[bp.x][bp.y] = 0;
   turn[bp.x][bp.y] = -1;
   mk[bp.x][bp.y] = 1;
   for(i = 0; i < 4; i++)
   {
       a.x = bp.x + dir[i][0];
       a.y = bp.y + dir[i][1];
       a.cnt = 1;
       Visited[a.x][a.y] = a.cnt;
       turn[a.x][a.y] = i;
       Q.push(a);
   }
   while(!Q.empty())
   {
       a = Q.top();
       Q.pop();
       
       if(a.x == ep.x && a.y == ep.y)
           return Visited[a.x][a.y];
       if(graph[a.x][a.y])
           continue;
       mk[i][j] = 1;
       for(i = 0; i < 4; i++)
       {
           b.x = a.x + dir[i][0];
           b.y = a.y + dir[i][1];
           if(isBound(b.x, b.y) && !mk[b.x][b.y])
           {    
                   if(i == turn[a.x][a.y])
                       b.cnt = Visited[a.x][a.y];
                   else 
                       b.cnt = Visited[a.x][a.y] + 1;
                   if(b.cnt < Visited[b.x][b.y])
                   {
                       Visited[b.x][b.y] = b.cnt;
                       turn[b.x][b.y] = i;
                       Q.push(b);
                   }
                   
           }
       }
   }
   return -1;
}
int main()
{
   char tc;
   int i, j, ans, cc = 1, kk;
   Point bp, ep;
   while(scanf("%d%d", &w, &h))
   {
       m = h + 1;
       n = w + 1;
       if(!w && !h)
           break;
       for(i = 0; i <= m; i++)
           for(j = 0; j <= n; j++)
               graph[i][j] = 0;
       for(i = 1; i <= h; i++)
       {
           getchar();
           for(j = 1; j <= w; j++)
           {
               scanf("%c", &tc);
               if(tc == 'X')
                   graph[i][j] = 1;
           }
       }
       cout<<"Board #"<<cc++<<":"<<endl;
       kk = 1;
       while(scanf("%d%d%d%d", &bp.y, &bp.x, &ep.y, &ep.x))
       {
           if(!bp.x && !bp.y && !ep.x && !ep.y)
               break;
           ans = bfs(bp, ep);
           if(ans != -1)
               cout<<"Pair "<<kk++<<": "<<ans<<" segments."<<endl;
           else
               cout<<"Pair "<<kk++<<": impossible."<<endl;
       }
       cout<<endl;
   }
   return 0;
}
