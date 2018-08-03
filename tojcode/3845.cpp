#include<iostream>
using namespace std;
int fib[1000];
int ans[100010];
void f()
{
  fib[1]=1;
  fib[2]=1;
  for(int i=3;i<1000;i++)
    fib[i]=fib[i-1]+fib[i-2];
  
  int now=1;
  ans[now++]=1;
  for(int i=3;;i++)
  {
    for(int j=0;j<fib[i];j++)
    {
      ans[now++]=i-1;
      if(now==100001)
        return ;
    }
  }
}        
    
      
int main()
{  
  f();
  
  int n;
  while(cin>>n)
    cout<<ans[n]<<endl;
}    
  
  