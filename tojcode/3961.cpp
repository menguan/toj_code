#include<iostream>
using namespace std;
int main()
{
  int a,b;
  int count=1;
  while(cin>>a>>b)
  {
    cout<<"Case "<<count++<<": ";
    if(b==1)
    {
      if(a%2)
        cout<<"Bob"<<endl;
      else
        cout<<"Alice 1"<<endl;
    }
    else if(2*b+1==a)
      cout<<"Alice "<<b<<endl;
    else
      cout<<"Alice 1"<<endl;
   }
} 