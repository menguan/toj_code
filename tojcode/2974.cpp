#include<iostream>
#include<cstring>
using namespace std;
int a[1000000];
int get(int n)
{
  int sum=0;
  while(n)
  {
    sum+=n%10;
    n/=10;
  }
  return sum;
}    
void f()
{
  memset(a,0,sizeof(a));
  int i;
  i=9;
  while(i<1000000)
  {
    a[i]=9;
    i+=get(i);
  }
  i=3;
  while(i<1000000)
  {
    a[i]=3;
    i+=get(i);
  }
  i=1;
  while(i<1000000)
  {
    a[i]=1;
    i+=get(i);
  } 
}
int main()   
{
  f();
  int n,i;
  while(cin>>n,n)
  {
    i=n;
  while(i<1000000)
  {
    if(a[i])
      break;
    i+=get(i);
  }     
  cout<<a[i]<<" "<<i<<endl;
  }
}     