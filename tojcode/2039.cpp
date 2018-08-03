#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
 cout<<"# Cards  Overhang"<<endl;
 int a;
 while(cin>>a)
 {
  double sum=0;
  for(int i=1;i<=a;i++)
  sum+=1.0/(2.0*i);
  cout<<setw(5)<<a;
  cout<<setw(10)<<setprecision(3)<<fixed<<sum<<endl;
  
 }
 return 0;
}
