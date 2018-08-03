#include<iostream>
using namespace std;
int a[3000];long long sum=0;
void f(int st,int end)
{
  if(end==st)
    return;
  else if(end-st==1)
    sum+=(a[end]*a[st]);
  else
  {
      f(st,(end-st)/2+st);
      f((end-st)/2+st+1,end);
  }
}         
      
int main()
{
  int n;
  for(int i=0;i<3000;i++)
    a[i]=i;
  
  cin>>n;
  f(1,n);
  
  cout<<sum<<endl;
  
}      