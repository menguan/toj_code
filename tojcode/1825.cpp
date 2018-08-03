#include<iostream>
using namespace std;
int main()
{
  double a,b,c;
  bool flag=1;
  while(cin>>a>>b>>c,a||b||c)
  {
    flag=1;
    if(a<=4.5&&b>=150&&c>=200)
    {
      cout<<"Wide Receiver ";
      flag=0;
    }
    if(a<=6.0&&b>=300&&c>=500)
    {
      
      cout<<"Lineman ";
      flag=0;
    }
    if(a<=5.0&&b>=200&&c>=300)
    {
      
      cout<<"Quarterback ";
      flag=0;
    }
    
    if(flag)
      cout<<"No positions";
    cout<<endl;
  }
}              