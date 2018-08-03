#include<iostream>
#include<string>
using namespace std;
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    int a,r=0;
    string s;
    cin>>a>>s;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
      r=(r*a+s[i]-'0')%10007;
    }
    cout<<r<<endl;
  }
}    