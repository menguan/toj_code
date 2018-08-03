#include<iostream>
using namespace std;
int main()
{
  int A,a,B,b,p;
  while(cin>>A>>a>>B>>b>>p)
  {
    if((B<=p&&A<=b)||(A<=p&&B<=a)||(A+B<=p))
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
return 0;
}