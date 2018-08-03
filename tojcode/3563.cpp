#include<iostream>
using namespace std;
int a[2010];
int main()
{
  int n,m,q;
  cin>>n>>m>>q;
  for(int i=1;i<=n;i++)
  {
    a[i]=i;
  }
  int j,k;
  while(m--)
  {
    cin>>j>>k;
    int temp=a[j];
    for(int i=1;i<=n;i++)
    {
       if(a[i]==temp)
         a[i]=a[k];
    }
  }
  while(q--)
  {
    cin>>j>>k;
    if(a[j]==a[k])
      cout<<"Y"<<endl;
    else
      cout<<"N"<<endl;
  }
}        
       