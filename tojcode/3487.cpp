#include<iostream>
#include<vector>
#include<map>
using namespace std; 
bool check(int n)
{
  int t;
  while(n)
  {
    t=n%10;
    if(t==3||t==4||t==7)
      return 0;
    n/=10;
  }
  return 1;
}
map<int,int>ud;
int main()
{
  ud[0]=0;
  ud[1]=1;
  ud[2]=2;
  ud[5]=5;
  ud[6]=9;
  ud[8]=8;
  ud[9]=6;
  vector<int>num;
  for(int i=1;i<12000000;i++)
  {
    if(check(i))
    {
      num.push_back(i);
    }
  }
  int t;
  while(cin>>t)
  {
    t=num[t-1];
    while(t)
    {
      cout<<ud[t%10];
      t/=10;
    }
    cout<<endl;
  }        
}        
