#include<iostream>
#include<string>
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
int main()
{
  string s;
  while(cin>>s)
  {
    s=f(s,"2");
    int len=s.length();
    int count=0;
    if(len==1)
    {
      count=(s[0]-'0')%4;
    }
    else
    {
      count=(s[len-1]-'0'+10*(s[len-2]-'0'))%4;
    }
    if(count==0)
      cout<<"\"Possible.\""<<endl;
    else
      cout<<"\"Not possible.\""<<endl;
  }
}      

    