#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
  int n;
  map<string,string>trans;
  char c[30];
  string s;
  cin>>n;
  while(n--) 
  {
    cin>>c;
    s=c;
    
    int len=strlen(c);
    if(len>2)
    {
      sort(c+1,c+len-1);
      c[len]='\0';
    }  
      trans[c]=s;
  }
  char t;
  while(cin>>c)
  {
    t=getchar();
    int len=strlen(c);
    if(len>2)
    {
      sort(c+1,c+len-1);
      c[len]='\0';
    } 
    
    cout<<trans[c]<<t;
  }
}      
    