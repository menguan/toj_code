#include<iostream>
#include<string>
using namespace std;
bool isnum(char c)
{
  if(c>='0'&&c<='9')
    return 1;
  return 0;
}    
    
long long f(string s)
{
  int len=s.length();
  long long ans=0;long long now=1;
  for(int i=len-1;i>=0;i--)
  {
    if(isnum(s[i]))
    {
      ans+=now*(s[i]-'0');
    }
    else
    {
      ans+=now*(s[i]-'A'+10);
    }
    now*=16;
  }
  return ans;
}      
        
  
int main()
{
  string s;
  while(cin>>s)
  {
    int ans=0;
    cout<<f(s)<<endl;
  }
}    