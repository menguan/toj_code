#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
char s[10000];
char w[26];
int main()
{
  int t,count=1;
  cin>>t;
  getchar();
  while(t--)
  {
     
     gets(s);
     gets(w);
     cout<<count++;
     cout<<" ";
     for(int i=0;i<strlen(s);i++)
     {
       if(s[i]==' ')
         cout<<" ";
       else
         cout<<w[s[i]-'A'];
     }
     cout<<endl;
  }
}   