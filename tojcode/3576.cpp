#include<iostream>
using namespace std;
int ans[10100];
int t00=1;
int t01=1;
int t10=1;
int t11=1;
void f()
{
  ans[0]=0;
  ans[1]=2;
  ans[2]=4;
  for(int i=3;i<=10000;i++)
  {
    int b00=t00;
    int b01=t01;
    int b10=t10;
    int b11=t11;
    t00=(b00+b10)%9997;
    t10=(b01+b11)%9997;
    t01=(b00)%9997;
    t11=(b01+b11)%9997;
    
    ans[i]=(t01+t00+t11+t10)%9997;
  }
}    
    
  
int main()
{
  f();
  int n;
  while(cin>>n,~n)
  {
    cout<<ans[n]<<endl;
  }
}    
  