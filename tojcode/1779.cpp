#include<iostream>
using namespace std;
long long a[31];
void f()
{
     a[0]=1;
     a[2]=3;
     for(int i=4;i<=30;i++)
     {
        a[i]=4*a[i-2]-a[i-4];
        }
}                 
int main()
{
    f();
    int n;
    while(cin>>n&&n!=-1)
    {
      if(n%2)
       cout<<"0"<<endl;
      else
        cout<<a[n]<<endl;
}
}