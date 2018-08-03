#include<iostream>
#include<string>
using namespace std;
int main()
{
  int n;
  string s;
  int count=1;
  cin>>n;
  while(n--)
  {
    cin>>s;
    int l=s.length();
    int a[l];
    bool b[l];
    cout<<"Scenario #"<<count++<<":"<<endl;
    int flag;
    for(int i=0;i<l;i++)
    {
      b[i]=1;
      if(s[i]=='?')
      {
         b[i]=0;
         flag=i;
      }
      else
      a[i]=s[i]-'0';
    }
    int f[3]={9,7,3};
    int sum=0;
    for(int i=l-1;i>=0;i--)
    {
      if(b[i])
      {
        if(l==7)
         sum+=f[i%3]*a[i];
        else if(l==6)
         sum+=f[(i+1)%3]*a[i];
      }   
    }
    for(int i=0;i<=9;i++)
    {
      if(l==7)
      {  
        if((sum+f[flag%3]*i)%10==0)
        {
          s[flag]=i+'0';
          break;
        }
      }
      else if(l==6)
      {  
        if((sum+f[(flag+1)%3]*i)%10==0)
        {
          s[flag]=i+'0';
          break;
        }
      }
    }
    cout<<s<<endl<<endl;
  }
}  