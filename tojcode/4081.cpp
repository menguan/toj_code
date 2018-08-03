#include<iostream>
#include<stack>
#include<cstring> 
#include<string>
using namespace std;
struct f
{
  int now;
  int end;
  char s[1000][20];
}a[4];  
int main()
{
  int n;
  while(cin>>n)
  {
    memset(a,0,sizeof(a));int nn=0;
    strcpy(a[0].s[0],"C:");
    strcpy(a[0].s[1],"users");
    strcpy(a[0].s[2],"godle");
    strcpy(a[1].s[0],"D:");
    strcpy(a[2].s[0],"E:");
    strcpy(a[3].s[0],"F:");
    a[0].end=2;char st[20];;
    while(n--)
    {
      cin>>st;
      if(strcmp(st,"cd")==0)
      {
        cin>>st;
        if(strcmp(st,"..")==0)
        {
          if(a[nn].end!=0)
            a[nn].end--;
        }
        else
        {
          a[nn].end++;
          strcpy(a[nn].s[a[nn].end],st);
        }
      }
      else
      {
        if(strcmp(st,"C:")==0)
        {nn=0;
          }
          else if(strcmp(st,"D:")==0) 
          nn=1;
          else if(strcmp(st,"E:")==0) 
          nn=2;
          else if(strcmp(st,"F:")==0) 
          nn=3;
        
      }
      for(int i=0;i<=a[nn].end;i++)
      {
        if(i!=0)
       cout<<"\\";
        cout<<a[nn].s[i];
      }
      cout<<endl;
    }
  }
}               
          
    
    
    
    
    