#include<iostream>
using namespace std;
int main()
{
 int n,m;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>m;
  cout<<(m/2)*((m-1)/2)<<endl;
 }
 
 return 0;
}