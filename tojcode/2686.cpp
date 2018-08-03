#include<iostream>
#include<cstring>
using namespace std;
int a[200][200];
bool flagx[200][200];
bool flagy[200][200];
bool flags[200][200];
int main()
{
  int n;
  while(cin>>n){
  memset(a,0,sizeof(a));
  memset(flagx,0,sizeof(flagx));
  memset(flagy,0,sizeof(flagy));
  memset(flags,0,sizeof(flags));
  
  for(int i=0;i<n*n;i++)
  {
    for(int j=0;j<n*n;j++)
    {
      cin>>a[i][j];
    }
  }
  bool flag=1;
  for(int i=0;i<n*n&&flag;i++)
  {
    for(int j=0;j<n*n&&flag;j++)
    {
      if(a[i][j]&&flag)
      {
        if(flagx[i][a[i][j]])
        {
          flag=0;
          break;
        }
        else
          flagx[i][a[i][j]]=1;
        if(flagy[j][a[i][j]])
        {
          flag=0;
          break;
        }
        else
          flagy[j][a[i][j]]=1;
        if(flags[i/n*n+j/n][a[i][j]])
        {
          flag=0;
          break;
        }
        else
          flags[i/n*n+j/n][a[i][j]]=1;
      }
    }
  }
  if(flag)
    cout<<"CORRECT"<<endl;
  else
    cout<<"INCORRECT"<<endl;
  }
}      
          
                
                