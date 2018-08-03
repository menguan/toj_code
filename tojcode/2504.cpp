#include<iostream>
using namespace std;
int len[100];int sum[100];
int main()
{
  len[1]=1;sum[1]=1;
  len[2]=1;sum[2]=2;
  len[3]=2;sum[3]=3;
  for(int i=4;i<41;i++)
  {
    len[i]=len[i-1]+len[i-2];
    sum[i]=sum[i-1]+len[i-1];
  }  
  int t;int k;
  cin>>t;
  while(t--)
  {
    cin>>k;
    bool flag=0;
    for(int i=40;i>=1;i--)
    {
      if(k>=sum[i])
      {
        //cout<<sum[i]<<" "<<i<<endl;
        k-=sum[i];
        flag=1;
        cout<<1;
      }
      else if(flag&&k<sum[i])
        cout<<0;
    }
    cout<<endl;
  }
}         