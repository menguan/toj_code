#include<iostream>
using namespace std;

long long a[100][100];
void f()
{
  for(int i=0;i<60;i++)
  {
    a[i][0]=a[i][i]=1;
  }  
  for(int i=1;i<60;i++)
  {
    for(int j=1;j<=i;j++)
    {
      a[i][j]=a[i-1][j-1]+a[i-1][j];
    }
  }
}
int main()
{
  f();
  int n;
  while(cin>>n)
  {
    if(n<0)
      return 0;
    if(n==0)
    {
      cout<<1<<endl;
      continue;
    }      
    cout<<1;
    for(int i=1;i<n;i++)
    {
      cout<<" "<<a[n][i];
    }
    cout<<" "<<1<<endl;
  }
}      