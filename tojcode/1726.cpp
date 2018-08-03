#include<iostream>
using namespace std;
int fb[60];
void f()
{
  fb[0]=1;
  fb[1]=1;
  for(int i=2;i<60;i++)
    fb[i]=fb[i-1]+fb[i-2];
}    
int main()
{
  f();
  int n,m,count=1;
  cin>>n;
  while(n--)
  {
    cin>>m;
    cout<<"Scenario #"<<count++<<":"<<endl;
      cout<<fb[m+1]<<endl<<endl;
  }
}  