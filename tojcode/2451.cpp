#include<iostream>
#include<cstring>
using namespace std;
bool ans=1;
char map[10][10];
int a[5];int size;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
void bfs(int i,int j)
{
  map[i][j]='.';
  for(int k=0;k<4;k++)
  {
    if(map[i+dir[k][0]][j+dir[k][1]]=='1')
    {
      size++;
      bfs(i+dir[k][0],j+dir[k][1]);
    }
  }
}      
       
int main()
{
  memset(a,0,sizeof(a));
  for(int i=0;i<10;i++)
  {
    for(int j =0;j<10;j++)
    {
      cin>>map[i][j];
    }
  } 
  for(int i=0;i<10;i++)
  {
    if(map[i][0]=='1'||map[0][i]=='1'||map[i][9]=='1'||map[9][i]=='1')
      ans=0;
  }
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(map[i][j]=='1'&&map[i+1][j+1]=='1')
        ans=0;
      if(map[i+1][j]=='1'&&map[i][j+1]=='1')
        ans=0;  
    }
  }      
      
  if(ans)    
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    {
      if(map[i][j]=='1')
      {
        size=1;
        bfs(i,j);
        
        a[size]++;
        
      }  
    }
  }
  //cout<<a[4]<<" "<<a[3]<<" "<<a[2]<<" "<<a[1]<<endl;
  
  if(a[4]==1&&a[3]==2&&a[2]==3&&a[1]==4&&ans)
  {
    cout<<"correct"<<endl;
  }
  else
    cout<<"incorrect"<<endl;
  //while(1);
}      

    
