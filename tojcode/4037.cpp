#include<iostream>
using namespace std;
int main()
{
  int n,a,b;
  cin>>n;
  while(n--)
  {
    cin>>a>>b;
    int end;
    for(int i=0;i<a;i++)
    for(int j=0;j<b;j++)
      cin>>end;
      
    if(end)
      cout<<"Alice"<<endl;
    else
      cout<<"Bob"<<endl;
  }
}   