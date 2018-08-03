#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s;
  while(cin>>s)
  {
    int len=s.length();
    int num=1;
    int now=s[0]-'0';
    if(now<3)
    {now*=10;
    now+=s[num++]-'0';
    }
    cout<<now/3;
    now%=3;
    while(num<len)
    {
      now*=10;
      now+=s[num++]-'0';
      cout<<now/3;
      now%=3;
    }
    cout<<endl;
  }
}     