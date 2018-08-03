#include<iostream>
#include<cstring>
using namespace std;
bool a[10010];
int b[10010];
int main()
{
  memset(a,0,sizeof(a));
  a[0]=1;
  a[1]=1;
  for(int i=2;i<=10000;i++)
  {
    if(!a[i])
    for(int j=2;i*j<=10000;j++)
    {
      a[i*j]=1;
    }
  }
  memset(b,0,sizeof(b));int now=0;
  for(int i=1;i<=10000;i++)
  {
    if(!a[i])
      now++;
    b[i]=now;
  }
  /*for(int i=0;i<=10000;i++)
  {
    if(!a[i])
    {  cout<<i<<endl;
       
  }}*/      
  int c,d;
  while(cin>>c>>d)
  {
    int t=b[d]-b[c-1];
    //cout<<t<<endl;
    if(!a[t])
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}            
      
      