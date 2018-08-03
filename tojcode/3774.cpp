#include<iostream>
#include<string>
using namespace std;
string s;
bool isnum(char c)
{
  if(c>='0'&&c<='9')
    return 1;
  else
    return 0;
}         
int main()
{
  int t;
  
  while(cin>>s)
  {
    
    int len=s.length();
    int sum=0;
    char temp='+';
    int num1=0;
    int num2=0;
    int i,j;
    for(i=0;i<len;i++)
    {
      
      if(isnum(s[i]))
      {
        num1=num1*10+s[i]-'0';
      }
      else if(s[i]=='*'||s[i]=='/')
      {
        for(j=i+1;j<len;j++)
        {
          if(isnum(s[j]))
          num2=num2*10+s[j]-'0';
          else
          break;
        }
        
        if(s[i]=='*')
          num1*=num2;
        else
          num1/=num2;
         
        num2=0;  
        i=j-1;
      }
      else
      {
        
        
        
          if(temp=='-')
            sum-=num1;
          else
            sum+=num1;
          temp=s[i];
        
        num1=0;
      } 
    }
    if(temp=='-')
      sum-=num1;
    else
      sum+=num1;         
    cout<<sum<<endl;
  }
}        
        
        
          
          
        
        
  
  