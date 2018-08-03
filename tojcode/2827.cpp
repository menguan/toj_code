#include<iostream>
#include<cstring>
#include<algorithm>
using  namespace std;
int get[10][10];
int map[10][10];
int main()
{
  int n;
  char t[10];
  while(cin>>n)
  {
    memset(get,0,sizeof(get));
    memset(map,0,sizeof(map));
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cin>>t;
        if(t[0]=='A')
          map[i][j]=1;
        else if(t[0]=='T')
          map[i][j]=10;
        else if(t[0]=='J')
          map[i][j]=11;
        else if(t[0]=='Q')
          map[i][j]=12;
        else if(t[0]=='K')
          map[i][j]=13; 
        else
          map[i][j]=t[0]-'0';
      }
    }
   
    for(int j=1;j<=n;j++)
    {
      for(int i=n;i>=1;i--) 
      {
         get[i][j]=map[i][j]+max(get[i][j-1],get[i+1][j]);
      }
    }  
    cout<<get[1][n]<<endl;
  }
}        
                  