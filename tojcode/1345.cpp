#include<iostream>
#include<string>
using namespace std;
string fib[1000]; 


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
int com(string s1,string s2)
{
  int len1=s1.length();
  int len2=s2.length();
  if(len1>len2)
    return 1;
  else if(len1<len2)
    return -1;
  else
  {int i;
    for( i=0;i<len1;i++)
    {
      if(s1[i]>s2[i])
        return 1;
      else if(s1[i]<s2[i])
        return -1;
    }
    if(i==len1)
      return 0;      
  } 
}     
    
int main()
{
  fib[1]="1";
  fib[2]="2";
  for(int i=3;;i++)
  {
    fib[i]=f(fib[i-1],fib[i-2]);
    if(fib[i].length()>102)
      {//cout<<i<<endl;
      break;}
  }
  string s1,s2;
  while(cin>>s1>>s2)
  {
    if(s1=="0"&&s2=="0")
      return 0;
      
    int count=0;
    for(int i=1;i<490;i++)
    {
      if(com(s1,fib[i])<=0&&com(s2,fib[i])>=0)
        count++;}
    cout<<count<<endl;
  }  
      
  
}      