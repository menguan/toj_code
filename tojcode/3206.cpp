#include<iostream>
using namespace std;
int main()
{
  int sum[400];
  int price[10];
  int n;
  int c;
  for(int i=0;i<400;i++)
  sum[i]=0;
  sum[0]=1;
  cin>>n>>c;
  for(int i=0;i<c;i++)
    cin>>price[i];
  for(int i=0;i<c;i++)
  {
    for(int j=0;j+price[i]<=n;j++)
    {
      sum[j+price[i]]+=sum[j];
    }
  }
  cout<<sum[n]<<endl;
  //while(1);
}      