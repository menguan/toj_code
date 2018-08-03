#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
char map[7][7];

int dir[4][2]={2,0,0,2,-2,0,0,-2};
int dir2[4][2]={1,0,0,1,-1,0,0,-1};
int main()
{
  int count=0;
  
  for(int i=0;i<7;i++)
    gets(map[i]);
  int x,y,x2,y2;
  for(int i=0;i<7;i++)
  {
    for(int j=0;j<7;j++)
    {
      if(map[i][j]=='o')
      {
        
        for(int k=0;k<4;k++)
        {
          x=i+dir[k][0];
          y=j+dir[k][1];
          x2=i+dir2[k][0];
          y2=j+dir2[k][1];
          if(x>6||x<0||y>6||y<0)
            continue;
          
          if(map[x][y]=='.'&&map[x2][y2]=='o')
          {
            
            count++;
          }  
        }
      }
    }
  }
  cout<<count<<endl;
  //while(1);
}                        
  
  