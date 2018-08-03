#include<iostream>
using namespace std;
int main()
{
  int max=0;
  int have=0;
  int del=0;
  char c;
  int temp;
  while(cin>>c)
  {
    if(c=='n')
    {
      cin>>temp;
      if(temp>max)
        max=temp;
      have++;
    }
    if(c=='r')
    {
      del++;
    }
  }
  if(have<=del)
    cout<<0<<endl;
  else
    cout<<max*max<<endl;
  //while(1);
}      