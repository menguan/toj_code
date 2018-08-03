#include<iostream>
#include<string>
using namespace std;
int main()
{
  int t;
  cin>>t;
  string s1,s2;
  while(t--)
  {
    cin>>s1>>s2;
    int len1=s1.length();
    int len2=s2.length();
    if(len1<len2)
    {
      cout<<"no"<<endl;
      continue;
    }
    
    int count=0;
    int start=0;
    while(start<len1)
    {
      if(s2[count]==s1[start])
      {
        count++;
        start++;
        if(count==len2)
        {
          break;
        }  
      }
      else
        start++;
    } 
    if(count==len2)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
}  