#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char s1[20],s2[100],s3[20];
int main()
{
 while(cin>>s1)
 {
  int l=strlen(s1);
  strcpy(s3,s1);
  int len=3*(l-2);
  int t=0;
  s2[0]='0';
  s2[1]='.';
  int j=2;
  while(t<len)
  { 
   int k=0;
   t++;
   for(int i=l-1;i>1;i--)                       
   {
    int g=(s1[i]-'0')*10+k;
    k=g/8;
    s1[i]=g%8+'0';
    
   }
   s2[j]=k+'0';
   j++;
  }
 
   cout<<s3<<" [8] = ";
  j--;
  while(s2[j]=='0')                             
   j--;
  for(int i=0;i<=j;i++)                           
   cout<<s2[i];
  cout<<" [10]"<<endl;
 }
  return 0;
}
