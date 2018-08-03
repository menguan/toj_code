#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s1,s2;
  int t;
  cin>>t;
  while(t--)
  {
    cin>>s1>>s2;
    int len1=s1.length();
    int len2=s2.length();
    int m=s1[len1-1]-'0';
    int n=s2[len2-1]-'0';
    if((m+n)%2)
      cout<<"CANNOT"<<endl;
    else
      cout<<"MEET"<<endl;
  }
}        
      
      
       
   