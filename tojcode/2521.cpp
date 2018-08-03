#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
 char s[100];
 int sum;
 while(gets(s))
 {
  if(s[0]=='#')
    break;    
  sum=0;
  int len=strlen(s);
  for(int i=0;i<len;i++)
  {
   if(s[i]=='.')sum+=100;   
   if(s[i]=='/')         
   {
    if(i==0)sum+=100;        
    for(int j=i-1;j>=0;)     
    {
     if(s[j]=='|')break;
     if(s[j]=='/')break;
     if(s[j]=='\\')break;
     if(s[j]=='.')
     {sum+=100;break;}
     if(j==0){sum+=100;break;}
     if(s[j]=='_')--j;
    }
   };
   if(s[i]=='\\')           
   {
    if(i==strlen(s))sum+=100;   
    for(int j=i+1;j>0;)         
    {
     if(s[j]=='|')break;
     if(s[j]=='/')break;
     if(s[j]=='\\')break;
     if(s[j]=='.')
     {sum+=100;break;}
     if(s[j]=='_')++j;
     if(j==strlen(s)){sum+=100;break;}
    }
   };
   if(s[i]=='|')            
   {
    if(i==0)sum+=50;
    for(int j=i-1;j>=0;)   
    {
     if(s[j]=='|')break;
     if(s[j]=='/')break;
     if(s[j]=='\\')break;
     if(s[j]=='.')
     {sum+=50;break;}
     if(j==0){sum+=50;break;}
     if(s[j]=='_')--j; 
    }
    if(i==strlen(s))sum+=50;
    for(int j=i+1;j>0;)   
    {
     if(s[j]=='|')break;
     if(s[j]=='/')break;
     if(s[j]=='\\')break;
     if(s[j]=='.')
     {sum+=50;break;}
     if(s[j]=='_')++j;
     if(j==strlen(s)){sum+=50;break;}
    }
   };
  }
   sum/=len;;
   cout<<sum<<endl;
 }
 return 0;
}
