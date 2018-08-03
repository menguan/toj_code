#include<iostream>
#include<cstring>
using namespace std;

int fac[10000];
int main()
{
 
  
  fac[1]=1;
  int i;
  for(i=2;;i++)
  {
    fac[i]=fac[i-1]*i;
    if(fac[i]>10000000)
      break;
  }
  bool flag1,flag2;
  int m1,m2;
  //for(int j=1;j<i;j++)
  //{
  //  cout<<fac[j]<<endl;
  //}  
  bool use[i];
  while(cin>>m1>>m2)
  {
    if(m1==0&&m2==0)
      return 0;
    memset(use,0,sizeof(use));
    flag1=0;
    flag2=0;  
    for(int j=i-1;j>=1;j--)
    {
      if(m1>=fac[j]&&use[j]==0)
      {
        m1-=fac[j];
        use[j]=1;
      }
      
      if(m1==0)
      {
        flag1=1;
        break;
      }
    }
    for(int j=i-1;j>=1;j--)
    {
      if(m2>=fac[j]&&use[j]==0)
      {
        m2-=fac[j];
        use[j]=1;
      }
      if(m2==0)
      {
        flag2=1;
        break;
      }
    }
    if(flag1&&flag2)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
}        
        
           
          