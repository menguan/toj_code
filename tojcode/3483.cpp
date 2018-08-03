#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int t;
  int a,b;
  cin>>t;
  while(t--)
  {
    cin>>a>>b;
    while(a-b)
    {
      int t=a;
      a=abs(a-b);
      b=min(t,b);
    }
    int count=0;
    for(int i=1;i<=a;i++)
    {
      if(a%i==0)
        count++;
    }
    cout<<count<<endl;
  }
}          
      
