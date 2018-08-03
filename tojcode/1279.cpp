#include<iostream>
#include<algorithm>
using namespace std;
int a[1010];
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    int m,max=0;
    cin>>m;
    for(int i=0;i<m;i++)
    {
      cin>>a[i];
    }
    sort(a,a+m);
    
    for(int i=0;i<m;i++)
    {
      if(a[i]*(m-i)>max)
      max=a[i]*(m-i);
    }
    cout<<max<<endl;
  }
}     