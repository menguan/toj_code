#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
string a;
string b;

int main()
{
  int t;
  cin>>t;
  getchar();
  while(t--)
  {
    getline(cin,a);
    getline(cin,b);
    int s1=0,s2=0,s3=0,s4=0;
    bool ss1=0,ss2=0;
    int len=a.length();
    for(int i=0;i<len;i++)
    {
      if(a[i]=='<')
      {
        if(ss1)
        {
          a.erase(i,1);
          len--;
          s3=i;
        }
        else
        {
          ss1=1;
          a.erase(i,1);
          len--;
          s1=i;
        }
      }
      if(a[i]=='>')
      {
        if(ss2)
        {
          a.erase(i,1);
          len--;
          s4=i-1;
        }
        else
        {
          ss2=1;
          a.erase(i,1);
          len--;
          s2=i-1;
        }
      }
      if(a[i]=='<')
      {
        if(ss1)
        {
          a.erase(i,1);
          len--;
          s3=i;
        }
        else
        {
          ss1=1;
          a.erase(i,1);
          len--;
          s1=i;
        }
      }
      if(a[i]=='>')
      {
        if(ss2)
        {
          a.erase(i,1);
          len--;
          s4=i-1;
        }
        else
        {
          ss2=1;
          a.erase(i,1);
          len--;
          s2=i-1;
        }
      }
    }
    for(int i=0;i<len;i++)
      cout<<a[i];
    cout<<endl;
      
    for(int i=0;i<b.length();i++)
    {
      if(b[i]!='.')
      {
        cout<<b[i];
      }
      else
      break;
    }
    for(int i=s3;i<=s4;i++)
      cout<<a[i];
    for(int i=s2+1;i<s3;i++)
      cout<<a[i];
    for(int i=s1;i<=s2;i++)
      cout<<a[i];
    for(int i=s4+1;i<len;i++)
      cout<<a[i];
    cout<<endl;
  }
}      