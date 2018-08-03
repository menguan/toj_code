#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
string a,b,c;
int main()
{ 
  getline(cin,a);
  getline(cin,b);
  int len1=a.length();
  int len2=b.length();
  while(getline(cin,c))
  {
     
       
     int lenn=c.length();
     for(int i=0;i<lenn;i++)
     {
       //cout<<c.find(a,i)<<endl;
       if(c.find(a,i)>=0&&c.find(a,i)<lenn)
       {
         int t=c.find(a,i);
         c.erase(t,len1);
         c.insert(t,b,0,len2);
         lenn=lenn-len1+len2;
       }
     }if(c==a)
       c=b;
     cout<<c<<endl;
   }      
  
  
  
  }