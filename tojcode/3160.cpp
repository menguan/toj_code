#include<iostream>//以后不能把检查过的变零，还是要用队列 
#include<cstring>
#include<queue>
using namespace std;

int move[8][2]={0,1,0,-1,1,0,-1,0,1,1,-1,1,1,-1,-1,-1},n,m;
int d[1005][1005], g[1005][1005];

struct node
{int x,y;       
}s,p;

void BFS(node a)
{
     queue<node>pq;
     pq.push(a);
     
     while(pq.size())
     {    
          s=pq.front(); 
          pq.pop();
          for( int i=0;i<8;i++)
          {
               p.x=s.x+move[i][0];
               p.y=s.y+move[i][1];

               if(d[p.x][p.y]==0&&g[p.x][p.y]>=1)
               {    
                    d[p.x][p.y]=1;
                    pq.push(p);
               }
          }
     }
}

int main()
{
    
    while( cin>>n>>m)
    {
          memset(g,-1,sizeof(g)); 
          memset(d,0,sizeof(d));
          int i,j;
          for( i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                cin>>g[i][j];
                
            
           
          int cnt=0;
          
          for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
               if(d[i][j]==0&&g[i][j]) 
               {
                   d[i][j]=1;  
                   s.x=i; s.y=j;
                   cnt++;  
                   BFS(s);
               } 
            }

          cout<<cnt<<endl;
    }

    return 0;
}    

 
