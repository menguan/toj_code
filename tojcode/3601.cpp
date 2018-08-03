#include<iostream>
#include<algorithm>
using namespace std;
int a[1000];
int b[1000];
int main()
{
  int m,n;
  cin>>m>>n;
  for(int i=0;i<m;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
    cin>>b[i];
  int maxn=-1;  
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(a[i]==b[j])
      {
        int count=1;
        int ii=i+1,jj=j+1;
        while(a[ii]==b[jj]&&ii<m&&jj<n)
        {
          count++;
          ii++;
          jj++;
        }
        if(count>maxn)
          maxn=count;  
      } 
    }
  }
  
  cout<<maxn<<endl;
  //while(1);
}              