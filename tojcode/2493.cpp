#include<iostream>
#include<cstring>
using namespace std;
int map[110][110];
int n;
int dir[4][2]={0,1,1,0,-1,0,0,-1};
bool flag[110];
void bfs(int x,int y,int num)
{
  if(map[x][y]!=num)
    return ;
  map[x][y]=0;
  for(int i=0;i<4;i++)
   bfs(x+dir[i][0],y+dir[i][1],num);
}          
int main()
{
   int x,y;
   while(cin>>n,n)
   {
     memset(map,0,sizeof(map));
     memset(flag,0,sizeof(flag));
     bool ans=1;
     for(int i=1;i<=n;i++)
     {
       for(int j=1;j<=n;j++)
       {
         map[i][j]=n;
       }
     }
     for(int i=1;i<n;i++)
     {
       for(int j=1;j<=n;j++)
       {
         cin>>x>>y;
         
         map[x][y]=i;
       }
     }/*
     for(int i=1;i<=n;i++)
     {
       for(int j=1;j<=n;j++)
       {
         cout<<map[i][j];
       }
       cout<<endl;
     }*/
     for(int i=1;i<=n&&ans;i++)
     {
       for(int j=1;j<=n&&ans;j++)
       {
         if(map[i][j])
         {
           if(flag[map[i][j]])
           {
            ans=0;
            break;
           }
             
           flag[map[i][j]]=1;
           bfs(i,j,map[i][j]);
         } 
           
       }
     }
     if(ans)
       cout<<"good"<<endl;
     else
       cout<<"wrong"<<endl;
   }
}       
       
       
         
         
