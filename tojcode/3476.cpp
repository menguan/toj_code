#include<iostream>
using namespace std;
int a[1200010];
int main()
{
  int n,q,beat;
  cin>>n>>q;
  int count=0;
  for(int i=1;i<=n;i++)
  {
    cin>>beat;
    for(int j=0;j<beat;j++)
    {
      a[count++]=i;
    }
  }
  int r;
  while(q--)
  {
    cin>>r;
    cout<<a[r]<<endl;
  }
  //while(1);
}  
        
  
  