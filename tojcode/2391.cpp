#include<iostream>
#include<string>
using namespace std;
int a1[150]={0};
int a2[150]={0};
int b1[150]={0};
int b2[150]={0};
string s;
int main()
{
  cin>>s;
  for(int i=0;i<s.length();i++)
  {
    a1[(int)s[i]]++;
  }
  cin>>s;
  for(int i=0;i<s.length();i++)
  {
    a2[(int)s[i]]++;
  }
  for(int i=0;i<150;i++)
  {
    if(a1[i])
      b1[a1[i]]++;
  }
  for(int i=0;i<150;i++)
  {
    if(a2[i])
      b2[a2[i]]++;
  }
  for(int i=0;i<150;i++)
  {
    if(b1[i]!=b2[i])
    {
      cout<<"NO"<<endl;
      
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}     