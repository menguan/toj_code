#include<iostream>
using namespace std;
int pa[50];
int ma[50];
void f()
{
  pa[0]=1;
  ma[0]=1;
  for(int i=1;i<50;i++)
  {
     pa[i]=ma[i-1];
     ma[i]=pa[i-1]+ma[i-1];
  }
}      
int main()
{
  f();
  int n;
  cin>>n;
  while(n--)
  {
    int m;
    cin>>m;
    cout<<pa[m]<< " "<<ma[m]<<endl;
  }
}   