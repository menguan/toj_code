#include<iostream>
using namespace std;
int f(int n)
{
  int i,j; 
  for(i=n-1;i>0;i--)
  {
    int t=n;
    for(j=0;j<i;j++)
    {
      if(t%i!=1)
        break;
      else
      t=((t-1)/i)*(i-1);
      
    }
    if(j==i)
      return i;
  }
  return 0;
}      
          
          
int main()
{
  int n;
  while(cin>>n,~n)
  {
    int re=f(n);
    cout<<n<<" coconuts, ";
    if(!re)
    cout<<"no solution"<<endl;
    else
    cout<<re<<" people and 1 monkey"<<endl;
  }
  return 0;
} 