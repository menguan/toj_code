#include<iostream>
#include<cmath>
int a[15][2]={0,0,0,1,0,2,0,3,1,0,1,1,1,2,1,3,2,0,2,1,2,2,2,3,3,0,3,1,3,2};
using namespace std;
char map[4][4];
int main()
{
  for(int i=0;i<4;i++)
    cin>>map[i];
  int sum=0;
    
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      if(map[i][j]!='.')
      {
        int temp=map[i][j]-'A';
        sum+=abs(a[temp][0]-i);
        sum+=abs(a[temp][1]-j);
      }
    }
  }
  cout<<sum<<endl;
  //while(1);
}        
          