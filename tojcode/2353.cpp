#include<iostream>
#include<cstring>
using namespace std;
int a[310];
bool b[1000100];
int k[310];
void f(int kk)
{
  for(int i=0;i<kk;i++)
    b[k[i]]=0;
}
int main()
{
  int t,n;
  
  cin>>t;
  while(t--)
  {
    memset(b,0,sizeof(b));
    cin>>n;int max=0;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      if(max<a[i])
      max=a[i];
    }
    int j;
    int kk=0;
    bool g=0;
    for(int i=n;;i++)  
    {
      f(kk);
      kk=0;
      for(j=0;j<n;j++)
      {
        if(b[a[j]%i])
          break;
        b[a[j]%i]=1;
        k[kk++]=a[j]%i;
      }
      if(j==n)
      {
        cout<<i<<endl;
        
        break;
      }
    }  
  }
}   