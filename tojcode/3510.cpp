#include<iostream>
#include<cstring>
using namespace std;
bool k[1000010];
int main()
{
  int m=1000001;
  int a,b;memset(k,0,sizeof(k));
    for(int i=1;i<=m;i++)
    {
      for(int j=i;j<=m;j+=i)
      {
        k[j]^=1;
      }
    }
    
  while(cin>>m>>a>>b&&(a+b+m))
  {
    int cnt=0;
    for(int i=a;i<=b;i++)
    {
      if(k[i])
        cnt++;
    }
    cout<<cnt<<endl;
  }
}       