#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
using namespace std;
char a[100];
char b[100];
int as[150];
int bs[150];
int main()
{
  int n,count=1;
  cin>>n;
  getchar();
  while(n--)
  {
    gets(a);
    gets(b);
    memset(as,0,sizeof(as));
    memset(bs,0,sizeof(bs));
    int aa=strlen(a);
    int bb=strlen(b);
    if(aa)
    for(int i=0;i<aa;i++)
    {
      as[a[i]]++;
    }
    
    if(bb)
    for(int i=0;i<bb;i++)
    {
      bs[b[i]]++;
    } 
    int sum=0;   
    for(int i=97;i<123;i++)
    {
      sum+=abs(as[i]-bs[i]);
    }
    cout<<"Case #"<<count++<<":  "<<sum<<endl; 
  }
}       
   