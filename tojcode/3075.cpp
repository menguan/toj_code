#include<iostream>
using namespace std;
int main()
{
  int n,m,k;
  while(cin>>n>>k>>m&&(n+m+k))
  {
    int pos=0;
    for(int i=2;i<=n-1;i++)
    {
      pos=(pos+k)%i;
    }
    cout<<1+(pos+m)%n<<endl;
  }
}      