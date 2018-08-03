#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int r,c;
char a[400][400];
bool ok(int x,int y,int n)
{
  int cnt=n*n/2;
  for(int i=x;i<=x+n-1;i++)
  {
    if(!cnt)  break;
    for(int j=y;j<=y+n-1;j++)
    {
      if(!cnt)  break;
      if(a[i][j]!=a[2*x+n-i-1][2*y+n-j-1])
      {
       // cout<<n<<" "<<i<<" "<<j<<" "<<2*x+n-i-1<<" "<<2*y+n-j-1<<endl;
        return 0;
      }
      cnt--;
    }
  }
  return 1;
}  
      
int main()
{
  scanf("%d%d",&r,&c);
  for(int i=0;i<r;i++)
    scanf("%s",a[i]);
  int n=min(r,c);
  int ans=-1;
  bool flag=0;
  while(n>=2)
  {
    if(flag)  break;
    for(int i=0;i<=r-n;i++)
    {
      if(flag)  break;
      for(int j=0;j<=c-n;j++)
      {
        if(flag)  break;
        if(ok(i,j,n))
        {
          ans=n;
          flag=1;
        }  
      }
    }
    n--;
  }
  printf("%d\n",ans);
 // while(1);
}
  