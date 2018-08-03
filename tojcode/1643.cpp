#include<iostream>
using namespace std;
int main()
{
int p,s,count=1;

  while(cin>>p>>s,p)
  {
   cout<<"Hole #"<<count++<<endl;
   if(s==1)
    cout<<"Hole-in-one."<<endl;
   else if(s==p)
    cout<<"Par."<<endl;
   else if(p-s==1)
    cout<<"Birdie."<<endl;
   else if(p-s==2)
    cout<<"Eagle."<<endl;
   else if(p-s==3)
    cout<<"Double Eagle."<<endl;
   else if(s-p==1)
    cout<<"Bogey."<<endl;
   else if(s-p>=2)
    cout<<"Double Bogey."<<endl;
   cout<<endl;
  }
}