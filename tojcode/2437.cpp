#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int len=s.length();
  for(int i=0;i<len-2;i++)
  {
    if(s[i]==s[i+2])
    {
      if(len%2)
      {
        cout<<1<<endl;
        return 0;
      }
      else
      {
        cout<<2<<endl;
        return 0;
      }
    }
  }
  cout<<len<<endl;
  return 0;
}          
    