#include<iostream>
using namespace std;
int k[500010];
bool kk[10000000]={0};
void f()
{
  k[0]=0;
  for(int i=1;i<=500000;i++)
  {
    if(k[i-1]-i>0&&kk[k[i-1]-i]==0)
    {
      k[i]=k[i-1]-i;     
      kk[k[i-1]-i]=1;
    }
    else 
    {
      k[i]=k[i-1]+i;     
      kk[k[i-1]+i]=1; 
    }
  }
}
int main()
{
  f();
  
  
  int n;
  while(cin>>n)
  {
    if(n==-1)
      return 0;
    else
      cout<<k[n]<<endl;
  }
}
