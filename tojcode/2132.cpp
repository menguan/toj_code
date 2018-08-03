#include<iostream>
using namespace std;
int main()
{
  int a[100001];
  int n;
  kk:while(cin>>n,n)
  {
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
      if(i!=a[a[i]])
      {cout<<"not ambiguous"<<endl;
       goto kk;}
    }
    cout<<"ambiguous"<<endl;
  }
}    