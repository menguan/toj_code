#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
  while(cin>>s)
  {
    int len=s.length();
    int flag;
    int a=0,b=0,c=0;
    for(int i=0,j=1;;i++,j*=10)
    {
      if(s[i]=='+')
      {
        flag=i;
        break;
      }  
      a+=(s[i]-'0')*j;
        
    }
    for(int i=flag+1,j=1;;i++,j*=10)
    {
      if(s[i]=='=')
      {
        flag=i;
        break;
      }  
      b+=(s[i]-'0')*j;
        
    }
    for(int i=flag+1,j=1;i<len;i++,j*=10)
    {
      c+=(s[i]-'0')*j;
    }
    if(a+b==c)
      cout<<"True"<<endl;
    else
      cout<<"False"<<endl;
  }
}       