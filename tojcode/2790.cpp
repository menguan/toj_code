#include<iostream>
#include<cstring>
using namespace std;
bool flag[2000010];
int c,n,temp;
int main()
{
  memset(flag,0,sizeof(flag));
  cin>>c>>n;
  while(c--)
  {
    cin>>temp;
    for(int i=1;i*temp<=n;i++)
    {
      flag[i*temp]=1;
    }
  }
  int count=0;
  for(int i=1;i<=n;i++)
  {
    if(flag[i])
      count++;
  }
  cout<<count<<endl;
  //while(1);
}       