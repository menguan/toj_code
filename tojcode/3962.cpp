#include<iostream>
using namespace std;
int main()
{
  int n,m,count=1;
  cin>>n;
  while(n--)
  {
    cin>>m;
    int t,count1;
    int sum=0;
    while(m--)
    {
      cin>>t;
      count1=0;
      do{count1+=(t%2);}while(t/=2);
      sum+=(count1-1);
    }
    
    cout<<"Case "<<count++<<": ";
    if(sum%2)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
}       