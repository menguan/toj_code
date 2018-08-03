#include<iostream>
using namespace std;
int f(int m,int n)
{
  int a=m>n?m:n;
  int b=m<n?m:n;int r;
  while(b)
  { 
    r=a%b;
    a=b;
    b=r;  
  }
  return a;
}          
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,b1,b2;
        cin>>n>>m>>b1>>b2;
        cout<<f(n-b1,m-b2)<<endl;
    }
    
    return 0;
}              
  