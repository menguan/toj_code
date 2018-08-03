#include<iostream>
using namespace std;
int n;int now;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int map[120][120];
void bfs(int i,int j)
{
  if(i<0||i>=n||j<0||j>=n)
    return ;
  if(map[i][j]==0)
    return ;  
  now+=map[i][j];
  map[i][j]=0;
  for(int k=0;k<4;k++)
    bfs(i+dir[k][0],j+dir[k][1]);
}      
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     cin>>n;
     int maxn=0;
     for(int i=0;i<n;i++)
     {
       for(int j=0;j<n;j++)
       {
         cin>>map[i][j];
       }
     }
     for(int i=0;i<n;i++)
     {
       for(int j=0;j<n;j++)
       {
         if(map[i][j])
         {
           now=0;
           bfs(i,j);
           if(now>maxn)
             maxn=now;
         }    
         
       }
     }
     cout<<maxn<<endl;
   }
}         
     
   