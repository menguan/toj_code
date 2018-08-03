#include<iostream>
#include<cmath>
#define eps 0.000000001
using namespace std;
char map[110][110];
long long f(int a,int b)
{
  if(a>b/2)
  {
    a=b-a;
  }
  long long ret=1;
  for(int i=1;i<=a;i++)
  {
    ret=ret*(b-i+1)/i;
  }
  return ret;
}    
    
    
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>map[i][j];
    }
  }
  long long ans=0;
  int count;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(map[i][j]=='.')
        continue;
      for(int x=0;x<n;x++)
      {
        for(int y=0;y<n;y++)
        {
          if(map[x][y]=='.')
        continue;
          for(int m=0;m<n;m++)
          {
            for(int nn=0;nn<n;nn++)
            {
              if(map[m][nn]=='.')
        continue;
        if(nn==y&&y==j&&m!=x&&m!=i&&i!=x)
          {ans++;
          continue;}
          else if(nn!=y&&y!=j&&nn!=j&&m==x&&m==i)
          {ans++;//cout<<m<<" "<<nn<<" "<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
          continue;}
              if(fabs((m-x)*1.0/(x-i)-(nn-y)*1.0/(y-j))<=eps&&m!=x&&m!=i)
                ans++;
             }
          }      
          
        }
      }
      
    }
  }
  cout<<ans/6<<endl;
  //while(1);
}        
              
          
       
      