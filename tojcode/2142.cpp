#include<iostream>
using namespace std;
bool a[600][600];
int main()
{
  int m,n;
  while(cin>>m>>n)
  {
    if(m==0&&n==0)
      return 0;
      
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        cin>>a[i][j];
      }
    }
    bool flag=0;
    for(int i=0;i<m;i++)
    {
      int sum=0;
      for(int j=0;j<n;j++)
      {
        sum+=a[j][i];
      }
      if(sum==n)
        flag=1;
    }
    if(flag)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
   }
}   