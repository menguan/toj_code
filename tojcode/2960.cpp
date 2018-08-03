#include<iostream>
#include<string> 
#include<algorithm>
using namespace std;
string f(string st1, string st2)
{
string st;
int a[2000]={0},b[2000]={0};
int len1,len2,len,i;
len1=st1.length();
len2=st2.length();
for(i=len1-1;i>=0;i--)
   a[len1-i]=st1[i]-'0';
for(i=len2-1;i>=0;i--)
   b[len2-i]=st2[i]-'0';
len=(len1>len2)?len1:len2;
for (i=1;i<=len;i++)
   a[i]=a[i]+b[i];
for (i=1;i<=len;i++)
   if (a[i]>9)
   {
    a[i+1]+=a[i]/ 10;
    a[i]%=10;
    if (i==len ) len++;
   }
   st="";
   for (i=0;i<len;i++)
    st+=a[len-i]+'0';
   return st;
} 
char temp1[10];
char temp2[10];
int len;
bool com(string s1,string s2)
{
  for(int i=0;i<len;i++)
  {
    temp1[i]=s1[i];
    temp2[i]=s2[i];
  }
  sort(temp1,temp1+len);
  sort(temp2,temp2+len); 
  int j;
  for(j=0;j<len;j++)
  {
    if(temp1[j]!=temp2[j])
      return 0;
  }
  return 1;
}       

int main()
{
  
  
  string s;
  cin>>s;
  string s2=s;
  len=s.length();
  bool flag=0;
  while(1)
  {
    s2=f(s2,"1");
    if(s2.length()==len+1)
      break;
    
    if(com(s2,s))
    {
      flag=1;
      break;
    }
  }
  if(flag)
    cout<<s2<<endl;
  else
    cout<<0<<endl;  
              
  
  
  
  
  //while(1);
}   