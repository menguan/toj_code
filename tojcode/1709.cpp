#include <iostream>
using namespace std;
int main()
{
 int t,count=1;
 int a,b,c,d;
 cin>>t;
 while(t--)
 {
   cin>>a>>b>>c>>d;
   cout<<"Scenario #"<<count++<<":"<<endl<<(a+b+c+d)%2<<endl<<endl;
 }
}
