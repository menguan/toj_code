#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int f(char c)
{
  if(c>=65&&c<=90)
    return (int)c;
  else if(c>=97&&c<=122)
    return (int)(c-32);
}    
    
int main()
{
  string a;
  while(getline(cin,a))
  {
    if(a=="THE END.")
    return 0;
    int len=a.length();
    
    int i,j;
    for(int k=0;k<len;)
    {
      if(!((a[k]>=65&&a[k]<=90)||(a[k]>=97&&a[k]<=122)))
      {  
         a.erase(k,1);
         len--;
      }              
      else
        k++;
    }
    len=a.length();      
    
      
    
    bool flag=0;
    i=0;
    j=len-1;
    while(1)
    {
      
      
      if(f(a[i++])==f(a[j--]))
      {
                  if(i==len)
                    break;
                  else
                    continue;
      }
      else
      {
        flag=1;
        break;
      }
    }
    if(flag==1)
      cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl; 
  }
}      
    