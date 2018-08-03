#include<iostream>
using namespace std;
int main()
{
  int t,count=1;
  cin>>t;
  while(t--)
  {
    int n,d,b,e;
    cin>>n>>d>>b>>e;
    cout<<"Problem set "<<count++<<": "<<n<<" / "<<d<<", base 7 digits "<<b<<" through "<<e<<": ";
    n%=d;
    int temp;
    for(int i=0;i<=e;i++)
    {
      temp=n*7/d;
      n=n*7%d;
      if(i>=b)
        cout<<temp;
    }
    cout<<endl;
  }
}        
  