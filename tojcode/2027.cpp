#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
  int a,b;
  kk:while(cin>>a>>b)
  {
    for(int i=2;i<=a&&i<=b;i++)
    {
      if(a%i==0&&b%i==0)
      {
        cout<<setw(10)<<a<<setw(10)<<b<<"    Bad Choice"<<endl<<endl;
        goto kk;
      }
    }
    cout<<setw(10)<<a<<setw(10)<<b<<"    Good Choice"<<endl<<endl;
  }     
    
  return 0; 
}