#include<iostream>
#include<vector>

using namespace std;
long long a[1000010];
void f()
{
  a[0]=0;
  a[1]=1;
  a[2]=4;
  a[3]=10; 
  for(int i=4;i<1000010;i++)
  {
    a[i]=a[i-1]+a[i-1]-a[i-2]+i;
   
  }
}    

int main()
{
  f();
  int n;
  while(cin>>n)
  {
    cout<<a[n]<<endl;
  }
}   