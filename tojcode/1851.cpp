#include<iostream>
#include<cstring>
#include<stack> 
using namespace std;
char a[200][200];
bool flagx[200][200];
bool flagy[200][200];
bool flags[200][200];
int n=3;
struct f
{
  int x,y,num;
};  
int main()
{
  int t;
  cin>>t;
  while(t--){
  
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
  
  for(int i=0;i<n*n;i++)
  {
    for(int j=0;j<n*n;j++)
    {
      if(a[i][j])
      {
        
          flagx[i][a[i][j]-'0']=1;
        
          flagy[j][a[i][j]-'0']=1;
        
          flags[i/n*n+j/n][a[i][j]-'0']=1;
      }
    }
  }
  int i,j,k;
  stack<f> q;
  f now;
  for(i=0;i<n*n;i++)
  {
    for(j=0;j<n*n;j++)
    {
      if(a[i][j]=='0')
      {
        
        for(k=1;k<=10;)
        {
          if(k==10)
          {
            
            now=q.top();
            q.pop();
            i=now.x;
            j=now.y;
            a[i][j]='0';k=now.num;
            flagx[i][k]=flagy[j][k]=flags[i/n*n+j/n][k]=0;
            k++;
            continue;
          }  
          else if(flagx[i][k]==0&&flagy[j][k]==0&&flags[i/n*n+j/n][k]==0)
          {
            flagx[i][k]=flagy[j][k]=flags[i/n*n+j/n][k]=1;
            a[i][j]=k+'0';
            now.x=i;
            now.y=j;
            now.num=k;
            q.push(now);
            break;
          }
          k++;
          
        }
        
      }
    }
  }
  for(int i=0;i<n*n;i++)
  {
    for(int j=0;j<n*n;j++)
    {
      cout<<a[i][j];
    }
    cout<<endl;
  }
            
          
      
  
  }
}      
          
                
                