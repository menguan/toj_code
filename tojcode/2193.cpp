#include<iostream> 
using namespace std;
int main()
{
  int a,b;
  while(cin>>a,a)
  {
    cin>>b;
    if(a%(b+1))
    cout<<"Just Do It."<<endl;
    else
    cout<<"Think About It."<<endl;
  }
}    