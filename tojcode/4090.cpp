#include<iostream>
#include<cstring>
using namespace std;
bool a[230010];
long long b[22010];
int getwei(int num)
{
  int r=0;
  while(num/=10)
    r++;
  return r+1;
}    
int main()
{
  
  memset(a,0,sizeof(a));
  a[0]=1;
  a[1]=1;
  for(int i=2;i<=2000;i++)
  {
    if(!a[i])
    for(int j=2;i*j<=230000;j++)
    {
      a[i*j]=1;
    }
  }int con=1;
  for(int i=1;i<=230000;i++)
    {
      if(!a[i])
        b[con++]=i;
    }    
  /*memset(b,0,sizeof(b));int now=0;int flag=0;int con=1;int we;int left,right;
  for(int i=1;i<=230000;i++)
  {
    if(!a[i])
    {
      if(flag==0)
      {
        flag=1;
        left=i;
        
      }
      else
      {
        flag=0;
        right=i;
        int ans=1;
        for(int j=0;j<getwei(right);j++)
         ans*=10;
       b[con++]=left*ans+right;
       //cout<<left<< " "<<right<<" "<<b[con-1]<<endl;
       //system("pause"); 
     }
   }      
        
  }
  
  /*for(int i=0;i<=10000;i++)
  {
    if(!a[i])
    {  cout<<i<<endl;
       
  }}*/      
  int c,d;
  while(cin>>c)
  {
    cout<<b[c*2-1]<<b[c*2]<<endl;
    
  }
}            
      
      